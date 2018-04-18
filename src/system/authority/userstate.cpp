#include "userstate.h"

UserState::Authority UserState::m_currentState=UserState::COMMON;

UserState::UserState(QObject *parent) : QObject(parent)
{

}
