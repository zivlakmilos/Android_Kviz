#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <QList>
#include <QSqlDatabase>

class QString;
class Kviz;
class BrziPrsti;

class Database
{ 
public:
    Database(void);
    ~Database(void);
    
    bool open(void);
    
    QList<Kviz> preuzmiListuKvizova(void);
    QList<BrziPrsti> preuzmiBrzePrste(int kvizId);
    BrziPrsti snimiBrzePrste(BrziPrsti brziPrsti, int kvizId = -1);
    void obrisiBrzePrste(int id);
    
private:
    QSqlDatabase m_db;
        
};

#endif // _DATABASE_H_