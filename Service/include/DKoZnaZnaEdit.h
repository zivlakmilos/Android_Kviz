#ifndef _D_KO_ZNA_ZNA_EDIT_H_
#define _D_KO_ZNA_ZNA_EDIT_H_

#include <QDialog>

#include <data/koznazna.h>

class QVBoxLayout;
class QHBoxLayout;
class QTextEdit;
class QLineEdit;
class QPushButton;
class QLabel;

class DKoZnaZnaEdit : public QDialog
{
    Q_OBJECT
    
public:
    DKoZnaZnaEdit(KoZnaZna *pitanje, QWidget *parent = 0);
    virtual ~DKoZnaZnaEdit(void);
    
    KoZnaZna getPitanje(void) const { return *m_pitanje; };
    
private:
    void setupGui(void);
    
    KoZnaZna *m_pitanje;
    
    QVBoxLayout *m_layoutMain;
    QHBoxLayout *m_layoutButtons;
    
    QLabel *m_lblPitanje;
    QTextEdit *m_txtPitanje;
    QLabel *m_lblOdgovor;
    QLineEdit *m_txtOdgovor;
    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;
    
private slots:
    void prihvati(void);
};

#endif // _D_KO_ZNA_ZNA_EDIT_H_