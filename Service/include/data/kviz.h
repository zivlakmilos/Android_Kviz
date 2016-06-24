#ifndef _DATA_KVIZ_H_
#define _DATA_KVIZ_H_

class Kviz
{
public:
    Kviz(void)
        : m_id(-1) {};
    Kviz(QString naziv)
        : m_id(-1),
          m_naziv(naziv) {};
    Kviz(int id, QString naziv)
        : m_id(id),
          m_naziv(naziv) {};
    ~Kviz(void) {};
    
    int getId(void) const { return m_id; };
    void setId(int id) { if(m_id < 0) m_id = id; };
    
    QString getNaziv(void) const { return m_naziv; };
    void setNaziv(QString naziv) { m_naziv = naziv; };
    
    enum { KoZnaZna = 1,
           BrziPrsti,
           Asocijacije };
    
private:
    int m_id;
    QString m_naziv;
};

#endif // _DATA_KVIZ_H_
