#ifndef _DATA_M_BRZI_PRSTI
#define _DATA_M_BRZI_PRSTI

#include <QAbstractTableModel>

#include <data/brziprsti.h>

class MBrziPrsti : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    MBrziPrsti(QList<BrziPrsti> data, QObject *parent);
    virtual ~MBrziPrsti(void);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    
    void dataChange(int index, BrziPrsti data) { m_data[index] = data; };
    void addData(BrziPrsti data) { m_data.append(data); };
    
private:
    QVariant podatakZaPrikaz(int column, int row) const;
    
    QList<BrziPrsti> m_data;
};

#endif // _DATA_M_BRZI_PRSTI