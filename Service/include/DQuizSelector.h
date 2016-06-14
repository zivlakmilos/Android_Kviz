#ifndef _D_QUIZ_SELECTOR_
#define _D_QUIZ_SELECTOR_

#include <QDialog>

class QLabel;
class QComboBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class Kviz;

class DQuizSelector : public QDialog
{
public:
    DQuizSelector(QWidget* parent = 0);
    virtual ~DQuizSelector(void);
    
    /* Getters and Setters */
    QString getSelectedQuizId(void);
    
private:
    QLabel *m_lblIzborKviza;
    QComboBox *m_cbKvizovi;
    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;
    
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_buttonsLayout;
    
    QList<Kviz> m_kvizovi;
    
    void setupGui(void);
};

#endif // _D_QUIZ_SELECTOR_