package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;
import java.util.List;

/**
 *
 * @author zi
 */


public class Network
{
    // Constants
    public static final int REGISTER = 0;
    
    // Network variables
    private static List<Client> client;
    
    // Global variables
    private static int clientCount = 0;
    private static int action = REGISTER;
    
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
}
