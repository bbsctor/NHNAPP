#ifndef HISTORYGRAPHQUERYVIEWMANAGER_H
#define HISTORYGRAPHQUERYVIEWMANAGER_H
#include "historydataqueryviewmanager.h"

class HistoryGraphQueryViewManager : public HistoryDataQueryViewManager
{
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> xValues READ xValues)
    Q_PROPERTY(QList<QVariant> yValues READ yValues)

public:
    HistoryGraphQueryViewManager(QObject *parent = 0);
    Q_INVOKABLE void getBackData();
    QList<QVariant> xValues() const
    {
        return m_xValues;
    }

    QList<QVariant> yValues() const
    {
        return m_yValues;
    }

public slots:

signals:

private:
    QList<QVariant> m_xValues;
    QList<QVariant> m_yValues;
};

#endif // HISTORYGRAPHQUERYVIEWMANAGER_H
