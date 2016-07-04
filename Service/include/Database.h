#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <QList>
#include <QSqlDatabase>

class QString;
class Kviz;
class BrziPrsti;
class KoZnaZna;
class Asocijacije;

class Database
{ 
public:
    Database(void);
    ~Database(void);
    
    bool open(void);
    
    QList<Kviz> preuzmiListuKvizova(void);
    Kviz snimiKviz(Kviz kviz);
    QList<BrziPrsti> preuzmiBrzePrste(int kvizId);
    BrziPrsti snimiBrzePrste(BrziPrsti brziPrsti, int kvizId = -1);
    void obrisiBrzePrste(int id);
    QList<KoZnaZna> preuzmiKoZnaZna(int kvizId);
    KoZnaZna snimiKoZnaZna(KoZnaZna koZnaZna, int kvizId = -1);
    void obrisiKoZnaZna(int id);
    QList<Asocijacije> preuzmiAsocijacije(int kvizId);
    Asocijacije snimiAsocijacije(Asocijacije asocijacije, int kvizId = -1);
    void obrisiAsocijacije(int id);
    
private:
    QSqlDatabase m_db;
        
};

#endif // _DATABASE_H_