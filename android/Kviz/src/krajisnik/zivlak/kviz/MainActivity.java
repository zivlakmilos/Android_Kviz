package krajisnik.zivlak.kviz;

import android.app.Activity;
import android.os.Bundle;
import android.widget.*;
import android.view.*;
import android.view.View.*;
//import android.os.Handler;
import android.content.Intent;


public class MainActivity extends Activity
{
    // Visual components
    private TextView lblIp;
    private EditText txtIp;
    private TextView lblName;
    private EditText txtName;
    private Button btnRegister;
    private Button btnExit;
    
    // Global private variables
    private NetworkListener networkListener;
    
    // Handler for handle thread messages
//    public Handler handler;
    
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        lblIp = (TextView) this.findViewById(R.id.lblIp);
        txtIp = (EditText) this.findViewById(R.id.txtIp);
        lblName = (TextView) this.findViewById(R.id.lblName);
        txtName = (EditText) this.findViewById(R.id.txtName);
        btnRegister = (Button) this.findViewById(R.id.btnRegister);
        btnExit = (Button) this.findViewById(R.id.btnExit);
        
        networkListener = new NetworkListener(this);
        
//        handler = new Handler();
        
        btnRegister.setOnClickListener(new OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                Network.open(txtIp.getText().toString());
                networkListener.start();
                Network.sendString(txtName.getText().toString());
                
//                lblIp.setVisibility(View.INVISIBLE);
//                txtIp.setVisibility(View.INVISIBLE);
//                lblName.setVisibility(View.INVISIBLE);
//                txtName.setVisibility(View.INVISIBLE);
//                btnRegister.setVisibility(View.INVISIBLE);
//                lblIp.setVisibility(View.GONE);
//                txtIp.setVisibility(View.GONE);
//                lblName.setVisibility(View.GONE);
//                txtName.setVisibility(View.GONE);
//                btnRegister.setVisibility(View.GONE);
            }
        });
        
        btnExit.setOnClickListener(new OnClickListener()
        {
            @Override
            public void onClick(View view)
            {
                networkListener.setRun(false);
                Network.close();
                System.exit(0);
            }
        });
    }
    
//    public void updateIp(final String data)
//    {
//        this.runOnUiThread(new Runnable()
//        {
//            @Override
//            public void run()
//            {
//                lblIp.setText(data);
//            }
//        });
//    }
    
    // Start type1 form
    public void startType1()
    {
        this.runOnUiThread(new Runnable()
        {
            @Override
            public void run()
            {
                Intent type1 = new Intent(MainActivity.this, Type1.class);
                startActivity(type1);
            }
        });
    }
}
