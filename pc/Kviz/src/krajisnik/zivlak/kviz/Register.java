package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;


public class Register implements Runnable
{
    // Network variables
    private static ServerSocket server;
    private static Socket client;
    
    // Global variables
    private boolean running;
    
    // Constructor
    public Register()
    {
    }
    
    public void setRunning(boolean running)
    {
        this.running = running;
    }
    
    // Main function of Server thread
    @Override
    public void run()
    {
        try
        {
            server = new ServerSocket(5000);
            while(running)
            {
                client = server.accept();
                Network.addClient(client);
            }
        } catch(IOException err){}
    }
}
