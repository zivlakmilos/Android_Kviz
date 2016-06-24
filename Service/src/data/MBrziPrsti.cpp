#include <data/MBrziPrsti.h>

#include <data/brziprsti.h>

MBrziPrsti::MBrziPrsti(QList<BrziPrsti> data, QObject *parent)
    : QAbstractTableModel(parent),
      m_data(data)
{
}

MBrziPrsti::~MBrziPrsti(void)
{
}

int MBrziPrsti::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int MBrziPrsti::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QVariant MBrziPrsti::data(const QModelIndex &index, int role) const
{
    switch(role)
    {
        case Qt::DisplayRole:
            return podatakZaPrikaz(index.column(), index.row());
            break;
    }
    
    return QVariant();
}

QVariant MBrziPrsti::headerData(int section, Qt::Orientation orientation, int role) const
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
                    return "A";
                    break;
                case 2:
                    return "B";
                    break;
                case 3:
                    return "C";
                    break;
                case 4:
                    return "D";
                    break;
                case 5:
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

QVariant MBrziPrsti::podatakZaPrikaz(int column, int row) const
{
    switch(column)
    {
        case 0:
            return m_data[row].getPitanje();
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
            break;
        case 5:
            return m_data[row].getOdgovor();
            break;
    }
}