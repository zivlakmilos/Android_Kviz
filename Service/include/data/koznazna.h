#ifndef _DATA_KO_ZNA_ZNA_H_
#define _DATA_KO_ZNA_ZNA_H_

class KoZnaZna
{
public:
    KoZnaZna(void)
        : m_id(-1) {};
    KoZnaZna(int id, QString pitanje, QString odgovor)
        : m_id(id),
          m_pitanje(pitanje),
          m_odgovor(odgovor) {};
    KoZnaZna(QString pitanje, QString odgovor)
        : m_id(-1),
          m_pitanje(pitanje),
          m_odgovor(odgovor) {};
    
    int getId(void) const { return m_id; };
    void setId(int id) { if(m_id < 0) m_id = id; };
    
    QString getPitanje(void) const { return m_pitanje; };
    void setPitanje(QString pitanje) { m_pitanje = pitanje; };
    
    QString getOdgovor(void) const { return m_odgovor; };
    void setOdgovor(QString odgovor) { m_odgovor = odgovor; };
    
private:
    int m_id;
    QString m_pitanje;
    QString m_odgovor;
};

#endif // _DATA_KO_ZNA_ZNA_H_