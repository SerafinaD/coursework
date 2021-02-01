#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QSize>
#include <PaintEvent.hpp>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicFlight->setStyleSheet("background-color:black;");
    scene = new QGraphicsScene();
}

void MainWindow::resizeEvent(QResizeEvent *k)
{
    QSize size = k->size();
    QSize old_size = k->oldSize();

    if (old_size.isValid())
    {
        ui->check_isRad->move(ui->check_isRad->x() + (size.width() - old_size.width()), ui->check_isRad->y() + (size.height() - old_size.height()));
        ui->line_xtarget->move(ui->line_xtarget->x() + (size.width() - old_size.width()), ui->line_xtarget->y() + (size.height() - old_size.height()));
        ui->label_xtarget->move(ui->label_xtarget->x() + (size.width() - old_size.width()), ui->label_xtarget->y() + (size.height() - old_size.height()));
        ui->line_ytarget->move(ui->line_ytarget->x() + (size.width() - old_size.width()), ui->line_ytarget->y() + (size.height() - old_size.height()));
        ui->label_ytarget->move(ui->label_ytarget->x() + (size.width() - old_size.width()), ui->label_ytarget->y() + (size.height() - old_size.height()));
        ui->line_xrocket->move(ui->line_xrocket->x() + (size.width() - old_size.width()), ui->line_xrocket->y() + (size.height() - old_size.height()));
        ui->label_xrocket->move(ui->label_xrocket->x() + (size.width() - old_size.width()), ui->label_xrocket->y() + (size.height() - old_size.height()));
        ui->line_yrocket->move(ui->line_yrocket->x() + (size.width() - old_size.width()), ui->line_yrocket->y() + (size.height() - old_size.height()));
        ui->label_yrocket->move(ui->label_yrocket->x() + (size.width() - old_size.width()), ui->label_yrocket->y() + (size.height() - old_size.height()));
        ui->label_angle->move(ui->label_angle->x() + (size.width() - old_size.width()), ui->label_angle->y() + (size.height() - old_size.height()));
        ui->line_fitarget->move(ui->line_fitarget->x() + (size.width() - old_size.width()), ui->line_fitarget->y() + (size.height() - old_size.height()));
        ui->line_vtarget->move(ui->line_vtarget->x() + (size.width() - old_size.width()), ui->line_vtarget->y() + (size.height() - old_size.height()));
        ui->label_vtarget->move(ui->label_vtarget->x() + (size.width() - old_size.width()), ui->label_vtarget->y() + (size.height() - old_size.height()));
        ui->line_Vrocket->move(ui->line_Vrocket->x() + (size.width() - old_size.width()), ui->line_Vrocket->y() + (size.height() - old_size.height()));
        ui->label_vrocket->move(ui->label_vrocket->x() + (size.width() - old_size.width()), ui->label_vrocket->y() + (size.height() - old_size.height()));
        ui->label_start->move(ui->label_start->x() + (size.width() - old_size.width()), ui->label_start->y() + (size.height() - old_size.height()));
        ui->line_time->move(ui->line_time->x() + (size.width() - old_size.width()), ui->line_time->y() + (size.height() - old_size.height()));
        ui->button_start->move(ui->button_start->x() + (size.width() - old_size.width()), ui->button_start->y() + (size.height() - old_size.height()));
        ui->graphicFlight->resize(ui->graphicFlight->size() + size - old_size);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::customEvent(QEvent* pe)
{
   if (pe->type() == PaintEvent::TypeEvent)
   {
       QPoint aim_p = static_cast<PaintEvent*>(pe)->aim_pos();
       QPoint rocket_p = static_cast<PaintEvent*>(pe)->rocket_pos();
       scene->clear();
          if(!aim_p.x() && !aim_p.y() && !rocket_p.x() && !rocket_p.y())
          {
                  QImage image(":/boom.png");
                  image = image.scaled(ui->graphicFlight->size());
                  scene->addPixmap(QPixmap::fromImage(image));
                  scene->setSceneRect(0,0,ui->graphicFlight->width(),ui->graphicFlight->height());
                  ui->graphicFlight->setScene(scene);
                  delete a;
                  delete rocket;
                  delete p_trd;
                  delete controllerl;
          }
          else
          {
                QBrush aim_br(QColor(255, 255, 10));
                QBrush rocket_br(QColor(255, 10, 10));
                aim_br.setStyle(Qt::BrushStyle::VerPattern);
                rocket_br.setStyle(Qt::BrushStyle::VerPattern);
                scene->addRect(QRect(aim_p.x(),aim_p.y(),2,2), QPen(QColor(255,255,10)), aim_br);
                scene->addRect(QRect(rocket_p.x(),rocket_p.y(),2,2), QPen(QColor(255,10,10)), rocket_br);
                ui->graphicFlight->setScene(scene);
          }
   }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left || event->key() == Qt::Key_A)
       {
           a->set_angle(a->get_angle() + qDegreesToRadians(5.0));
       }
    if (event->key() == Qt::Key_Right || event->key() == Qt::Key_D)
       {
           a->set_angle(a->get_angle() - qDegreesToRadians(5.0));
       }
}

void MainWindow::on_button_start_clicked()
{
    p_trd = new Paint_Trd(this);
    p_trd->start();
    double fi;
    if (!ui->check_isRad->checkState())
        fi = qDegreesToRadians(ui->line_fitarget->text().toDouble());
    a = new Aim(ui->line_xtarget->text().toDouble(), ui->line_ytarget->text().toDouble(), ui->line_vtarget->text().toDouble(), fi);
    rocket = new Rocket(ui->line_xrocket->text().toDouble(), ui->line_yrocket->text().toDouble(), ui->line_Vrocket->text().toDouble(), a);
    controllerl = new Controller(this, p_trd);
    controllerl->startCalc(a, rocket, ui->line_time->text().toDouble());
}

void MainWindow::on_line_xtarget_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_xtarget->setText(QString::number(0.0));
}

void MainWindow::on_line_ytarget_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_ytarget->setText(QString::number(0.0));
}

void MainWindow::on_line_fitarget_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_fitarget->setText(QString::number(0.0));
}

void MainWindow::on_line_vtarget_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_vtarget->setText(QString::number(0.0));
}

void MainWindow::on_line_xrocket_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_xrocket->setText(QString::number(0.0));
}

void MainWindow::on_line_yrocket_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_yrocket->setText(QString::number(0.0));
}

void MainWindow::on_line_time_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_time->setText(QString::number(0.0));
}

void MainWindow::on_line_Vrocket_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toDouble(&ok);
    if (!ok)
        ui->line_Vrocket->setText(QString::number(0.0));
}
