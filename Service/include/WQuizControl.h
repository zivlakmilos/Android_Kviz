#ifndef _W_QUIZ_CONTROL_H_
#define _W_QUIZ_CONTROL_H_

#include <QWidget>

class QGroupBox;
class QSpinBox;
class QLabel;
class QSlider;
class QHBoxLayout;
class QVBoxLayout;
class QPushButton;

class WQuizControl : public QWidget
{
    Q_OBJECT
    
public:
    WQuizControl(QWidget *parent = 0);
    virtual ~WQuizControl(void);
    
private:
    void setupGui(void);
    
    enum { BrziPrsti = 0,
           KoZnaZna,
           Asocijacije,
           BrojTipova           // Mora biti na kraju
    };
    
    const QString m_labels[BrojTipova] = {
        "Brzi prsti",
        "Ko zna zna",
        "Asocijacije"
    };
    
    QGroupBox *m_gbOpcije[BrojTipova];
    QSlider *m_sliderBrojPitanja[BrojTipova];
    QSpinBox *m_sbBrojPitanja[BrojTipova];
    QLabel *m_lblBrojPitanja[BrojTipova];
    QSlider *m_sliderVreme[BrojTipova];
    QSpinBox *m_sbVreme[BrojTipova];
    QLabel *m_lblVreme[BrojTipova];
    QPushButton *m_btnSledecePitanje;
    QPushButton *m_btnRekordi;
    QHBoxLayout *m_layoutBrojPitanja[BrojTipova];
    QHBoxLayout *m_layoutVreme[BrojTipova];
    QVBoxLayout *m_layoutSubMain[BrojTipova];
    QVBoxLayout *m_layoutMian;
};

#endif // _W_QUIZ_CONTROL_H_