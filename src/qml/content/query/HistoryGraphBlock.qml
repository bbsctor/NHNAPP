//import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import QtQuick 2.0
import QtCharts 2.0
import SqlModel 1.0
import "../../common/button"

Rectangle {
    anchors.fill: parent

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent
        Rectangle{
            Layout.fillHeight: true
            Layout.fillWidth: true
            //![1]
            ChartView {
                title: "Line"
                antialiasing: true
                anchors.fill: parent
                LineSeries {
                    id:lineSeries
                    axisX: DateTimeAxis {
                        id:dtAxis
                        format: "hh:mm:ss"
                        tickCount: 5
                        //min:new Date(2017, 4, 14)
                        //max:new Date(2017, 4, 15)
                    }
                    axisY: ValueAxis {
                        min: 0
                        max: 300
                    }
                }
            }
            //![1]

        }

        Grid {
            id: grid
            x: 120
            y: 29
            spacing: 120
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            rows: 1
            columns: 3

            ContentButton {
                id: button
                text: qsTr("前一天")
            }

            ContentButton {
                id: button1
                text: qsTr("当天")
            }

            ContentButton {
                id: button2
                text: qsTr("后一天")
            }

            Connections {
                target: button
                onClicked: generateLine()
            }



        }
    }

    HistoryGraphQueryViewManager{
        id:viewManager
    }

    function generateLine()
    {
        viewManager.getBackData();
        var xValues = viewManager.xValues;
        var yValues = viewManager.yValues;
        dtAxis.min = new Date(xValues[0]);
        dtAxis.max = new Date(xValues[xValues.length - 1]);

        for(var i = 0; i < xValues.length; i++)
        {
            lineSeries.append(new Date(xValues[i]), yValues[i]);
        }
    }
}
