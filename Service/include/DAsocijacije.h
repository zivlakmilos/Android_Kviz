#ifndef _D_ASOCIJACIJE_H_
#define _D_ASOCIJACIJE_H_

#include <QTableView>

#include <data/asocijacije.h>
#include <DPitanje.h>

class QMenu;
class QAction;

class Kviz;
class MAsocijacije;
class WAsocijacijePreview;

class DAsocijacije : public QTableView, public DPitanje
{
    Q_OBJECT
    
public:
    DAsocijacije(Kviz *kviz, QWidget* parent = 0);
    virtual ~DAsocijacije(void);
    
    void novoPitanje(void);
    void obrisiPitanje(void);
    void addAction(QAction *action);
    
private:
    Asocijacije snimiAsocijacije(Asocijacije koZnaZna);
    
    Kviz *m_kviz;
    MAsocijacije *m_model;
    WAsocijacijePreview *m_popupPreview;
    
    QMenu *m_popupKviz;
    
private slots:
    void doubleClicked(QModelIndex index);
    void customMenuRequest(QPoint pos);
    
protected:
    void closeEvent(QCloseEvent *event);
    bool eventFilter(QObject *obj, QEvent *event);
    
signals:
    void close(bool);
};

#endif // _D_ASOCIJACIJE_H_