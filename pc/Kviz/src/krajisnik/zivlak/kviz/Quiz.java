package krajisnik.zivlak.kviz;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class Quiz
{
    // Global variable
    private int id;
    private String name;
    private int numberOfQuestions;
    private List<Question> question = new ArrayList<Question>();
    private Random random;
    
    // Constructor
    /**
     * 
     * Kreiraj novi kviz, podesi id i broj pitanja.
     * 
     * @param id id kviza
     * @param numOfQuestions broj pitanja po krugu (broj takmicara)
     */
    public Quiz(int id, int numOfQuestions)
    {
        this.id = id;
        this.numberOfQuestions = numOfQuestions;
        random = new Random();
//        Database.setQuiz(id);
        for(int i = 0; i < this.numberOfQuestions; i++)
        {
//            int r = random.nextInt(Database.getNumberOfQuestionNow());
//            question.add(Database.getQuestion(r));
//            Database.setQuestion(r, true);
//            Database.updateQuestions();
        }
    }
}
