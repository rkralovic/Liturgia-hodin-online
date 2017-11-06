package sk.breviar.android;

import java.lang.Runnable;

import android.os.Bundle;

public class PrayerDisplaySettings extends SettingsActivity {
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    inflateMenu(R.menu.device_settings);
    getSupportActionBar().setTitle(getString(R.string.settings_title));

    final SettingsActivity act = this;
  }
}

