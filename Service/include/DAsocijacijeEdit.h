#ifndef _D_ASOCIJACIJE_EDIT_H
#define _D_ASOCIJACIJE_EDIT_H

#include <QDialog>

class Asocijacije;

class DAsocijacijeEdit : public QDialog
{
    Q_OBJECT
    
public:
    DAsocijacijeEdit(Asocijacije *pitanje, QWidget* parent = 0);
    virtual ~DAsocijacijeEdit(void);
    
private:
};

#endif //_D_ASOCIJACIJE_EDIT_H