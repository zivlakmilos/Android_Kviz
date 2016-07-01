#ifndef _DATA_M_BRZI_PRSTI
#define _DATA_M_BRZI_PRSTI

#include <QAbstractTableModel>

#include <data/asocijacije.h>

class MAsocijacije : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    MAsocijacije(QList<Asocijacije> data, QObject *parent = 0);
    virtual ~MAsocijacije(void);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    
    void dataChange(int index, Asocijacije data);
    void addData(Asocijacije data);
    QList<Asocijacije> getData(void) { return m_data; };
    void removeData(int index);
    
private:
    QVariant podatakZaPrikaz(int column, int row) const;
    
    QList<Asocijacije> m_data;
};

#endif // _DATA_M_BRZI_PRSTI