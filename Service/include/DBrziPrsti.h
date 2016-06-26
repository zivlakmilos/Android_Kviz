#ifndef _D_BRZI_PRSTI_H_
#define _D_BRZI_PRSTI_H_

#include <QTableView>

#include <data/brziprsti.h>

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
    
private:
    BrziPrsti snimiBrzePrste(BrziPrsti brziPrsti);
    
    Kviz *m_kviz;
    QList<BrziPrsti> m_pitanja;
    MBrziPrsti *m_model;
    
protected:
    void closeEvent(QCloseEvent *event);
    
private slots:
    void doubleClicked(QModelIndex index);
    
signals:
    void close(bool);
};

#endif // _D_BRZI_PRSTI_H_