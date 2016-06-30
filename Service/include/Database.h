#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <QList>
#include <QSqlDatabase>

class QString;
class Kviz;
class BrziPrsti;
class KoZnaZna;

class Database
{ 
public:
    Database(void);
    ~Database(void);
    
    bool open(void);
    
    QList<Kviz> preuzmiListuKvizova(void);
    QList<BrziPrsti> preuzmiBrzePrste(int kvizId);
    QList<KoZnaZna> preuzmiKoZnaZna(int kvizId);
    BrziPrsti snimiBrzePrste(BrziPrsti brziPrsti, int kvizId = -1);
    void obrisiBrzePrste(int id);
    KoZnaZna snimiKoZnaZna(KoZnaZna koZnaZna, int kvizId = -1);
    void obrisiKoZnaZna(int id);
    
private:
    QSqlDatabase m_db;
        
};

#endif // _DATABASE_H_