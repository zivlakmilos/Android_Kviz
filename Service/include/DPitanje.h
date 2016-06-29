#ifndef _D_PITANJE_H_
#define _D_PITANJE_H_


class QAction;

class DPitanje
{
public:
    virtual void novoPitanje(void) = 0;
    virtual void obrisiPitanje(void) = 0;
    virtual void addAction(QAction *action) = 0;
};

#endif // _D_PITANJE_H_