#ifndef _D_KO_ZNA_ZNA_H_
#define _D_KO_ZNA_ZNA_H_

#include <QTableView>

#include <data/koznazna.h>
#include <DPitanje.h>

class QMenu;
class QAction;

class Kviz;
class MKoZnaZna;

class DKoZnaZna : public QTableView, public DPitanje
{
    Q_OBJECT
    
public:
    DKoZnaZna(Kviz *kviz, QWidget* parent = 0);
    virtual ~DKoZnaZna(void);
    
    void novoPitanje(void);
    void obrisiPitanje(void);
    void addAction(QAction *action);
    
private:
    KoZnaZna snimiKoZnaZna(KoZnaZna koZnaZna);
    
    Kviz *m_kviz;
    MKoZnaZna *m_model;
    
    QMenu *m_popupKviz;
    
private slots:
    void doubleClicked(QModelIndex index);
    void customMenuRequest(QPoint pos);
    
protected:
    void closeEvent(QCloseEvent *event);
    
signals:
    void close(bool);
};

#endif // _D_KO_ZNA_ZNA_H_