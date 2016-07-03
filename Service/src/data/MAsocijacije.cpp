#include <data/MAsocijacije.h>

#include <data/asocijacije.h>

MAsocijacije::MAsocijacije(QList<Asocijacije> data, QObject *parent)
    : QAbstractTableModel(parent),
      m_data(data)
{
}

MAsocijacije::~MAsocijacije(void)
{
}

int MAsocijacije::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int MAsocijacije::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant MAsocijacije::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
        case Qt::DisplayRole: case Qt::EditRole:
            return podatakZaPrikaz(index.column(), index.row());
            break;
    }
    
    return QVariant();
}

QVariant MAsocijacije::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section)
            {
                case 0:
                    return "Konacno resenje";
                    break;
                case 1:
                    return "A";
                    break;
                case 2:
                    return "B";
                    break;
                case 3:
                    return "C";
                case 4:
                    return "D";
            }
        } else
        {
            return section + 1;
        }
    }
    
    return QVariant();
}

QVariant MAsocijacije::podatakZaPrikaz(int column, int row) const
{
    switch(column)
    {
        case 0:
            return m_data[row].getKonacnoResenje();
            break;
        case 1:
            return m_data[row].getA();
            break;
        case 2:
            return m_data[row].getB();
            break;
        case 3:
            return m_data[row].getC();
            break;
        case 4:
            return m_data[row].getD();
    }
    
    return QVariant();
}

void MAsocijacije::dataChange(int index, Asocijacije data)
{
    m_data[index] = data;
    emit dataChanged(this->index(index - 1, 0),
                     this->index(index - 1, columnCount() - 1));
}

void MAsocijacije::addData(Asocijacije data)
{
    int rowIndex = rowCount();
    
    m_data.append(data);
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    insertRow(rowCount());
    endInsertRows();
    
    emit dataChanged(index(rowIndex, 0),
                     index(rowIndex, columnCount() - 1));
}

void MAsocijacije::removeData(int index)
{
    m_data.removeAt(index);
    
    beginRemoveRows(QModelIndex(), index, index);
    removeRow(index);
    endRemoveRows();
    
    emit dataChanged(this->index(index, 0),
                     this->index(index, columnCount() - 1));
}