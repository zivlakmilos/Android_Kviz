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
    private static int quizId = 0;
    
    // Connect to database
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
    
    // Disconnect from database
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
    
    // Get question from databese and return it
    public static Question getQuestion(int rb)
    {
        Question question = new Question();
        return question;
    }
    
    // Set quiz id and check if exists
    public static int setQuiz(int id)
    {
        quizId = id;
        // Check if quiz exist
        // if not return -1 and set quizId to -1
        //quizId = -1;
        return 0;
    }
    
    // Update question avalibility
    public static void updateQuestions()
    {
        // Update questions
    }
    
    // Get number of avalible questions
    public static int getNumberOfQuestionNow()
    {
        // Filtriraj bazu i izbroj
        // Vrati vrednosti, ako nema pitanja vraca 0
        return 0;
    }
    
    // Set question avalibility
    public static void setQuestion(int id, boolean avalibility)
    {
        // Code
    }
}
