package krajisnik.zivlak.kviz;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;


public class Database
{
    // Database variables
    private static Connection con = null;
    private static Statement st = null;
    private static ResultSet rs = null;
    
    // Global variables
    private static String url = "";
    private static String username = "";
    private static String password = "";
    
    // Connect on database server
    public static boolean connect(String ip, int port, String database,
            String user, String pass)
    {
        url = "jdbc:mysql://" + ip + ":" + String.valueOf(port) +
                "/" + database;
        username = user;
        password = pass;
        
        try
        {
            con = DriverManager.getConnection(url, username, password);
            st = con.createStatement();
        } catch(SQLException err)
        {
            return false;
        }
        
        return true;    // This maybe not good idea
    }
    
    // Disconnect from database server
    public static void disconnect()
    {
        try
        {
            if(rs != null)
                rs.close();
            if(st != null)
                st.close();
            if(con != null)
                con.close();
        } catch(SQLException err){}
    }
    
    // Add client to database
    public static void addClient(Client c)
    {
        try
        {
            st.executeQuery("");
        } catch(SQLException err){}
    }
    
    // Get question
    public static Question getQuestion(int rb)
    {
        Question question = new Question();
        return question;
    }
}
