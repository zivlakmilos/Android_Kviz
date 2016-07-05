#ifndef _D_ANDROID_PROJECTOR_H_
#define _D_ANDROID_PROJECTOR_H_

#include <QWidget>

class DAndroidProjector : public QWidget
{
    Q_OBJECT
    
public:
    DAndroidProjector(QWidget *parent = 0);
    virtual ~DAndroidProjector(void);
    
private:
};

#endif // _D_ANDROID_PROJECTOR_H_