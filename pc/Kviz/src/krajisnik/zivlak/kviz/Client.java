package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;


public class Client extends Thread
{
    // Network variables
    private Socket client;
    private DataInputStream is;
    private DataOutputStream os;
    
    // Global variables
    private int id = 0;
    private String name = "";
    
    // Constructor
    public Client(Socket client, int id)
    {
        this.client = client;
        try
        {
            is = new DataInputStream(client.getInputStream());
            os = new DataOutputStream(client.getOutputStream());
        } catch(IOException err){}
        this.id = id;
        name = this.readString();
    }
    
    // Send string to client
    public void sendString(String data)
    {
        try
        {
            os.writeUTF(data);
        } catch(IOException err){}
    }
    
    // Read string from client
    private String readString()
    {
        String data = "";
        try
        {
            data = is.readUTF();
        } catch(IOException err){}
        return data;
    }
    
    // Main function of Client thread
    @Override
    public void run()
    {
        String data = "";
        while(true)
        {
            data = readString();
            switch(Network.getAction())
            {
                case Network.REGISTER:
                    if(name == "")
                    {
                        name = data;
                        // ToDo: update database
                    }
                    break;
            }
        }
    }
}
