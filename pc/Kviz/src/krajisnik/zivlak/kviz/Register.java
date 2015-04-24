package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;


public class Register extends Thread
{
    // Network variables
    private ServerSocket server;
    private Socket client;
    
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
