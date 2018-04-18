#include "settingdefaultinformationdatamodel.h"

SettingDefaultInformationDataModel::SettingDefaultInformationDataModel()
{

}

        char SettingDefaultInformationDataModel::RS485Status() const
        {
            return m_RS485Status;
        }

        void SettingDefaultInformationDataModel::setRS485Status(char RS485Status)
        {
            m_RS485Status = RS485Status;
        }

        char SettingDefaultInformationDataModel::autoMeasurePeriod() const
        {
            return m_autoMeasurePeriod;
        }

        void SettingDefaultInformationDataModel::setAutoMeasurePeriod(char autoMeasurePeriod)
        {
            m_autoMeasurePeriod = autoMeasurePeriod;
        }

        char SettingDefaultInformationDataModel::autoCalibrationPeriod() const
        {
            return m_autoCalibrationPeriod;
        }

        void SettingDefaultInformationDataModel::setAutoCalibrationPeriod(char autoCalibrationPeriod)
        {
            m_autoCalibrationPeriod = autoCalibrationPeriod;
        }

        char SettingDefaultInformationDataModel::measureMode() const
        {
            return m_measureMode;
        }

        void SettingDefaultInformationDataModel::setMeasureMode(char measureMode)
        {
            m_measureMode = measureMode;
        }

        char SettingDefaultInformationDataModel::pumpStartTime() const
        {
            return m_pumpStartTime;
        }

        char SettingDefaultInformationDataModel::dispelTime() const
        {
            return m_dispelTime;
        }

        void SettingDefaultInformationDataModel::setDispelTime(char dispelTime)
        {
            m_dispelTime = dispelTime;
        }

        void SettingDefaultInformationDataModel::setPumpStartTime(char pumpStartTime)
        {
            m_pumpStartTime = pumpStartTime;
        }

        ushort SettingDefaultInformationDataModel::alertUpper() const
        {
            return m_alertUpper;
        }

        void SettingDefaultInformationDataModel::setAlertUpper(const ushort &alertUpper)
        {
            m_alertUpper = alertUpper;
        }

        ushort SettingDefaultInformationDataModel::alertLower() const
        {
            return m_alertLower;
        }

        void SettingDefaultInformationDataModel::setAlertLower(const ushort &alertLower)
        {
            m_alertLower = alertLower;
        }

        char SettingDefaultInformationDataModel::currentSelectCurve() const
        {
            return m_currentSelectCurve;
        }

        void SettingDefaultInformationDataModel::setCurrentSelectCurve(char currentSelectCurve)
        {
            m_currentSelectCurve = currentSelectCurve;
        }

        char SettingDefaultInformationDataModel::slaveAddress() const
        {
            return m_slaveAddress;
        }

        void SettingDefaultInformationDataModel::setSlaveAddress(char slaveAddress)
        {
            m_slaveAddress = slaveAddress;
        }

        void SettingDefaultInformationDataModel::set4to20mAStatus(char _4to20mAStatus)
        {
            m_4to20mAStatus = _4to20mAStatus;
        }

        char SettingDefaultInformationDataModel::_4to20mAStatus() const
        {
            return m_4to20mAStatus;
        }
//        char SettingDefaultInformationDataModel::currentSelectCurve() const
//        {
//            return m_currentSelectCurve;
//        }
//        void SettingDefaultInformationDataModel::setCurrentSelectCurve(char currentSelectCurve)
//        {
//            m_currentSelectCurve=currentSelectCurve;
//        }




