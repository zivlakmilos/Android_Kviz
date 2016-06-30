#include <data/MKoZnaZna.h>

#include <data/koznazna.h>

MKoZnaZna::MKoZnaZna(QList<KoZnaZna> data, QObject *parent)
    : QAbstractTableModel(parent),
      m_data(data)
{
}

MKoZnaZna::~MKoZnaZna(void)
{
}

int MKoZnaZna::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int MKoZnaZna::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant MKoZnaZna::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
        case Qt::DisplayRole: case Qt::EditRole:
            return podatakZaPrikaz(index.column(), index.row());
            break;
    }
    
    return QVariant();
}

QVariant MKoZnaZna::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                    return "Pitanje";
                    break;
                case 1:
                    return "Odgovor";
                    break;
            }
        } else
        {
            return section + 1;
        }
    }
    
    return QVariant();
}

QVariant MKoZnaZna::podatakZaPrikaz(int column, int row) const
{
    switch(column)
    {
        case 0:
            return m_data[row].getPitanje();
            break;
        case 1:
            return m_data[row].getOdgovor();
            break;
    }
    
    return QVariant();
}

void MKoZnaZna::dataChange(int index, KoZnaZna data)
{
    m_data[index] = data;
    emit dataChanged(this->index(index - 1, 0),
                     this->index(index - 1, columnCount() - 1));
}

void MKoZnaZna::addData(KoZnaZna data)
{
    int rowIndex = rowCount();
    
    m_data.append(data);
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    insertRow(rowCount());
    endInsertRows();
    
    emit dataChanged(index(rowIndex, 0),
                     index(rowIndex, columnCount() - 1));
}

void MKoZnaZna::removeData(int index)
{
    m_data.removeAt(index);
    
    beginRemoveRows(QModelIndex(), index, index);
    removeRow(index);
    endRemoveRows();
    
    emit dataChanged(this->index(index, 0),
                     this->index(index, columnCount() - 1));
}