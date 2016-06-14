#ifndef _D_QUIZ_SELECTOR_
#define _D_QUIZ_SELECTOR_

#include <QDialog>

class QLabel;
class QComboBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

class DQuizSelector : public QDialog
{
    public:
        DQuizSelector(QWidget* parent = 0);
        virtual ~DQuizSelector(void);
        
    private:
        QLabel *m_lblIzborKviza;
        QComboBox *m_cbKvizovi;
        QPushButton *m_btnOk;
        QPushButton *m_btnCancel;
        
        QVBoxLayout *m_mainLayout;
        QHBoxLayout *m_buttonsLayout;
        
        void setupGui(void);
};

#endif // _D_QUIZ_SELECTOR_