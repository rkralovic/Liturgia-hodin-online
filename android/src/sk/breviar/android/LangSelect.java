package sk.breviar.android;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.AlertDialog.Builder;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.CheckBox;

import sk.breviar.android.BreviarApp;
import sk.breviar.android.UrlOptions;

public class LangSelect extends Activity {
    static final int DIALOG_ABOUT = 1;
    static final int DIALOG_NEWS = 2;

    UrlOptions url_options;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
      url_options = new UrlOptions(BreviarApp.getUrlOptions(getApplicationContext()));

      super.onCreate(savedInstanceState);
      setContentView(R.layout.langselect);

      final LangSelect activity = this;

      ((Button)findViewById(R.id.lang_sk)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.setResult(RESULT_OK, new Intent().putExtra("lang", "sk"));
          activity.finish();
        }
      });

      ((Button)findViewById(R.id.lang_cz)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.setResult(RESULT_OK, new Intent().putExtra("lang", "cz"));
          activity.finish();
        }
      });

      ((Button)findViewById(R.id.lang_hu)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.setResult(RESULT_OK, new Intent().putExtra("lang", "hu"));
          activity.finish();
        }
      });

      CheckBox override_check = (CheckBox)findViewById(R.id.override_locale_check);

      override_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          BreviarApp.setOverrideLocale(getApplicationContext(), ((CheckBox)v).isChecked());
        }
      });

      override_check.setChecked(BreviarApp.getOverrideLocale(getApplicationContext()));

      // settings_title
      
      CheckBox vol_buttons_check = (CheckBox)findViewById(R.id.vol_buttons_check);

      vol_buttons_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          BreviarApp.setVolButtons(getApplicationContext(), ((CheckBox)v).isChecked());
        }
      });

      vol_buttons_check.setChecked(BreviarApp.getVolButtons(getApplicationContext()));

      CheckBox dimlock_check = (CheckBox)findViewById(R.id.dimlock_check);

      dimlock_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          BreviarApp.setDimLock(getApplicationContext(), ((CheckBox)v).isChecked());
        }
      });

      dimlock_check.setChecked(BreviarApp.getDimLock(getApplicationContext()));

      CheckBox mute_check = (CheckBox)findViewById(R.id.mute_check);

      mute_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          BreviarApp.setMute(getApplicationContext(), ((CheckBox)v).isChecked());
        }
      });

      mute_check.setChecked(BreviarApp.getMute(getApplicationContext()));

      // prayer_content_settings1_title
      
      CheckBox various_options_in_prayers_check = (CheckBox)findViewById(R.id.various_options_in_prayers_check);

      various_options_in_prayers_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setDisplayVariousOptions(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      various_options_in_prayers_check.setChecked(url_options.isDisplayVariousOptions());

      CheckBox alternatives_check = (CheckBox)findViewById(R.id.alternatives_check);

      alternatives_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setDisplayAlternatives(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      alternatives_check.setChecked(url_options.isDisplayAlternatives());

      // prayer_content_settings_title
      
      CheckBox display_communia_info_check = (CheckBox)findViewById(R.id.display_communia_info_check);

      display_communia_info_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setDisplayCommuniaInfo(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      display_communia_info_check.setChecked(url_options.isDisplayCommuniaInfo());

      CheckBox verse_numbering_check = (CheckBox)findViewById(R.id.verse_numbering_check);

      verse_numbering_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setVerseNumbering(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      verse_numbering_check.setChecked(url_options.isVerseNumbering());

      CheckBox bible_references_check = (CheckBox)findViewById(R.id.bible_references_check);

      bible_references_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setBibleReferences(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      bible_references_check.setChecked(url_options.isBibleReferences());

      CheckBox liturgical_readings_check = (CheckBox)findViewById(R.id.liturgical_readings_check);

      liturgical_readings_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setLiturgicalReadings(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      liturgical_readings_check.setChecked(url_options.isLiturgicalReadings());

      // display_settings_title

      CheckBox navigation_check = (CheckBox)findViewById(R.id.navigation_check);

      navigation_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setNavigation(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      navigation_check.setChecked(url_options.isNavigation());

      CheckBox wrapping_printed_check = (CheckBox)findViewById(R.id.wrapping_printed_check);

      wrapping_printed_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setTextWrap(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      wrapping_printed_check.setChecked(url_options.isTextWrap());

      CheckBox smart_buttons_check = (CheckBox)findViewById(R.id.smart_buttons_check);

      smart_buttons_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setSmartButtons(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      smart_buttons_check.setChecked(url_options.isSmartButtons());

      CheckBox night_mode_check = (CheckBox)findViewById(R.id.night_mode_check);

      night_mode_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setNightmode(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      night_mode_check.setChecked(url_options.isNightmode());

      CheckBox normal_font_check = (CheckBox)findViewById(R.id.normal_font_check);

      normal_font_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setOnlyNonBoldFont(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      normal_font_check.setChecked(url_options.isOnlyNonBoldFont());

      CheckBox buttons_order_check = (CheckBox)findViewById(R.id.buttons_order_check);

      buttons_order_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setButtonsOrder(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      buttons_order_check.setChecked(url_options.isButtonsOrder());

      // calendar_settings_title

      CheckBox epiphany_sunday_check = (CheckBox)findViewById(R.id.epiphany_sunday_check);

      epiphany_sunday_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setEpiphanySunday(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      epiphany_sunday_check.setChecked(url_options.isEpiphanySunday());

      CheckBox ascension_sunday_check = (CheckBox)findViewById(R.id.ascension_sunday_check);

      ascension_sunday_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setAscensionSunday(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      ascension_sunday_check.setChecked(url_options.isAscensionSunday());

      CheckBox body_blood_sunday_check = (CheckBox)findViewById(R.id.body_blood_sunday_check);

      body_blood_sunday_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setBodyBloodSunday(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      body_blood_sunday_check.setChecked(url_options.isBodyBloodSunday());

      CheckBox emphasize_local_calendar_check = (CheckBox)findViewById(R.id.emphasize_local_calendar_check);

      emphasize_local_calendar_check.setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          activity.url_options.setEmphasizeLocalCalendar(((CheckBox)v).isChecked());
          BreviarApp.setUrlOptions(getApplicationContext(), activity.url_options.build(true));
        }
      });

      emphasize_local_calendar_check.setChecked(url_options.isEmphasizeLocalCalendar());

      ((Button)findViewById(R.id.about)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          showDialog(DIALOG_ABOUT);
        }
      });

      ((Button)findViewById(R.id.btn_news)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          showDialog(DIALOG_NEWS);
        }
      });

      ((Button)findViewById(R.id.alarms)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          startActivity(new Intent("sk.breviar.android.ALARMS"));
        }
      });
    }

    @Override
    protected Dialog onCreateDialog(int id) {
      String content = null;
      switch(id) {
        case DIALOG_ABOUT:
          content = Util.getAboutText(this);
          break;
        case DIALOG_NEWS:
          content = getString(R.string.news);
          break;
        default:
          // fall through
      }
      return Util.createHtmlDialog(this, content);
    }
}
