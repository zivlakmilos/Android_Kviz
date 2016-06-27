#ifndef _D_BRZI_PRSTI_H_
#define _D_BRZI_PRSTI_H_

#include <QTableView>

#include <data/brziprsti.h>

class QMenu;
class QAction;

class Kviz;
class MBrziPrsti;
class DBrziPrstiEdit;

class DBrziPrsti : public QTableView
{
    Q_OBJECT
    
public:
    DBrziPrsti(Kviz *kviz, QWidget *parent = 0);
    virtual ~DBrziPrsti(void);
    
    void novoPitanje(void);
    void obrisiPitanje(void);
    void addAction(QAction *action);
    
private:
    BrziPrsti snimiBrzePrste(BrziPrsti brziPrsti);
    
    Kviz *m_kviz;
    MBrziPrsti *m_model;
    
    QMenu *m_popupKviz;
    
protected:
    void closeEvent(QCloseEvent *event);
    
private slots:
    void doubleClicked(QModelIndex index);
    void customMenuRequest(QPoint pos);
    
signals:
    void close(bool);
};

#endif // _D_BRZI_PRSTI_H_