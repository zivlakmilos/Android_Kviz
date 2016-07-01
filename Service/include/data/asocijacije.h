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
    
private:
    int m_id;
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