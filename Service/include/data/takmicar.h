#ifndef _DATA_TAKMICAR_H_
#define _DATA_TAKMICAR_H_

class Takmicar
{
public:
    Takmicar(void)
        : m_id(-1),
          m_ime(""),
          m_bodoviUkupno(0),
          m_bodoviBrziPrsti(0),
          m_bodoviKoZnaZna(0),
          m_bodoviAsocijacije(0) {};
    Takmicar(int id, QString ime)
        : m_id(id),
          m_ime(ime),
          m_bodoviUkupno(0),
          m_bodoviBrziPrsti(0),
          m_bodoviKoZnaZna(0),
          m_bodoviAsocijacije(0) {};
    virtual ~Takmicar(void) {};
    
    int getId(void) { return m_id; };
    void setId(int id) { m_id = id; };
    
    QString getIme(void) { return m_ime; };
    void setIme(QString ime) { m_ime = ime; };
    
    float getBodoviUkupno(void) { return m_bodoviUkupno; };
    
    float getBodoviBrziPrsti(void) { return m_bodoviBrziPrsti; };
    void addBodoviBrziPrsti(float bodoviBrziPrsti)
    {
        m_bodoviBrziPrsti += bodoviBrziPrsti;
        m_bodoviUkupno += bodoviBrziPrsti;
    };
    
    float getBodoviKoZnaZna(void) { return m_bodoviKoZnaZna; };
    void addBodoviKoZnaZna(float bodoviKoZnaZna)
    {
        m_bodoviKoZnaZna += bodoviKoZnaZna;
        m_bodoviUkupno += bodoviKoZnaZna;
    };
    
    float getBodoviAsocijacije(void) { return m_bodoviAsocijacije; };
    void addBodoviAsocijacije(float bodoviAsocijacije)
    {
        m_bodoviAsocijacije += bodoviAsocijacije;
        m_bodoviUkupno += bodoviAsocijacije;
    };
    
private:
    int m_id;
    QString m_ime;
    float m_bodoviUkupno;
    float m_bodoviBrziPrsti;
    float m_bodoviKoZnaZna;
    float m_bodoviAsocijacije;
};

#endif // _DATA_TAKMICAR_H_