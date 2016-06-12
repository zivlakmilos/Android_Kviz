#include <QSqlDatabase>

#include <Database.h>

Database::Database(void)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL", "android_kviz");
    m_db.setHostName("zivlakmilos.ddns.net");
    m_db.setDatabaseName("android_kviz");
    m_db.setUserName("androidkviz");
    m_db.setPassword("Android_Kviz.5001");
}

Database::~Database(void)
{
    if(m_db.isOpen())
        m_db.close();
    QSqlDatabase::removeDatabase("android_kviz");
}

bool Database::open(void)
{
    return m_db.open();
}
