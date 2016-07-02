#ifndef _D_ASOCIJACIJE_EDIT_H
#define _D_ASOCIJACIJE_EDIT_H

#include <QDialog>

#include <data/asocijacije.h>

class QPushButton;
class QLineEdit;
class QVBoxLayout;
class QHBoxLayout;

class DAsocijacijeEdit : public QDialog
{
    Q_OBJECT
    
public:
    DAsocijacijeEdit(Asocijacije *pitanje, QWidget *parent = 0);
    virtual ~DAsocijacijeEdit(void);
    
    Asocijacije getPitanje(void) const { return *m_pitanje; };
    
private:
    void setupGui(void);
    
    Asocijacije *m_pitanje;
    
    QVBoxLayout *m_layoutMain;
    QHBoxLayout *m_layoutKonacnoResenje;
    QHBoxLayout *m_layoutAB;
    QHBoxLayout *m_layoutAB1;
    QHBoxLayout *m_layoutAB2;
    QHBoxLayout *m_layoutAB3;
    QHBoxLayout *m_layoutAB4;
    QHBoxLayout *m_layoutCD;
    QHBoxLayout *m_layoutCD1;
    QHBoxLayout *m_layoutCD2;
    QHBoxLayout *m_layoutCD3;
    QHBoxLayout *m_layoutCD4;
    QHBoxLayout *m_layoutButtons;
    
    QLineEdit *m_txtKonacnoResenje;
    QLineEdit *m_txtA;
    QLineEdit *m_txtB;
    QLineEdit *m_txtC;
    QLineEdit *m_txtD;
    QLineEdit *m_txtA1;
    QLineEdit *m_txtA2;
    QLineEdit *m_txtA3;
    QLineEdit *m_txtA4;
    QLineEdit *m_txtB1;
    QLineEdit *m_txtB2;
    QLineEdit *m_txtB3;
    QLineEdit *m_txtB4;
    QLineEdit *m_txtC1;
    QLineEdit *m_txtC2;
    QLineEdit *m_txtC3;
    QLineEdit *m_txtC4;
    QLineEdit *m_txtD1;
    QLineEdit *m_txtD2;
    QLineEdit *m_txtD3;
    QLineEdit *m_txtD4;
    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;
    
private slots:
    void prihvati(void);
};

#endif //_D_ASOCIJACIJE_EDIT_H