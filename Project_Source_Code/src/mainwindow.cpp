#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GLWindow.h"

MainWindow::MainWindow(int _numBoids,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_gl = new GLWindow(_numBoids,this);
    ui->s_main_layout->addWidget(m_gl,0,0,5,1,0);
    this->resize(QSize(120,120));

    connect(ui->m_alignweight,SIGNAL(valueChanged(double)),m_gl,SLOT(setFlockAlignmentWeight(double)));
    connect(ui->m_seperateweight,SIGNAL(valueChanged(double)),m_gl,SLOT(setFlockSeperationWeight(double)));
    connect(ui->m_cohesionweight,SIGNAL(valueChanged(double)),m_gl,SLOT(setFlockCohesionWeight(double)));
    connect(ui->m_seperatedistance,SIGNAL(valueChanged(double)),m_gl,SLOT(setFlockSeperateDistance(double)));
    connect (ui->m_minSpeed,SIGNAL(valueChanged(double)),m_gl,SLOT(setMinSpeed(double)));
    connect (ui->m_maxSpeed,SIGNAL(valueChanged(double)),m_gl,SLOT(setMaxSpeed(double)));
    connect (ui->m_boidscale,SIGNAL(valueChanged(double)),m_gl,SLOT(setboidScale(double)));
    ui->m_seperatedistance->setMaximum(ui->m_neighbourdistance->value());
    m_gl->setboidScale(1.5);
    m_gl->setboidType("Teapot");
    m_gl->setFlockNeighboutDistance(8);
    m_gl->setFlockSeperateDistance(3.5);
    m_gl->setFlockCohesionWeight(10);
    m_gl->setFlockSeperationWeight(5);
    m_gl->setFlockAlignmentWeight(15);
    m_gl->setMaxSpeed(0.8);
    m_gl->setMinSpeed(0.1);
    m_gl->setboidScale(1.5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *_event)
{
    m_gl->keyPress(_event);
          // finally update the GLWindow and re-draw
    m_gl->updateGL();
}

void MainWindow::on_m_neighbourdistance_valueChanged(double val)
{
    m_gl->setFlockNeighboutDistance(val);

    ui->m_seperatedistance->setMaximum(val);
}

void MainWindow::on_m_add_clicked()
{
    m_gl->addBoids(ui->m_numberBoids->value());
}

void MainWindow::on_pushButton_2_clicked()
{
    m_gl->removeBoids(ui->m_numberBoids->value());
}

void MainWindow::on_m_type_currentIndexChanged(int index)
{

   m_gl->setboidType(ui->m_type->itemText(index).toStdString());
}

void MainWindow::on_m_simulate_clicked()
{
    m_gl->toggleAnimation();
    ui->m_simulate->setDisabled("false");
    ui->m_stop->setEnabled("True");
}


void MainWindow::on_m_stop_clicked()
{
    m_gl->toggleAnimation();
    ui->m_simulate->setEnabled("true");
    ui->m_stop->setDisabled("false");

}

void MainWindow::on_m_reset_clicked()
{
    m_gl->resetBoids();
    m_gl->updateGL();
}
