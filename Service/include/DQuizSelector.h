#ifndef _D_QUIZ_SELECTOR_
#define _D_QUIZ_SELECTOR_

#include <QWidget>

class QComboBox;
class QPushButton;

class DQuizSelector : public QWidget
{
    public:
        DQuizSelector(QWidget* parent = 0);
        virtual ~DQuizSelector(void);
        
    private:
        QComboBox *m_cbKvizovi;
        QPushButton *m_btnOk;
        QPushButton *m_btnCancel;
        
        void setupGui(void);
};

#endif // _D_QUIZ_SELECTOR_