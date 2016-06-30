#ifndef _DATA_M_BRZI_PRSTI
#define _DATA_M_BRZI_PRSTI

#include <QAbstractTableModel>

#include <data/koznazna.h>

class MKoZnaZna : public QAbstractTableModel
{
    Q_OBJECT
    
public:
    MKoZnaZna(QList<KoZnaZna> data, QObject *parent = 0);
    virtual ~MKoZnaZna(void);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    
    void dataChange(int index, KoZnaZna data);
    void addData(KoZnaZna data);
    QList<KoZnaZna> getData(void) { return m_data; };
    void removeData(int index);
    
private:
    QVariant podatakZaPrikaz(int column, int row) const;
    
    QList<KoZnaZna> m_data;
};

#endif // _DATA_M_BRZI_PRSTI