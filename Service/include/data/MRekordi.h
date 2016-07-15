#ifndef _DATA_M_REKORDI_H_
#define _DATA_M_REKORDI_H_

#include <QAbstractTableModel>

#include "data/takmicar.h"

class MRekordi : public QAbstractTableModel
{
public:
    MRekordi(QList<Takmicar> data, QObject *parent = 0);
    virtual ~MRekordi(void);
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    
private:
    QList<Takmicar> m_data;
};

#endif // _DATA_M_REKORDI_H_