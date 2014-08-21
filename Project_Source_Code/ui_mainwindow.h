/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Apr 4 11:00:00 2011
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *s_main_layout;
    QGroupBox *groupBox_3;
    QPushButton *m_simulate;
    QPushButton *m_stop;
    QPushButton *m_reset;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;
    QDoubleSpinBox *m_maxSpeed;
    QDoubleSpinBox *m_minSpeed;
    QLabel *label_12;
    QLabel *label_11;
    QGroupBox *groupBox_2;
    QDoubleSpinBox *m_cohesionweight;
    QDoubleSpinBox *m_seperateweight;
    QDoubleSpinBox *m_alignweight;
    QDoubleSpinBox *m_neighbourdistance;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_10;
    QDoubleSpinBox *m_seperatedistance;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QGroupBox *groupBox;
    QSpinBox *m_numberBoids;
    QLabel *label;
    QPushButton *m_add;
    QPushButton *pushButton_2;
    QComboBox *m_type;
    QLabel *label_14;
    QDoubleSpinBox *m_boidscale;
    QLabel *label_15;
    QLabel *label_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1348, 865);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        s_main_layout = new QGridLayout(centralWidget);
        s_main_layout->setSpacing(6);
        s_main_layout->setContentsMargins(11, 11, 11, 11);
        s_main_layout->setObjectName(QString::fromUtf8("s_main_layout"));
        s_main_layout->setSizeConstraint(QLayout::SetMinimumSize);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMaximumSize(QSize(350, 100));
        m_simulate = new QPushButton(groupBox_3);
        m_simulate->setObjectName(QString::fromUtf8("m_simulate"));
        m_simulate->setGeometry(QRect(0, 0, 90, 27));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_simulate->sizePolicy().hasHeightForWidth());
        m_simulate->setSizePolicy(sizePolicy2);
        m_stop = new QPushButton(groupBox_3);
        m_stop->setObjectName(QString::fromUtf8("m_stop"));
        m_stop->setEnabled(false);
        m_stop->setGeometry(QRect(100, 0, 80, 27));
        sizePolicy2.setHeightForWidth(m_stop->sizePolicy().hasHeightForWidth());
        m_stop->setSizePolicy(sizePolicy2);
        m_stop->setDefault(false);
        m_reset = new QPushButton(groupBox_3);
        m_reset->setObjectName(QString::fromUtf8("m_reset"));
        m_reset->setEnabled(true);
        m_reset->setGeometry(QRect(200, 0, 80, 27));
        sizePolicy2.setHeightForWidth(m_reset->sizePolicy().hasHeightForWidth());
        m_reset->setSizePolicy(sizePolicy2);
        m_reset->setDefault(false);

        s_main_layout->addWidget(groupBox_3, 5, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(1024, 768, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        s_main_layout->addItem(horizontalSpacer, 1, 0, 5, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMinimumSize(QSize(300, 0));
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_maxSpeed = new QDoubleSpinBox(groupBox_4);
        m_maxSpeed->setObjectName(QString::fromUtf8("m_maxSpeed"));
        m_maxSpeed->setMinimum(0.5);
        m_maxSpeed->setMaximum(5);
        m_maxSpeed->setSingleStep(0.01);
        m_maxSpeed->setValue(0.8);

        gridLayout->addWidget(m_maxSpeed, 1, 1, 1, 1);

        m_minSpeed = new QDoubleSpinBox(groupBox_4);
        m_minSpeed->setObjectName(QString::fromUtf8("m_minSpeed"));
        m_minSpeed->setMinimum(0.01);
        m_minSpeed->setMaximum(4);
        m_minSpeed->setSingleStep(0.01);
        m_minSpeed->setValue(0.1);

        gridLayout->addWidget(m_minSpeed, 2, 1, 1, 1);

        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 2, 0, 1, 1);

        label_11 = new QLabel(groupBox_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 1, 0, 1, 1);


        s_main_layout->addWidget(groupBox_4, 3, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(300, 400));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        m_cohesionweight = new QDoubleSpinBox(groupBox_2);
        m_cohesionweight->setObjectName(QString::fromUtf8("m_cohesionweight"));
        m_cohesionweight->setGeometry(QRect(174, 130, 81, 31));
        m_cohesionweight->setDecimals(2);
        m_cohesionweight->setMaximum(1000);
        m_cohesionweight->setSingleStep(1);
        m_cohesionweight->setValue(10);
        m_seperateweight = new QDoubleSpinBox(groupBox_2);
        m_seperateweight->setObjectName(QString::fromUtf8("m_seperateweight"));
        m_seperateweight->setGeometry(QRect(174, 170, 81, 31));
        m_seperateweight->setDecimals(2);
        m_seperateweight->setMaximum(1000);
        m_seperateweight->setSingleStep(1);
        m_seperateweight->setValue(5);
        m_alignweight = new QDoubleSpinBox(groupBox_2);
        m_alignweight->setObjectName(QString::fromUtf8("m_alignweight"));
        m_alignweight->setGeometry(QRect(174, 210, 81, 31));
        m_alignweight->setDecimals(0);
        m_alignweight->setMaximum(1000);
        m_alignweight->setSingleStep(1);
        m_alignweight->setValue(15);
        m_neighbourdistance = new QDoubleSpinBox(groupBox_2);
        m_neighbourdistance->setObjectName(QString::fromUtf8("m_neighbourdistance"));
        m_neighbourdistance->setGeometry(QRect(175, 30, 81, 31));
        m_neighbourdistance->setSingleStep(0.01);
        m_neighbourdistance->setValue(8);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(8, 35, 161, 21));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(26, 135, 121, 21));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 175, 131, 21));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(21, 217, 121, 21));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 80, 141, 21));
        m_seperatedistance = new QDoubleSpinBox(groupBox_2);
        m_seperatedistance->setObjectName(QString::fromUtf8("m_seperatedistance"));
        m_seperatedistance->setGeometry(QRect(175, 75, 81, 31));
        m_seperatedistance->setMaximum(10);
        m_seperatedistance->setSingleStep(0.1);
        m_seperatedistance->setValue(3.5);
        line = new QFrame(groupBox_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 15, 266, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(4, 59, 266, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox_2);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(4, 105, 266, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        s_main_layout->addWidget(groupBox_2, 2, 1, 1, 1);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMinimumSize(QSize(250, 200));
        m_numberBoids = new QSpinBox(groupBox);
        m_numberBoids->setObjectName(QString::fromUtf8("m_numberBoids"));
        m_numberBoids->setGeometry(QRect(140, 30, 91, 31));
        m_numberBoids->setMaximum(500);
        m_numberBoids->setValue(10);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 40, 122, 17));
        m_add = new QPushButton(groupBox);
        m_add->setObjectName(QString::fromUtf8("m_add"));
        m_add->setGeometry(QRect(34, 170, 93, 27));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 170, 93, 27));
        m_type = new QComboBox(groupBox);
        m_type->setObjectName(QString::fromUtf8("m_type"));
        m_type->setGeometry(QRect(140, 70, 91, 27));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 75, 122, 17));
        m_boidscale = new QDoubleSpinBox(groupBox);
        m_boidscale->setObjectName(QString::fromUtf8("m_boidscale"));
        m_boidscale->setGeometry(QRect(140, 110, 91, 27));
        m_boidscale->setMinimum(0.1);
        m_boidscale->setMaximum(15);
        m_boidscale->setSingleStep(0.1);
        m_boidscale->setValue(1.5);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(89, 115, 51, 17));

        s_main_layout->addWidget(groupBox, 1, 1, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        s_main_layout->addWidget(label_6, 7, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1348, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Flocking System", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        m_simulate->setText(QApplication::translate("MainWindow", "Simulate", 0, QApplication::UnicodeUTF8));
        m_stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        m_reset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Other Options :", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Minimum Speed :", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Maximum Speed :", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Flocking Rules :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Neighbour Distance :", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Cohesion Weight :", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Seperation Weight:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Alignment Weight:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Separation Distance:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Boids :", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Number os Boids :", 0, QApplication::UnicodeUTF8));
        m_add->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        m_type->clear();
        m_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Teapot", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Sphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "Pyramid", 0, QApplication::UnicodeUTF8)
        );
        label_14->setText(QApplication::translate("MainWindow", "Types of Boids :", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Scale :", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Flocking System by Shalin K Banjara (i7913717) MSc Computer Animation and Visual Effects", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
