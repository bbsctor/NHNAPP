#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include <QObject>
#include <QMap>

class AppContext : public QObject
{
    Q_OBJECT
public:
    explicit AppContext(QObject *parent = 0);
    static bool set(QString name, void* obj);
    static void* get(QString name);
    static bool init();
    static bool initDataModel();
    static bool initController();
    static bool initTimer();
signals:

public slots:
protected:

private:
    static QMap<QString, void*> map;
};

#endif // APPCONTEXT_H
