#include <data/MRekordi.h>

MRekordi::MRekordi(QList<Takmicar> data, QObject *parent)
    : QAbstractTableModel(parent),
      m_data(data)
{
}

MRekordi::~MRekordi(void)
{
}

int MRekordi::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.size();
}

int MRekordi::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant MRekordi::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();
    
    switch(role)
    {
        case Qt::DisplayRole: case Qt::EditRole:
            switch(index.column())
            {
                case 0:
                    return m_data[index.row()].getIme();
                    break;
                case 1:
                    return m_data[index.row()].getBodoviUkupno();
                    break;
            }
            break;
    }
    
    return QVariant();
}

QVariant MRekordi::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(role)
    {
        case Qt::DisplayRole:
            if(orientation == Qt::Horizontal)
            {
                switch(section)
                {
                    case 0:
                        return QString("Ime");
                        break;
                    case 1:
                        return QString("Bodovi");
                }
            } else
            {
                return section;
            }
            break;
    }
    
    return QAbstractItemModel::headerData(section, orientation, role);
}