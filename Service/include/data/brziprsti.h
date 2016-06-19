#ifndef _DATA_BRZI_PRSTI_H_
#define _DATA_BRZI_PRSTI_H_

class BrziPrsti
{
public:
    BrziPrsti(void) {};
    BrziPrsti(int id, QString pitanje, QString a, QString b, QString c, QString d, QChar odgovor)
        : m_id(id),
          m_pitanje(pitanje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_odgovor(odgovor) {};
    BrziPrsti(QString pitanje, QString a, QString b, QString c, QString d, QChar odgovor)
        : m_pitanje(pitanje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_odgovor(odgovor) {};
    virtual ~BrziPrsti(void) {};
    
    int getId(void) { return m_id; };
    
    QString getPitanje(void) const { return m_pitanje; };
    void setPitanje(QString pitanje) { m_pitanje = pitanje; };
    
    QString getA(void) const { return m_a; };
    void setA(QString a) { m_a = a; };
    
    QString getB(void) const { return m_b; };
    void setB(QString b) { m_b = b; };
    
    QString getC(void) const { return m_c; };
    void setC(QString c) { m_c = c; };
    
    QString getD(void) const { return m_d; };
    void setD(QString d) { m_d = d; };
    
    QChar getOdgovor(void) const { return m_odgovor; };
    void setOdgovor(char odgovor) { m_odgovor = odgovor; };
    
private:
    int m_id;
    QString m_pitanje;
    QString m_a;
    QString m_b;
    QString m_c;
    QString m_d;
    QChar m_odgovor;
};

#endif // _DATA_BRZI_PRSTI_H_