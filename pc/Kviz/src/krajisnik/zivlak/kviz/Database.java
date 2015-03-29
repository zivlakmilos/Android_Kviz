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
    String user = "";
    String password = "";
}
