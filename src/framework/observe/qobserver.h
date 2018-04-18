#ifndef QOBSERVER
#define QOBSERVER

class QObservable;

class QObserver
{
public:
    virtual ~QObserver()
    {

    }
    //当被观察的目标发生变化时，通知调用该方法
    //来自被观察者pObs,扩展参数为pArg
    virtual void Update(QObservable *pObs, void *pArg = 0) = 0;
};

#endif // QOBSERVER
