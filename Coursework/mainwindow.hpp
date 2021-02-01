#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QResizeEvent>
#include <QEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "classController.hpp"
#include "classAim.hpp"
#include "classRocket.hpp"
#include "PaintTrd.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent*);
protected:
    void customEvent(QEvent* pe) override;

    virtual void keyPressEvent(QKeyEvent *event);
private slots:
    void on_button_start_clicked();

    void on_line_xtarget_textChanged(const QString &arg1);

    void on_line_ytarget_textChanged(const QString &arg1);

    void on_line_fitarget_textChanged(const QString &arg1);

    void on_line_vtarget_textChanged(const QString &arg1);

    void on_line_xrocket_textChanged(const QString &arg1);

    void on_line_yrocket_textChanged(const QString &arg1);

    void on_line_time_textChanged(const QString &arg1);

    void on_line_Vrocket_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Controller *controllerl;
    Aim *a;
    Paint_Trd *p_trd;
    Rocket *rocket;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_HPP
