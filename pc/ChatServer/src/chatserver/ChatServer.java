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
        ServerSocket server;
        Socket client;
        DataInputStream is = null;
        DataOutputStream os = null;
        
        try
        {
            server = new ServerSocket(5000);
            client = server.accept();
            is = new DataInputStream(client.getInputStream());
            os = new DataOutputStream(client.getOutputStream());
        } catch(IOException err){}
        
        while(true)
        {
            try
            {
                System.out.println(is.readUTF());
                os.writeUTF("OK");
            } catch(IOException err){}
        }
    }
    
}
