#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QGraphicsView>
#include "label_now.h"
#include "scene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
public slots:
    void position_on_scene(double x, double y);
    //void draw_obj();
    
private slots:
    void on_pb_inline_clicked();
    void on_pb_outline_clicked();
    
    void on_pb_pen_clicked();
    void on_pb_rect_clicked();
    void on_pb_ellipse_clicked();
    
private:
    Ui::MainWindow *ui;
    label_now _l1;
    Scene *_scene;
};
#endif // MAINWINDOW_H
