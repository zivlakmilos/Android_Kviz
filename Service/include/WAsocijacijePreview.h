#ifndef _W_ASOCIJACIJE_PREVIEW_H_
#define _W_ASOCIJACIJE_PREVIEW_H_

#include <QWidget>

#include <data/asocijacije.h>

class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class WAsocijacijePreview : public QWidget
{
    Q_OBJECT
    
public:
    WAsocijacijePreview(QWidget *parent = 0);
    virtual ~WAsocijacijePreview(void);
    
    void setData(Asocijacije *pitanje);
    
private:
    void setupGui(void);
    
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
    
    QLabel *m_lblKonacnoResenje;
    QLabel *m_lblA;
    QLabel *m_lblB;
    QLabel *m_lblC;
    QLabel *m_lblD;
    QLabel *m_lblA1;
    QLabel *m_lblA2;
    QLabel *m_lblA3;
    QLabel *m_lblA4;
    QLabel *m_lblB1;
    QLabel *m_lblB2;
    QLabel *m_lblB3;
    QLabel *m_lblB4;
    QLabel *m_lblC1;
    QLabel *m_lblC2;
    QLabel *m_lblC3;
    QLabel *m_lblC4;
    QLabel *m_lblD1;
    QLabel *m_lblD2;
    QLabel *m_lblD3;
    QLabel *m_lblD4;
};

#endif //_W_ASOCIJACIJE_PREVIEW_H_