package chatserver;

/**
 *
 * @author zi
 */

import java.net.*;
import java.io.*;


public class ChatServer
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args)
    {
        ServerSocket server = null;
        Socket client;
        DataInputStream is = null;
        DataOutputStream os = null;
        
        try
        {
            server = new ServerSocket(5000);
        } catch(IOException err){}
        
        int countClient = 0;
        
        while(countClient < 2)
        {
            try
            {
                if(server != null)
                {
                    client = server.accept();
                    new Client(client).start();
                    countClient++;
                }
            } catch(IOException err){}
        }
    }
    
}
