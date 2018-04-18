import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.0
import ViewManager 1.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4

TabViewStyle{

                tab:Item{

                    implicitWidth:  180;
                    implicitHeight: 60;

                    //被选中状态下的item
                    Rectangle{

                        width: (styleData.index < control.count - 1 ) ? (parent.width - 2 ):parent.width;
                        height: parent.height - 4;
                        anchors.top: parent.top;
                        anchors.left: parent.left;
                        anchors.leftMargin: 1;
                        visible: styleData.selected;

                        gradient: Gradient{
                            GradientStop{position: 0.0 ; color:"#606060";}
                            GradientStop{position: 0.5 ; color:"#c0c0c0";}
                            GradientStop{position: 1.0 ; color:"#a0a0a0";}

                        }

                    }

                    //未选中的状态
                    Rectangle{

                        width: 2;
                        height: parent.height - 4;
                        anchors.top:  parent.top;
                        anchors.right: parent.right;
                        visible:  styleData.index < control.count - 1;
                        gradient: Gradient{

                            GradientStop{position: 0.0 ; color:"#404040";}
                            GradientStop{position: 0.5 ; color:"#707070";}
                            GradientStop{position: 1.0 ; color:"#404040";}
                        }


                    }

                    //item的水平布局
                    RowLayout{

                        implicitWidth:  Math.max( text.width , 71);
                        height: 48;
                        anchors.centerIn:  parent;
                        z : 1;

                        Text{

                            id: text;
                            text:styleData.title;
                            color:styleData.selected ?"blue" : (styleData.hovered ? "green":"white");
                            font.pointSize: 16
                        }

                    }



                }


                tabBar :Rectangle{

                    height: 56;

                    gradient: Gradient{

                        GradientStop{position: 0.0 ; color:"#484848";}
                        GradientStop{position: 0.3 ; color:"#787878";}
                        GradientStop{position: 1.0 ; color:"#a0a0a0";}
                    }


                    Rectangle{

                        width: parent.width;
                        height: 4;
                        anchors.bottom: parent.bottom;
                        border.width: 2;
                        border.color: "#c7c7c7";

                    }
                }
            }
