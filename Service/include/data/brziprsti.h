#ifndef _DATA_BRZI_PRSTI_H_
#define _DATA_BRZI_PRSTI_H_

class BrziPrsti
{
public:
    BrziPrsti(void) {};
    BrziPrsti(int id, QString pitanje, QString a, QString b, QString c, QString d, char odgobor)
        : m_id(id),
          m_pitanje(pitanje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_odgovor(odgobor) {};
    BrziPrsti(QString pitanje, QString a, QString b, QString c, QString d, char odgobor)
        : m_pitanje(pitanje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_odgovor(odgobor) {};
    virtual ~BrziPrsti(void) {};
    
    int getId(void) { return m_id; };
    
    QString getPitanje(void) { return m_pitanje; };
    void setPitanje(QString pitanje) { m_pitanje = pitanje; };
    
    QString getA(void) { return m_a; };
    void setA(QString a) { m_a = a; };
    
    QString getB(void) { return m_b; };
    void setB(QString b) { m_b = b; };
    
    QString getC(void) { return m_c; };
    void setC(QString c) { m_c = c; };
    
    QString getD(void) { return m_d; };
    void setD(QString d) { m_d = d; };
    
    char getOdgovor(void) { return m_odgovor; };
    void setOdgovor(char odgovor) { m_odgovor = odgovor; };
    
private:
    int m_id;
    QString m_pitanje;
    QString m_a;
    QString m_b;
    QString m_c;
    QString m_d;
    char m_odgovor;
};

#endif // _DATA_BRZI_PRSTI_H_