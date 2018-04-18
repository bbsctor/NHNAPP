#ifndef QOBSERVABLE_H
#define QOBSERVABLE_H

#include "QObserver.h"
#include <QSet>

class QObservable
{
public:
    QObservable();
    virtual ~QObservable(){}
    // 注册观察者
    void Attach(QObserver *pObs);
    // 注销观察者
    void Detach(QObserver *pObs);
    // 注销所有观察者
    void DetachAll();
    // 若状态变化，则遍历所有观察者，逐个通知更新
    void Notify(void *pArg = NULL);
    // 测试目标状态是否变化
    bool HasChanged();
    // 获取观察者数量
    int GetObserversCount();

protected:
    // 设置状态变化！！！必须继承QObervable才能设置目标状态
    void SetChanged();
    // 初始化目标为未变化状态
    void ClearChanged();

private:
    // 状态
    bool m_bChanged;
    // set保证目标唯一性
    QSet <QObserver*> m_setObs;
};

#endif // QOBSERVABLE_H
