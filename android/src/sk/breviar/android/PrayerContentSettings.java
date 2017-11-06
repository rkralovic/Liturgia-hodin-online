package sk.breviar.android;

import java.lang.Runnable;

import android.os.Bundle;

public class PrayerContentSettings extends SettingsActivity {
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    inflateMenu(R.menu.device_settings);
    getSupportActionBar().setTitle(getString(R.string.settings_title));

    final SettingsActivity act = this;
    handleSwitch(R.id.vol_buttons, new BooleanOption() {
      public void set(boolean value) { BreviarApp.setVolButtons(act, value); }
      public boolean get() { return BreviarApp.getVolButtons(act); }
    });
  }
}

