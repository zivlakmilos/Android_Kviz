#include <Database.h>

#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>

Database::Database(void)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("zivlakmilos.ddns.net");
    m_db.setDatabaseName("android_kviz");
    m_db.setUserName("androidkviz");
    m_db.setPassword("Android_Kviz.5001");
}

Database::~Database(void)
{
    if(m_db.isOpen())
        m_db.close();
}

bool Database::open(void)
{
    return m_db.open();
}

QList<QString> Database::preuzmiListuFilmova(void)
{
    QList<QString> result;
    QSqlQuery query;
    query.exec("SELECT naziv FROM nazivi_kvizova");
    
    while(query.next())
    {
        result.append(query.value(0).toString());
    }
    
    return result;
}