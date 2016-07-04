#include <Database.h>

#include <QtCore>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <data/kviz.h>
#include <data/brziprsti.h>
#include <data/koznazna.h>
#include <data/asocijacije.h>

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
                  "WHERE p.kviz_id = :kviz_id AND p.tip = :tip");
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

void Database::obrisiBrzePrste(int id)
{
    QSqlQuery query(m_db);
    
    m_db.transaction();
    query.prepare("DELETE FROM brzi_prsti WHERE id=:id");
    query.bindValue(":id", id);
    query.exec();
    
    query.prepare("DELETE FROM kviz_pitanja "
                  "WHERE pitanje_id=:id AND tip=:tip");
    query.bindValue(":id", id);
    query.bindValue(":tip", Kviz::BrziPrsti);
    query.exec();
    m_db.commit();
}

KoZnaZna Database::snimiKoZnaZna(KoZnaZna koZnaZna, int kvizId)
{
    QSqlQuery query(m_db);
    
    if(koZnaZna.getId() < 0)
    {
        query.prepare("INSERT INTO ko_zna_zna (pitanje, odgovor) "
                      "VALUES (:pitanje, :odgovor)");
        query.bindValue(":pitanje", koZnaZna.getPitanje());
        query.bindValue(":odgovor", koZnaZna.getOdgovor());
        query.exec();
        
        koZnaZna.setId(query.lastInsertId().toInt());
        
        query.prepare("INSERT INTO kviz_pitanja (tip, kviz_id, pitanje_id) "
                      "VALUES (:tip, :kviz_id, LAST_INSERT_ID())");
        query.bindValue(":tip", Kviz::KoZnaZna);
        query.bindValue(":kvi_id", kvizId);
        query.exec();
    } else
    {
        query.prepare("UPDATE brzi_prsti SET "
                      "pitanje=:pitanje, "
                      "odgovor=:odgovor "
                      "WHERE id=:id");
        query.bindValue(":id", koZnaZna.getId());
        query.bindValue(":odgovor", koZnaZna.getOdgovor());
        query.exec();
    }
    
    return koZnaZna;
}

void Database::obrisiKoZnaZna(int id)
{
    QSqlQuery query(m_db);
    
    m_db.transaction();
    query.prepare("DELETE FROM ko_zna_zna WHERE id=:id");
    query.bindValue(":id", id);
    query.exec();
    
    query.prepare("DELETE FROM kviz_pitanja "
                  "WHERE pitanje_id=:id AND tip=:tip");
    query.bindValue(":id", id);
    query.bindValue(":tip", Kviz::BrziPrsti);
    query.exec();
    m_db.commit();
}

QList<KoZnaZna> Database::preuzmiKoZnaZna(int kvizId)
{
    QList<KoZnaZna> result;
    QSqlQuery query(m_db);
    
    query.prepare("SELECT kzz.id, kzz.pitanje, kzz.odgovor "
                  "FROM ko_zna_zna kzz "
                  "LEFT JOIN kviz_pitanja p ON kzz.id = p.pitanje_id "
                  "WHERE p.kviz_id = :kviz_id AND p.tip = :tip");
    query.bindValue(":kviz_id", kvizId);
    query.bindValue(":tip", Kviz::KoZnaZna);
    query.exec();
    
    while(query.next())
    {
        int id = query.value(0).toInt();
        QString pitanje = query.value(1).toString();
        QString odgovor = query.value(2).toString();
        result.append(KoZnaZna(id, pitanje, odgovor));
    }
    
    return result;
}

QList<Asocijacije> Database::preuzmiAsocijacije(int kvizId)
{
    QList<Asocijacije> result;
    QSqlQuery query(m_db);
    
    query.prepare("SELECT a.id, a.konacno, a.a, a.b, a.c, a.d, "
                  "a.a1, a.a2, a.a3, a.a4, "
                  "a.b1, a.b2, a.b3, a.b4, "
                  "a.c1, a.c2, a.c3, a.c3, "
                  "a.d1, a.d2, a.d3, a.d4 "
                  "FROM asocijacije a "
                  "LEFT JOIN kviz_pitanja p ON a.id = p.pitanje_id "
                  "WHERE p.kviz_id = :kviz_id AND p.tip = :tip");
    query.bindValue(":kviz_id", kvizId);
    query.bindValue(":tip", Kviz::Asocijacije);
    query.exec();
    
    while(query.next())
    {
        Asocijacije asocijacije;
        asocijacije.setId(query.value(0).toInt());
        asocijacije.setKonacnoResenje(query.value(1).toString());
        asocijacije.setA(query.value(2).toString());
        asocijacije.setB(query.value(3).toString());
        asocijacije.setC(query.value(4).toString());
        asocijacije.setD(query.value(5).toString());
        asocijacije.setA1(query.value(6).toString());
        asocijacije.setA2(query.value(7).toString());
        asocijacije.setA3(query.value(8).toString());
        asocijacije.setA4(query.value(9).toString());
        asocijacije.setB1(query.value(10).toString());
        asocijacije.setB2(query.value(11).toString());
        asocijacije.setB3(query.value(12).toString());
        asocijacije.setB4(query.value(13).toString());
        asocijacije.setC1(query.value(14).toString());
        asocijacije.setC2(query.value(15).toString());
        asocijacije.setC3(query.value(16).toString());
        asocijacije.setC4(query.value(17).toString());
        asocijacije.setD1(query.value(18).toString());
        asocijacije.setD2(query.value(19).toString());
        asocijacije.setD3(query.value(20).toString());
        asocijacije.setD4(query.value(21).toString());
        result.append(asocijacije);
    }
    
    return result;
}

Asocijacije Database::snimiAsocijacije(Asocijacije asocijacije, int kvizId)
{
    QSqlQuery query(m_db);
    
    if(asocijacije.getId() < 0)
    {
        query.prepare("INSERT INTO asocijacije (konacno, a, b, c, d, "
                      "a1, a2, a3, a4, "
                      "b1, b2, b3, b4, "
                      "c1, c2, c3, c4, "
                      "d1, d2, d3, d4) "
                      "VALUES (:konacno, :a, :b, :c, :d, "
                      ":a1, :a2, :a3, :a4, "
                      ":b1, :b2, :b3, :b4, "
                      ":c1, :c2, :c3, :c4, "
                      ":d1, :d2, :d3, :d4)");
        query.bindValue(":konacno", asocijacije.getKonacnoResenje());
        query.bindValue(":a", asocijacije.getA());
        query.bindValue(":b", asocijacije.getB());
        query.bindValue(":c", asocijacije.getC());
        query.bindValue(":d", asocijacije.getD());
        query.bindValue(":a1", asocijacije.getA1());
        query.bindValue(":a2", asocijacije.getA2());
        query.bindValue(":a3", asocijacije.getA3());
        query.bindValue(":a4", asocijacije.getA4());
        query.bindValue(":b1", asocijacije.getB1());
        query.bindValue(":b2", asocijacije.getB2());
        query.bindValue(":b3", asocijacije.getB3());
        query.bindValue(":b4", asocijacije.getB4());
        query.bindValue(":c1", asocijacije.getC1());
        query.bindValue(":c2", asocijacije.getC2());
        query.bindValue(":c3", asocijacije.getC3());
        query.bindValue(":c4", asocijacije.getC4());
        query.bindValue(":d1", asocijacije.getD1());
        query.bindValue(":d2", asocijacije.getD2());
        query.bindValue(":d3", asocijacije.getD3());
        query.bindValue(":d4", asocijacije.getD4());
        query.exec();
        
        asocijacije.setId(query.lastInsertId().toInt());
        
        query.prepare("INSERT INTO kviz_pitanja (tip, kviz_id, pitanje_id) "
                      "VALUES (:tip, :kviz_id, LAST_INSERT_ID())");
        query.bindValue(":tip", Kviz::Asocijacije);
        query.bindValue(":kvi_id", kvizId);
        query.exec();
    } else
    {
        query.prepare("UPDATE asocijacije SET "
                      "konacno=:konacno, "
                      "a=:a, b=:b, c=:c, d=:d, "
                      "a1=:a1, a2=:a2, a3=:a3, a4=:a4, "
                      "b1=:b1, b2=:b2, b3=:b3, b4=:b4, "
                      "c1=:c1, c2=:c2, c3=:c3, c4=:c4, "
                      "d1=:d1, d2=:d2, d3=:d3, d4=:d4 "
                      "WHERE id=:id");
        query.bindValue(":id", asocijacije.getId());
        query.bindValue(":konacno", asocijacije.getKonacnoResenje());
        query.bindValue(":a", asocijacije.getA());
        query.bindValue(":b", asocijacije.getB());
        query.bindValue(":c", asocijacije.getC());
        query.bindValue(":d", asocijacije.getD());
        query.bindValue(":a1", asocijacije.getA1());
        query.bindValue(":a2", asocijacije.getA2());
        query.bindValue(":a3", asocijacije.getA3());
        query.bindValue(":a4", asocijacije.getA4());
        query.bindValue(":b1", asocijacije.getB1());
        query.bindValue(":b2", asocijacije.getB2());
        query.bindValue(":b3", asocijacije.getB3());
        query.bindValue(":b4", asocijacije.getB4());
        query.bindValue(":c1", asocijacije.getC1());
        query.bindValue(":c2", asocijacije.getC2());
        query.bindValue(":c3", asocijacije.getC3());
        query.bindValue(":c4", asocijacije.getC4());
        query.bindValue(":d1", asocijacije.getD1());
        query.bindValue(":d2", asocijacije.getD2());
        query.bindValue(":d3", asocijacije.getD3());
        query.bindValue(":d4", asocijacije.getD4());
        query.exec();
        query.exec();
    }
    
    return asocijacije;
}

void Database::obrisiAsocijacije(int id)
{
    QSqlQuery query(m_db);
    
    m_db.transaction();
    query.prepare("DELETE FROM asocijacije WHERE id=:id");
    query.bindValue(":id", id);
    query.exec();
    
    query.prepare("DELETE FROM kviz_pitanja "
                  "WHERE pitanje_id=:id AND tip=:tip");
    query.bindValue(":id", id);
    query.bindValue(":tip", Kviz::Asocijacije);
    query.exec();
    m_db.commit();
}

Kviz Database::snimiKviz(Kviz kviz)
{
    QSqlQuery query(m_db);
    
    if(kviz.getId() < 0)
    {
        query.prepare("INSERT INTO nazivi_kvizova (naziv) "
                      "VALUES (:naziv)");
        query.bindValue(":naziv", kviz.getNaziv());
        query.exec();
        
        kviz.setId(query.lastInsertId().toInt());
    } else
    {
        query.prepare("UPDATE nazivi_kvizova SET "
                      "naziv=:naziv, "
                      "WHERE id=:id");
        query.bindValue(":id", kviz.getId());
        query.bindValue(":odgovor", kviz.getNaziv());
        query.exec();
    }
    
    return kviz;
}