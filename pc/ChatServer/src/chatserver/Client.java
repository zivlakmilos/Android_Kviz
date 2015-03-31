package chatserver;

import java.net.*;
import java.io.*;

/**
 *
 * @author zi
 */


public class Client extends Thread
{
    private Socket client;
    private DataInputStream is;
    private DataOutputStream os;
    
    public Client(Socket c)
    {
        this.client = c;
        try
        {
            if(client != null)
            {
                is = new DataInputStream(client.getInputStream());
                System.out.println(is.readUTF());
                os = new DataOutputStream(client.getOutputStream());
                os.writeUTF("OK");
            }
        } catch(IOException err){}
    }
    
    @Override
    public void run()
    {
        while(true)
        {
            try
            {
                System.out.println(is.readUTF());
            } catch(IOException err){}
        }
    }
}
