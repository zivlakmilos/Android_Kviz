package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.List;


public class Network
{
    // Constants
    public static final int NOTHING = 0;        // Nothing (Default action)
    public static final int REGISTER = 1;       // Registar players
    public static final int COMPETITION = 2;    // Start competition
    public static final int RANG = 3;           // Rang list (end competition)
    
    // Network variables
    private static List<Client> client = new ArrayList<Client>();
    
    // Global variables
    private static int clientCount = 0;
    private static int action = NOTHING;
    
    
    // Add new client to sercer
    public static void addClient(Socket c)
    {
        client.add(new Client(c, clientCount));
        client.get(clientCount).start();
        // ToDo: update database (maybe)
        clientCount++;
    }
    
    // Send string to client
    public static void sendString(int id, String data)
    {
        client.get(id).sendString(data);
    }
    
    // Get action
    public static int getAction()
    {
        return action;
    }
    
    // Set action
    public static void setAction(int a)
    {
        action = a;
    }
    
    // Start/end registration
    public static void setRegister(boolean start)
    {
        Register register = new Register();
        if(start)
        {
            setAction(REGISTER);
            register.setRunning(true);
            register.start();
        } else
        {
            setAction(REGISTER);
            register.setRunning(false);
//            register.stop();
        }
    }
    
    // Start/end competition
    public static void setCompetition(boolean start)
    {
        if(start)
        {
            setAction(COMPETITION);
        } else
        {
            setAction(RANG);
        }
    }
}
