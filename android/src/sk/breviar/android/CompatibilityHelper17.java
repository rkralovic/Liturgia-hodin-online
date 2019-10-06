package sk.breviar.android;

import android.app.Activity;
import android.content.Context;
import android.content.res.Configuration;

import java.util.Locale;

public class CompatibilityHelper17 {
  public void applyLocale(Activity activity, Locale locale) {
    Configuration cfg = new Configuration();
    cfg.setLocale(locale);
    activity.applyOverrideConfiguration(cfg);
  }

  public Context getContextForLocale(Context context, Locale locale) {
    Configuration cfg = new Configuration();
    cfg.setLocale(locale);
    return context.createConfigurationContext(cfg);
  }
}

