package sk.breviar.android;

import android.app.Activity;
import android.os.Bundle;
import sk.breviar.android.Server;
import android.webkit.WebView;
import java.io.IOException;
import android.webkit.WebViewClient;
import android.webkit.WebSettings;
import android.content.Intent;
import android.net.Uri;
import android.widget.Button;
import android.view.View;
import android.view.Window;

public class Breviar extends Activity
{
    WebView wv;
    Server S = null;
    static String scriptname = "cgi-bin/l.cgi";

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
      super.onCreate(savedInstanceState);

      requestWindowFeature(Window.FEATURE_NO_TITLE);

      if (S==null) {
        try {
          S = new Server(this, scriptname);
        } catch (IOException e) {
          finish();
        }
        S.start();
      }
      setContentView(R.layout.breviar);

      wv = (WebView)findViewById(R.id.wv);
      if (wv.restoreState(savedInstanceState) == null)
        wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes");

      wv.getSettings().setBuiltInZoomControls(true);
      wv.getSettings().setDefaultZoom(WebSettings.ZoomDensity.FAR);

      wv.setWebViewClient(new WebViewClient() {
        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
          view.loadUrl(url);
          return true;
        }
      } );

      ((Button)findViewById(R.id.backBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.goBack();
        }
      });
 
      ((Button)findViewById(R.id.forwardBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.goForward();
        }
      });
 
      ((Button)findViewById(R.id.todayBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.loadUrl("http://localhost:" + S.port + "/" + scriptname + "?qt=pdnes");
        }
      });
 
      ((Button)findViewById(R.id.pgdnBtn)).setOnClickListener(new View.OnClickListener() {
        public void onClick(View v) {
          wv.pageDown(false);
        }
      });
 
    }

    protected void onSaveInstanceState(Bundle outState) {
      wv.saveState(outState);
    }

    @Override
    public void onDestroy() {
      if (S != null) S.stopServer();
      super.onDestroy();
    }
}
