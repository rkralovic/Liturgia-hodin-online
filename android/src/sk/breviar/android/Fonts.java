package sk.breviar.android;

import android.graphics.fonts.Font;
import android.graphics.fonts.SystemFonts;
import android.graphics.fonts.FontStyle;
import android.util.Log;

import java.io.File;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.Vector;

public class Fonts {
  public static class FontMap {
    public static class Variants {
      public Variants() {
        variants = new Vector<Font>();
        display_font = null;
      }

      public void Add(Font variant) {
        variants.add(variant);
        display_font = null;
      }

      public Font GetDisplayFont() {
        if (display_font == null) { double best_score = 1e9;
          for (Font v : variants) {
            double wdiff = v.getStyle().getWeight() - 400.0;
            double sdiff = v.getStyle().getSlant();
            double score = wdiff * wdiff + sdiff * sdiff;
            if (score < best_score) {
              best_score = score;
              display_font = v;
            }
          }
        }
        return display_font;
      }

      Vector<Font> variants;
      Font display_font;
    }

    public TreeMap<String, Variants> families;

    private String cached_css = null;

    public FontMap() {
      families = new TreeMap<String, Variants>();
    }

    static String parseFamily(File file) {
      // Todo: Sanitize unexpected characters
      return file.getAbsolutePath().toString()
        .replaceAll("[^/]*/", "")
        .replaceFirst("\\.[^.]*$", "")
        .replaceFirst("-[^-]*$", "");
    }

    public void Insert(Font font) {
      if (!font.getLocaleList().isEmpty()) {
        // ignore non-latin fonts.
        return;
      }
      java.io.File file = font.getFile();
      if (file == null) {
        Log.v("breviar", "font without file: " + font.toString());
        return;
      }
      String family = parseFamily(file);
      if (!families.containsKey(family)) {
        families.put(family, new Variants());
      }

      families.get(family).Add(font);

      // Invalidate cache
      cached_css = null;
    }

    public String GetCss() {
      if (cached_css == null) {
        StringBuilder out = new StringBuilder();
        for (Map.Entry<String, Variants> e : families.entrySet()) {
          for (Font v : e.getValue().variants) {
            out.append("@font-face {\n");

            out.append("  font-family: \"");
            out.append(e.getKey());
            out.append("\";\n");
            out.append("  src: url(\"/file");
            // Todo: Escape unexpected characters
            out.append(v.getFile().getPath());
            out.append("\");\n");
            if (v.getStyle().getSlant() > 0) {
              out.append("  font-style: italic;\n");
            } else {
              out.append("  font-style: normal;\n");
            }
            out.append("  font-weight: ");
            out.append(v.getStyle().getWeight());
            out.append(";\n");

            out.append("}\n");
          }
        }
        cached_css = out.toString();
      }
      return cached_css;
    }

    public void DebugDump() {
      for (Map.Entry<String, Variants> e : families.entrySet()) {
        Log.v("breviar", "font family: " + e.getKey());
        for (Font v : e.getValue().variants) {
          Log.v("breviar", "  style: " + v.getStyle().toString() +
                " " + v.getFile().getPath());
        }
      }
    }
  }

  static FontMap system_fonts = null;

  synchronized static FontMap GetSystemFonts() {
    if (system_fonts == null) {
      InitializeSystemFonts();
    }
    return system_fonts;
  }

  synchronized static void InitializeSystemFonts() {
    system_fonts = new FontMap();
    for(Font font : SystemFonts.getAvailableFonts()) {
      system_fonts.Insert(font);
    }

    // Debug:
    system_fonts.DebugDump();
    Log.v("breviar", "font css: " + system_fonts.GetCss());
  }
}
