#include "QObservable.h"
#include <QDebug>

QObservable::QObservable():m_bChanged(false)
{

}

void QObservable::Attach(QObserver *pObs)
{
    if(!pObs)
        return;

    m_setObs.insert(pObs);
}

void QObservable::Detach(QObserver *pObs)
{
    if(!pObs)
        return;

    m_setObs.remove(pObs);
}

void QObservable::DetachAll()
{
    m_setObs.clear();
}

void QObservable::Notify(void *pArg)
{
    if(!HasChanged())
        return;
    qDebug() << "notify observers…" ;
    ClearChanged();
    QSet<QObserver*>::iterator itr = m_setObs.begin();
    for(; itr != m_setObs.end(); itr++)
    {
        (*itr)->Update(this,pArg);
    }
}

bool QObservable::HasChanged()
{
    return m_bChanged;
}

int QObservable::GetObserversCount()
{
    return m_setObs.size();
}

void QObservable::SetChanged()
{
    m_bChanged=true;
}

void QObservable::ClearChanged()
{
    m_bChanged=false;
}








