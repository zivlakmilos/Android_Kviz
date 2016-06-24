#include <Database.h>

#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

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
                  "WHERE p.kviz_id = 1 AND p.tip = :tip");
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

BrziPrsti Database::snimiBrzePrste(BrziPrsti brziPrsti, int kvizId)
{
    QSqlQuery query(m_db);
    
    if(brziPrsti.getId() < 0)
    {
        m_db.transaction();
        query.prepare("INSERT INTO brzi_prsti (pitanje, a, b, c, d, odgovor) "
                      "VALUES (:pitanje, :a, :b, :c, :d, :odgovor)");
        query.bindValue(":pitanje", brziPrsti.getPitanje());
        query.bindValue(":a", brziPrsti.getA());
        query.bindValue(":b", brziPrsti.getB());
        query.bindValue(":c", brziPrsti.getC());
        query.bindValue(":d", brziPrsti.getD());
        query.bindValue(":odgovor", brziPrsti.getOdgovor());
        query.exec();
        
        brziPrsti.setId(query.lastInsertId().toInt());
        
        query.prepare("INSERT INTO kviz_pitanja (tip, kviz_id, pitanje_id) "
                      "VALUES (:tip, :kviz_id, LAST_INSERT_ID())");
        query.bindValue(":tip", Kviz::BrziPrsti);
        query.bindValue(":kvi_id", kvizId);
        query.exec();
        m_db.commit();
    } else
    {
        query.prepare("UPDATE brzi_prsti SET "
                      "pitanje=:pitanje, "
                      "a=:a, b=:b, c=:c, d=:d, "
                      "odgovor=:odgovor "
                      "WHERE id=:id");
        query.bindValue(":id", brziPrsti.getId());
        query.bindValue(":pitanje", brziPrsti.getPitanje());
        query.bindValue(":a", brziPrsti.getA());
        query.bindValue(":b", brziPrsti.getB());
        query.bindValue(":c", brziPrsti.getC());
        query.bindValue(":d", brziPrsti.getD());
        query.bindValue(":odgovor", brziPrsti.getOdgovor());
        query.exec();
    }
    
    return brziPrsti;
}