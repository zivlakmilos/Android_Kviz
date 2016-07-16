package net.ddns.zivlakmilos.androidkviz.takmicar;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		Button btnPrijava = (Button)findViewById(R.id.btnPrijava);
		btnPrijava.setOnClickListener(new OnClickListener(){

			@Override
			public void onClick(View arg0) {
				
				Toast.makeText(getApplicationContext(),
							   "RADI!",
							   Toast.LENGTH_LONG).show();
			}
			
		});
	}
}
