#include <Database.h>

#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <data/kviz.h>

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

QList<Kviz> Database::preuzmiListuKvizova(void)
{
    QList<Kviz> result;
    QSqlQuery query(m_db);
    query.exec("SELECT id, naziv FROM nazivi_kvizova");
    
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString naziv = query.value(1).toString();
        result.append(Kviz(id, naziv));
    }
    
    return result;
}