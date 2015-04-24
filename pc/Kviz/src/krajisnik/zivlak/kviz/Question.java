package krajisnik.zivlak.kviz;

/**
 *
 * @author zi
 */


public class Question
{
    // Constants
    public static final int TYPE1 = 1;
    public static final int TYPE2 = 2;
    public static final int TYPE3 = 3;
    
    // Global variables
    private int id;
    private int type;
    private int typeId;
    private boolean avalible;
    
    private String question;
    private String answer;
    private String a, b, c, d, e, f, g;
    private String a1, b1, v1, d1, e1, f1, g1;
    
    // Constructor
    public Question()
    {
    }
    
    /**
     *
     * Set Type of question.
     * Use symbolic constants for arguments.
     * @param type type of question (symbolic constants)
     */
    public void setType(int type)
    {
        this.type = type;
    }
    
    /**
     * 
     * Postavi "vaznost" pitanja.
     */
    public void setAvalible(boolean abalible)
    {
        this.avalible = avalible;
    }
}
