#include <Database.h>

#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>

#include <data/kviz.h>
#include <data/brziprsti.h>

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

QList<BrziPrsti> Database::preuzmiBrzePrste(int kvizId)
{
    QList<BrziPrsti> result;
    QSqlQuery query(m_db);
    
    query.prepare("SELECT bp.id, bp.pitanje, bp.a, bp.b, bp.c, bp.d, bp.odgovor "
                  "FROM brzi_prsti bp "
                  "LEFT JOIN kviz_pitanja p ON bp.id = p.pitanje_id "
                  "WHERE p.kviz_id = 1 AND p.tip = :tip;");
    query.bindValue(":kviz_id", kvizId);
    query.bindValue(":tip", Kviz::BrziPrsti);
    query.exec();
    
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString pitanje = query.value(1).toString();
        QString a = query.value(2).toString();
        QString b = query.value(3).toString();
        QString c = query.value(4).toString();
        QString d = query.value(5).toString();
        QChar odgovor = query.value(6).toString()[0];
        result.append(BrziPrsti(id, pitanje, a, b, c, d, odgovor));
    }
    
    return result;
}