#ifndef USERSTATE_H
#define USERSTATE_H

#include <QObject>

class UserState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Authority currentState READ currentState WRITE setCurrentState NOTIFY currentStateChanged)
public:
    explicit UserState(QObject *parent = 0);
    enum Authority{COMMON, OPERATE, ADMIN};
    Q_ENUMS(Authority)

    Authority currentState() const
    {
        return m_currentState;
    }

signals:
    void currentStateChanged(Authority currentState);
public slots:
void setCurrentState(Authority currentState)
{
    if (m_currentState == currentState)
        return;
    m_currentState = currentState;
    emit currentStateChanged(currentState);
}

private:
    static Authority m_currentState;
};

#endif // USERSTATE_H
