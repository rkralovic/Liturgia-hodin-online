package sk.breviar.android;

import android.app.Activity;
import android.app.AlarmManager;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Build;
import android.util.Log;
import android.webkit.WebView;
import android.widget.CheckBox;

import java.util.GregorianCalendar;

import sk.breviar.android.AlarmReceiver;
import sk.breviar.android.CompatibilityHelper8;

public class Util {
  static final String prefname = "BreviarPrefs";

  static class AlarmTime {
    AlarmTime(int minute_, int hour_, boolean enabled_) {
      minute = minute_;
      hour = hour_;
      enabled = enabled_;
    }
    int minute, hour;
    boolean enabled;
  };

  static class EventInfo {
    EventInfo(int id_, String tag_, String p_, int cap_, int notify_, int hr, int min) {
      id = id_;
      caption = cap_;
      notify_text = notify_;
      tag = tag_;
      p = p_;
      defaultTime = new AlarmTime(min, hr, false);
    };

    AlarmTime getTime(Context ctx) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      int min = settings.getInt(tag + "-min", defaultTime.minute);
      int hr = settings.getInt(tag + "-hr", defaultTime.hour);
      boolean e = settings.getBoolean(tag + "-e", defaultTime.enabled);
      return new AlarmTime(min, hr, e);
    }

    void setTime(Context ctx, int hour, int minute) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putInt(tag + "-min", minute);
      editor.putInt(tag + "-hr", hour);
      editor.putBoolean(tag + "-e", true);
      editor.commit();
      setAlarm(ctx);
    }

    void disable(Context ctx) {
      SharedPreferences settings = ctx.getSharedPreferences(prefname, 0);
      SharedPreferences.Editor editor = settings.edit();
      editor.putBoolean(tag + "-e", false);
      editor.commit();
      setAlarm(ctx);
    }

    void updateBox(CheckBox box, AlarmTime t) {
      String s = box.getContext().getString(caption);
      if (t.enabled) {
        s += String.format(": %d:%02d", t.hour, t.minute);
      } else {
        s += ": " + box.getContext().getString(R.string.alarmOff);
      }
      box.setText(s);
      box.setChecked(t.enabled);
    }

    long nextTrigger(Context ctx) {
      AlarmTime t = getTime(ctx);
      if (!t.enabled) return Long.MAX_VALUE;

      GregorianCalendar act = new GregorianCalendar();

      // make sure we calculate time in future
      act.add(GregorianCalendar.SECOND, 10);

      GregorianCalendar out = (GregorianCalendar)act.clone();
      out.set(GregorianCalendar.SECOND, 0);
      out.set(GregorianCalendar.MINUTE, t.minute);
      out.set(GregorianCalendar.HOUR_OF_DAY, t.hour);
      if (out.before(act)) {
        out.add(GregorianCalendar.DAY_OF_MONTH, 1);
      }
      return out.getTimeInMillis();
    }

    int id, caption, notify_text;
    String tag, p;
    AlarmTime defaultTime;
  };

  static void setAlarm(Context ctx) {
    long next = Long.MAX_VALUE;
    int id = -1;
    for (int i = 0; i < events.length; ++i) {
      long t = events[i].nextTrigger(ctx);
      if (t < next) {
        next = t;
        id = i;
      }
    }
    
    Intent intent = new Intent(ctx, AlarmReceiver.class);
    intent.setAction("sk.breviar.android.NOTIFY");
    intent.putExtra("id", id);

    PendingIntent pi = PendingIntent.getBroadcast(ctx, 0, intent, PendingIntent.FLAG_UPDATE_CURRENT);
    AlarmManager am = (AlarmManager)ctx.getSystemService(Context.ALARM_SERVICE);
    if (next == Long.MAX_VALUE) {
      am.cancel(pi);
    } else {
      Log.v("breviar", "Current time " + java.lang.System.currentTimeMillis());
      Log.v("breviar", "Setting notification to " + next + ", id = " + id);
      am.set(AlarmManager.RTC_WAKEUP, next, pi);
    }
  }

  // FIXME: this needs to be consistent with liturgia.h. Automatically export that?
  static final EventInfo events[] = {
    new EventInfo(R.id.inv_check,   "alarm-inv",   "mi",    R.string.inv,   R.string.inv_notify,    8, 00),
    new EventInfo(R.id.read_check,  "alarm-read",  "mpc",   R.string.read,  R.string.read_notify,  11, 00),
    new EventInfo(R.id.rch_check,   "alarm-rch",   "mrch",  R.string.rch,   R.string.rch_notify,   10, 00),
    new EventInfo(R.id.h9_check,    "alarm-9h",    "mpred", R.string.h9,    R.string.h9_notify,     9, 00),
    new EventInfo(R.id.h12_check,   "alarm-12h",   "mna",   R.string.h12,   R.string.h12_notify,   12, 00),
    new EventInfo(R.id.h15_check,   "alarm-15h",   "mpo",   R.string.h15,   R.string.h15_notify,   15, 00),
    new EventInfo(R.id.vesp_check,  "alarm-vesp",  "mv",    R.string.vesp,  R.string.vesp_notify,  18, 00),
    new EventInfo(R.id.kompl_check, "alarm-kompl", "mk",    R.string.kompl, R.string.kompl_notify, 22, 00)
  };

  static public Dialog createHtmlDialog(Activity act, String content) {
    if (content == null) return null;
    WebView wv = new WebView(act);
    if (Build.VERSION.SDK_INT < 8) {
      wv.loadData(content, "text/html; charset=utf-8", "utf-8");
    } else {
      
      try {
        wv.loadData(CompatibilityHelper8.Base64EncodeToString(
                        content.getBytes("UTF-8")),
                    "text/html; charset=utf-8", "base64");
      } catch (java.io.UnsupportedEncodingException e) {
        wv.loadData("unsupported encoding utf-8", "text/html", null);
      }
    }
    return new AlertDialog.Builder(act)
           .setView(wv)
           .setCancelable(false)
           .setNeutralButton("OK", new DialogInterface.OnClickListener() {
               public void onClick(DialogInterface dialog, int id) {
                    dialog.cancel();
               }
           })
           .create();
  }

  static public String streamToString(java.io.InputStream stream) {
    StringBuilder output = new StringBuilder();
    java.io.InputStreamReader reader = new java.io.InputStreamReader(stream);
    char[] buf = new char[4096];
    int len;
    try {
      while ((len = reader.read(buf, 0, 4096)) != -1) {
        output.append(buf, 0, len);
      }
    } catch (java.io.IOException e) {
      Log.v("breviar", "Can not read file: " + e.getMessage());
    }
    return output.toString();
  }

  static public String getAboutText(Context ctx) {
    try {
      String output =
          ctx.getString(R.string.about_text_head) +
          streamToString(ctx.getAssets().open(ctx.getString(R.string.about_text))) +
          ctx.getString(R.string.about_text_tail);

      return output
          .replaceAll("<!--\\{VERSION\\}-->", ctx.getString(R.string.version))
          .replaceAll("<!--\\{PROJECT_URL\\}-->", ctx.getString(R.string.about_PROJECT_URL))
          .replaceAll("<!--\\{E_MAIL\\}-->", ctx.getString(R.string.about_E_MAIL))
          .replaceAll("<!--\\{APP_NAME\\}-->", ctx.getString(R.string.about_APP_NAME))
          .replaceAll("<!--\\{SPECIAL_CREDITS\\}-->", ctx.getString(R.string.about_SPECIAL_CREDITS))
          .replaceAll("<!--\\{PROJECT_SOURCE_STORAGE\\}-->", ctx.getString(R.string.about_PROJECT_SOURCE_STORAGE))
          .replaceAll("<!--\\{PROJECT_SOURCE_URL\\}-->", ctx.getString(R.string.about_PROJECT_SOURCE_URL))
          .replaceAll("<!--\\{PLATFORM_ANDROID\\}-->", ctx.getString(R.string.about_PLATFORM_ANDROID))
          .replaceAll("<!--\\{PLATFORM_IOS\\}-->", ctx.getString(R.string.about_PLATFORM_IOS));
    } catch (java.io.IOException e) {
      Log.v("breviar", "Can not open file: " + e.getMessage());

      return "";
    }
  }
}
