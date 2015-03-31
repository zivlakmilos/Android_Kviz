package krajisnik.zivlak.kviz;

import java.net.*;
import java.io.*;

public class Network
{
    // Variables
    private static Socket client;
    private static DataInputStream is;
    private static DataOutputStream os;
    private static String serverIp;
    private static int serverPort = 5000;
    
    public static void open(String ip)
    {
        serverIp = "192.168.1." + ip;
        //serverPort = port;
        try
        {
            client = new Socket(serverIp, serverPort);
            is = new DataInputStream(client.getInputStream());
            os = new DataOutputStream(client.getOutputStream());
        } catch(IOException ioe){}
    }
    
    public static void sendString(String data)
    {
        try
        {
            os.writeUTF(data);
        } catch(IOException ioe){}
    }
    
    public static String readString()
    {
        String data = "";
        try
        {
            data = is.readUTF();
        } catch(IOException ioe){}
        return data;
    }
    
    public static void close()
    {
        try
        {
            os.close();
            client.close();
        } catch(IOException ioe){}
    }
}
