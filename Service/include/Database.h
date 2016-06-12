#ifndef _DATABASE_H_
#define _DATABASE_H_

class Database
{
    public:
        Database(void);
        ~Database(void);
        
        bool open(void);
        
    private:
        QSqlDatabase m_db;
        
};

#endif // _DATABASE_H_