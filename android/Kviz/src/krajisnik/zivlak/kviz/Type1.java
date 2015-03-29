package krajisnik.zivlak.kviz;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.View;
import android.view.View.*;


public class Type1 extends Activity
{
    // Visual compoenents
    private Button btnClose;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        setContentView(R.layout.type1);
        
        // Initialize visual compoenents
        btnClose = (Button) this.findViewById(R.id.btnClose);
        
        // Handler events
        // btnClose on click
        btnClose.setOnClickListener(new OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                finish();
            }
        });
    }
}