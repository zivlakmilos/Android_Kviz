#ifndef _DATA_ASOCIJACIJE_H_
#define _DATA_ASOCIJACIJE_H_

class Asocijacije
{
public:
    Asocijacije(void)
        : m_id(-1) {};
    Asocijacije(int id, QString konacnoResenje,
                QString a, QString b, QString c, QString d,
                QString a1, QString a2, QString a3, QString a4,
                QString b1, QString b2, QString b3, QString b4,
                QString c1, QString c2, QString c3, QString c4,
                QString d1, QString d2, QString d3, QString d4)
        : m_id(id),
          m_konacnoResenje(konacnoResenje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_a1(a1),
          m_a2(a2),
          m_a3(a3),
          m_a4(a4),
          m_b1(b1),
          m_b2(b2),
          m_b3(b3),
          m_b4(b4),
          m_c1(c1),
          m_c2(c2),
          m_c3(c3),
          m_c4(c4),
          m_d1(d1),
          m_d2(d2),
          m_d3(d3),
          m_d4(d4) {};
    Asocijacije(QString konacnoResenje,
                QString a, QString b, QString c, QString d,
                QString a1, QString a2, QString a3, QString a4,
                QString b1, QString b2, QString b3, QString b4,
                QString c1, QString c2, QString c3, QString c4,
                QString d1, QString d2, QString d3, QString d4)
        : m_id(-1),
          m_konacnoResenje(konacnoResenje),
          m_a(a),
          m_b(b),
          m_c(c),
          m_d(d),
          m_a1(a1),
          m_a2(a2),
          m_a3(a3),
          m_a4(a4),
          m_b1(b1),
          m_b2(b2),
          m_b3(b3),
          m_b4(b4),
          m_c1(c1),
          m_c2(c2),
          m_c3(c3),
          m_c4(c4),
          m_d1(d1),
          m_d2(d2),
          m_d3(d3),
          m_d4(d4) {};
    
    int getId(void) const { return m_id; };
    void setId(int id) { if(m_id < 0) m_id = id; };
    QString getKonacnoResenje(void) const { return m_konacnoResenje; };
    void setKonacnoResenje(QString konacnoResenje) { m_konacnoResenje = konacnoResenje; };
    QString getA(void) const { return m_a; };
    void setA(QString a) { m_a = a; };
    QString getB(void) const { return m_a; };
    void setB(QString b) { m_b = b; };
    QString getC(void) const { return m_a; };
    void setC(QString c) { m_c = c; };
    QString getD(void) const { return m_a; };
    void setD(QString d) { m_d = d; };
    QString getA1(void) const { return m_a1; };
    void setA1(QString a1) { m_a1 = a1; };
    QString getA2(void) const { return m_a2; };
    void setA2(QString a2) { m_a2 = a2; };
    QString getA3(void) const { return m_a3; };
    void setA3(QString a3) { m_a3 = a3; };
    QString getA4(void) const { return m_a4; };
    void setA4(QString a4) { m_a4 = a4; };
    QString getB1(void) const { return m_b1; };
    void setB1(QString b1) { m_b1 = b1; };
    QString getB2(void) const { return m_b2; };
    void setB2(QString b2) { m_b2 = b2; };
    QString getB3(void) const { return m_b3; };
    void setB3(QString b3) { m_b3 = b3; };
    QString getB4(void) const { return m_b4; };
    void setB4(QString b4) { m_b4 = b4; };
    void setC1(QString c1) { m_c1 = c1; };
    QString getC2(void) const { return m_c2; };
    void setC2(QString c2) { m_c2 = c2; };
    QString getC3(void) const { return m_c3; };
    void setC3(QString c3) { m_c3 = c3; };
    QString getC4(void) const { return m_c4; };
    void setC4(QString c4) { m_c4 = c4; };
    void setD1(QString d1) { m_d1 = d1; };
    QString getD2(void) const { return m_d2; };
    void setD2(QString d2) { m_d2 = d2; };
    QString getD3(void) const { return m_d3; };
    void setD3(QString d3) { m_d3 = d3; };
    QString getD4(void) const { return m_d4; };
    void setD4(QString d4) { m_d4 = d4; };
    
private:
    int m_id;
    QString m_konacnoResenje;
    QString m_a;
    QString m_b;
    QString m_c;
    QString m_d;
    QString m_a1;
    QString m_a2;
    QString m_a3;
    QString m_a4;
    QString m_b1;
    QString m_b2;
    QString m_b3;
    QString m_b4;
    QString m_c1;
    QString m_c2;
    QString m_c3;
    QString m_c4;
    QString m_d1;
    QString m_d2;
    QString m_d3;
    QString m_d4;
};

#endif // _DATA_ASOCIJACIJE_H_