#include "runninginfodatamodel.h"

RunningInfoDataModel::RunningInfoDataModel(QObject *parent):DataModel(parent)
{

}

QString RunningInfoDataModel::currentAction() const
{
    return m_currentAction;
}

void RunningInfoDataModel::setCurrentAction(const QString &currentAction)
{
    m_currentAction = currentAction;
}

QString RunningInfoDataModel::nextAction() const
{
    return m_nextAction;
}

void RunningInfoDataModel::setNextAction(const QString &nextAction)
{
    m_nextAction = nextAction;
}

QString RunningInfoDataModel::dispelTemperature() const
{
    return m_dispelTemperature;
}

void RunningInfoDataModel::setDispelTemperature(const QString &dispelTemperature)
{
    m_dispelTemperature = dispelTemperature;
}

QString RunningInfoDataModel::environmentTemperature() const
{
    return m_environmentTemperature;
}

void RunningInfoDataModel::setEnvironmentTemperature(const QString &environmentTemperature)
{
    m_environmentTemperature = environmentTemperature;
}

QString RunningInfoDataModel::absorbance() const
{
    return m_absorbance;
}

void RunningInfoDataModel::setAbsorbance(const QString &absorbance)
{
    m_absorbance = absorbance;
}

int RunningInfoDataModel::progress() const
{
    return m_progress;
}

void RunningInfoDataModel::setProgress(int progress)
{
    m_progress = progress;
}

QString RunningInfoDataModel::currentStatus() const
{
    return m_currentStatus;
}

void RunningInfoDataModel::setCurrentStatus(const QString &currentStatus)
{
    m_currentStatus = currentStatus;
}

QString RunningInfoDataModel::coolerTempearture() const
{
    return m_coolerTempearture;
}

void RunningInfoDataModel::setCoolerTempearture(const QString &coolerTempearture)
{
    m_coolerTempearture = coolerTempearture;
}

QString RunningInfoDataModel::switchValvoStatus() const
{
    return m_switchValvoStatus;
}

void RunningInfoDataModel::setSwitchValvoStatus(const QString &switchValvoStatus)
{
    m_switchValvoStatus = switchValvoStatus;
}

QString RunningInfoDataModel::injectBumbStatus() const
{
    return m_injectBumbStatus;
}

void RunningInfoDataModel::setInjectBumbStatus(const QString &injectBumbStatus)
{
    m_injectBumbStatus = injectBumbStatus;
}
