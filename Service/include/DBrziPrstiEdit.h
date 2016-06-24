#ifndef _D_BRZI_PRSTI_EDIT_H_
#define _D_BRZI_PRSTI_EDIT_H_

#include <QDialog>

#include <data/brziprsti.h>

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QComboBox;
class QPushButton;

class DBrziPrstiEdit : public QDialog
{
    Q_OBJECT
    
public:
    DBrziPrstiEdit(BrziPrsti *pitanje, QWidget* parent = 0);
    virtual ~DBrziPrstiEdit(void);
    
    BrziPrsti getPitanje(void) { return *m_pitanje; };
    
private:
    void setupGui(void);
    
    QVBoxLayout *m_layoutMain;
    QHBoxLayout *m_layoutOdgovor;
    QHBoxLayout *m_layoutButtons;
    
    QLabel *m_lblPitanje;
    QLineEdit *m_txtPitanje;
    QLabel *m_lblA;
    QLineEdit *m_txtA;
    QLabel *m_lblB;
    QLineEdit *m_txtB;
    QLabel *m_lblC;
    QLineEdit *m_txtC;
    QLabel *m_lblD;
    QLineEdit *m_txtD;
    QLabel *m_lblOdgovor;
    QComboBox *m_cbOdgovor;
    QPushButton *m_btnOk;
    QPushButton *m_btnCancel;
    
    BrziPrsti *m_pitanje;
    
private slots:
    void prihvati(void);
};

#endif // _D_BRZI_PRSTI_EDIT_H_