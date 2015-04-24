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
    
    /**
     * 
     * Konekcija na mySQL bzu podataka.
     * 
     * @param ip ip adresa baze
     * @param port port baze
     * @param database naziv baze
     * @param user username
     * @param pass password
     * @return 
     */
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
    
    /**
     * 
     * Diskonektuj se sa baze podataka.
    */
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
    
    /**
     * 
     * Dodaje klijenta u bazu podataka
     * 
     * @param c klijent
     */
    public static void addClient(Client c)
    {
        try
        {
            st.executeQuery("");
        } catch(SQLException err){}
    }
    
    /**
     * 
     * Uzima redni broj pitanja i vraca pitanje iz baze podataka.
     * 
     * @param rb redni broj pitanja
     * @return Question pitanje
     */
    public static Question getQuestion(int rb)
    {
        Question question = new Question();
        return question;
    }
}
