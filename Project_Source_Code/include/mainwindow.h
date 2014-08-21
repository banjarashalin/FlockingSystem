#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GLWindow.h"
#include <QMainWindow>
#include "Flock.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected :

        /// @brief override the keyPressEvent inherited from QObject so we can handle key presses.
        /// @param [in] _event the event to process
                            void keyPressEvent(QKeyEvent *_event);
                           // void resizeEvent (QResizeEvent * _event);
        ///-------------------------------------------------------------------------------------------------------

public:
    explicit MainWindow(int _numBoids,QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GLWindow *m_gl;


private slots:
    void on_m_reset_clicked();
    void on_m_stop_clicked();
    void on_m_simulate_clicked();
    void on_m_type_currentIndexChanged(int index);
    void on_pushButton_2_clicked();
    void on_m_add_clicked();
    void on_m_neighbourdistance_valueChanged(double );
};

#endif // MAINWINDOW_H

