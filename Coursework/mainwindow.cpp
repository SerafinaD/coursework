#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QSize>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
