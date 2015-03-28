package krajisnik.zivlak.kviz;

import android.content.Intent;


public class NetworkListener implements Runnable
{
    // Constants
    private final int MAIN = 0;
    private final int TYPE1 = 1;
    
    // Activity variables
    private MainActivity mainActivity;
//    private Type1 type1;
//    private Intent type1Intent;
    
    // Global variables
    private String data = "";
    private Boolean run = true;
    private int activeForm = MAIN;
    
    // Constructor
    public NetworkListener(MainActivity a)
    {
        mainActivity = a;
    }
    
    // Main function of NetworkListener
    @Override
    public void run()
    {
        while(run)
        {
            // Read data from server
            data = Network.readString();
            
            // Which form is activate
            switch(activeForm)
            {
                case MAIN:
                    // Code if MAIN form is activate
                    mainForm(data);
                break;
                case TYPE1:
                    // Code if TYPE1 form is activate
                    type1(data);
                break;
            }
            
//            mainActivity.updateIp(data);
            mainActivity.startType1();
            
            // Recive code for quit
            if(data.equalsIgnoreCase("quit"))
                run = false;
        }
    }
    
    // Code if MAIN form is activate
    private void mainForm(String data)
    {
    }
    
    // Code if TYPE1 form is activate
    private void type1(String data)
    {
    }
}
