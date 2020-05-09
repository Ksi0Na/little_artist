#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    Scene(QObject *parent = nullptr);

    enum ShapeType 
    {
        None,
        Line,
        Rect,
        Ellipse
    };
    
    void set_shape_type(ShapeType current_shape_type);
    void set_inline_color(QColor current_color);
    void set_outline_color(QColor current_color);
    
signals:
    void mouse_moved(double x, double y);
    void mouse_left_clicked(double x, double y);
    
private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    ShapeType _shape_type;
    QGraphicsItem *_current_obj; // Если null - ничего не делать,  // если !null - изменяем размер в mouseMoveEvent
    QColor _outline_color;
    QColor _inline_color;
};

#endif // SCENE_H
