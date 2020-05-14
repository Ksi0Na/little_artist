#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _l1()
    , _scene(new Scene(this))
{
    ui->setupUi(this);
//=============NICE_VEIW=============
    QString styleButton=QString(
               "QAbstractButton {"
                       "border: 2px solid rgb(0,0,0); "
                       "background: rgb(110,110,110);"
               "}"
               "QAbstractButton:pressed  {"
                       "border: 4px solid rgb(50,50,50); "
                       "background: rgb(95, 95, 95);"
                       "}");
    ui->pb_del->setStyleSheet(styleButton);
    ui->pb_move->setStyleSheet(styleButton);
    ui->pb_select->setStyleSheet(styleButton);
    ui->pb_ellipse->setStyleSheet(styleButton);
    ui->pb_rect->setStyleSheet(styleButton);
    ui->pb_pen->setStyleSheet(styleButton);
    ui->pb_inline->setStyleSheet(styleButton);
    ui->pb_outline->setStyleSheet(styleButton);
//=============NICE_VEIW=============
    
//=============LABEL_NOW=============    
    _l1.set_l_n(ui->l_now);
    
    connect(ui->pb_pen, &QPushButton::pressed, &_l1, &label_now::pen);
    connect(ui->pb_rect, &QPushButton::pressed, &_l1, &label_now::rect);
    connect(ui->pb_ellipse, &QPushButton::pressed, &_l1, &label_now::ellipse);
    connect(ui->pb_move, &QPushButton::pressed, &_l1, &label_now::move);
    connect(ui->pb_select, &QPushButton::pressed, &_l1, &label_now::select);
    connect(ui->pb_del, &QPushButton::pressed, &_l1, &label_now::del);
    
    connect(_scene, &Scene::move_, &_l1, &label_now::move);
    connect(_scene, &Scene::select_, &_l1, &label_now::select);
    connect(_scene, &Scene::del_, &_l1, &label_now::del);
    connect(_scene, &Scene::not_signal, &_l1, &label_now::not_signal);
    
//=============LABEL_NOW=============    
    
    ui->graphicsView->setScene(_scene);
    _scene->setSceneRect(0, 0, 1000, 900);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    
    connect(_scene, &Scene::mouse_moved, this, &MainWindow::position_on_scene);
}

void MainWindow::position_on_scene(double x, double y)
{
    ui->statusbar->setStyleSheet("color: white;");
    ui->statusbar->showMessage(QString("%1 X %2").arg(x).arg(y));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_inline_clicked()
{
    QColor color = QColorDialog::getColor();
    _scene->set_inline_color(color);
    
    QString c = QString("background: %1;"
                                  "border: 2px solid rgb(85, 85, 85);"
                                 ).arg(color.name());
    
    ui->tv_inline->setStyleSheet(c);
}

void MainWindow::on_pb_outline_clicked()
{
    QColor color = QColorDialog::getColor();
    _scene->set_outline_color(color);
    
    QString c = QString("background: %1;"
                                  "border: 2px solid rgb(85, 85, 85);"
                                 ).arg(color.name());
    
    ui->tv_outline->setStyleSheet(c);
}

void MainWindow::on_pb_pen_clicked()
{
    _scene->set_shape_type(Scene::Line);
}

void MainWindow::on_pb_rect_clicked()
{
    _scene->set_shape_type(Scene::Rect);
}

void MainWindow::on_pb_ellipse_clicked()
{
    _scene->set_shape_type(Scene::Ellipse);
}


