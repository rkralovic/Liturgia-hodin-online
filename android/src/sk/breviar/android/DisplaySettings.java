package sk.breviar.android;

import java.lang.Runnable;
import java.util.Map;

import android.content.Context;
import android.graphics.Typeface; import android.os.Bundle;
import android.support.v4.view.MenuItemCompat;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.TextView;

import sk.breviar.android.Fonts;

public class DisplaySettings extends SettingsActivity {
  @Override
  public void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    inflateMenu(R.menu.display_settings);
    getSupportActionBar().setTitle(getString(R.string.display_settings_title));

    final SettingsActivity act = this;
    handleSwitch(R.id.first_vespers_buttons, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setFirstVespersButtons(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isFirstVespersButtons(); }
    });
    handleSwitch(R.id.navigation, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setNavigation(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isNavigation(); }
    });
    handleSwitch(R.id.smart_buttons, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setSmartButtons(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isSmartButtons(); }
    });
    handleSwitch(R.id.night_mode, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setNightmode(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isNightmode(); }
    });
    handleSwitch(R.id.background_override, new BooleanOption() {
      public void set(boolean value) { BreviarApp.setBackgroundOverride(act, value); }
      public boolean get() { return BreviarApp.getBackgroundOverride(act); }
    });
    handleSwitch(R.id.normal_font, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setOnlyNonBoldFont(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isOnlyNonBoldFont(); }
    });
    handleSwitch(R.id.buttons_rounded_corners, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setRoundedCorners(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isRoundedCorners(); }
    });
    handleSwitch(R.id.buttons_order, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setButtonsOrder(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isButtonsOrder(); }
    });
    handleSwitch(R.id.transparent_nav, new BooleanUrlOption() {
      public void setOpt(UrlOptions opts, boolean value) { opts.setTransparentNav(value); }
      public boolean getOpt(UrlOptions opts) { return opts.isTransparentNav(); }
    });

    // Font select
    {
      try {
        Spinner spinner = ((Spinner)MenuItemCompat.getActionView(
            navigationView.getMenu().findItem(R.id.font_select)));
        FontSelectAdapter adapter = new FontSelectAdapter(this);
        spinner.setAdapter(adapter);
        spinner.setOnItemSelectedListener(adapter);
      } catch (java.lang.NullPointerException e) {
        Log.v("breviar", "Cannot setup navigation view!");
      }
    }
  }

  static class FontInfo {
    public FontInfo(String name_, Typeface typeface_) {
      name = name_;
      typeface = typeface_;
    }

    String name;
    Typeface typeface;

    public String toString() {
      return name;
    }
  }

  static class FontSelectAdapter extends ArrayAdapter<FontInfo> implements AdapterView.OnItemSelectedListener {
    public FontSelectAdapter(Context ctx) {
      super(ctx, android.R.layout.simple_spinner_item);
      setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
      add(new FontInfo("<predvolený>", null));

      for (Map.Entry<String, Fonts.FontMap.Variants> e : Fonts.GetSystemFonts().families.entrySet()) {
        Typeface t = Typeface.createFromFile(e.getValue().GetDisplayFont().getFile());
        add(new FontInfo(e.getKey(), t));
      }

      // todo: set current selection
    }

    void SetupView(int position, View view) {
      if (view == null) return;
      if (!(view instanceof TextView)) return;

      FontInfo fi = getItem(position);
      if (fi == null) return;

      if (fi.typeface == null) return;

      ((TextView)view).setTypeface(fi.typeface);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
      View res = super.getView(position, convertView, parent);
      SetupView(position, res);
      return res;
    }

    @Override
    public View getDropDownView(int position, View convertView, ViewGroup parent) {
      View res = super.getDropDownView(position, convertView, parent);
      SetupView(position, res);
      return res;
    }

    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
      FontInfo fi = getItem(position);
      if (fi == null) return;

      UrlOptions opts = new UrlOptions(BreviarApp.getUrlOptions(getContext().getApplicationContext()));
      if (fi.typeface == null || fi.name == null) {
        Log.v("breviar", "Removing font selection");
        opts.setFont("");
      } else {
        Log.v("breviar", "Setting font to " + fi.name);
        opts.setFont(fi.name);
      }
      BreviarApp.setUrlOptions(getContext().getApplicationContext(), opts.build(true));
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {
    }

  }

  // TODO: Override updateMenu to refresh font selection adapter if there is
  // any other place that changes fonts.
}

