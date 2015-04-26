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
     * Postavi tip pitanja.
     * @param type tip pitanja (simbolicka konstanta)
     */
    public void setType(int type)
    {
        this.type = type;
    }
    
    /**
     * 
     * Postavi "vaznost" pitanja,
     * da li je pitanje proslo ili nije
     * @param avalible "vaznost", false(proslo)/ture(nije proslo)
     */
    public void setAvalible(boolean avalivle)
    {
        this.avalible = avalible;
    }
}
