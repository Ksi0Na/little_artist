#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>

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
    
    void set_shape_type(ShapeType shape_type);
    void set_inline_color(QColor inline_color);
    void set_outline_color(QColor outline_color);
    void set_obj(QGraphicsItem *obj);
    void set_size_of_line(int size_of_line);
    void set_start_pos(QPointF start_pos);
    
    QColor get_inline_color();
    QColor get_outline_color();
    QGraphicsItem * get_obj();
    int get_size_of_line();
    QPointF get_start_pos();
    
    void draw_obj(QGraphicsSceneMouseEvent *event, int action);
    void draw_line(QGraphicsSceneMouseEvent *event, int action);
    void draw_rect(QGraphicsSceneMouseEvent *event, int action);
    void draw_ellipse(QGraphicsSceneMouseEvent *event, int action);
    
    void move_obj();
    void del_obj();
    void select_obj();
    
signals:
    void mouse_moved(double x, double y);
    void move_();
    void del_();
    void select_();
    void not_signal();
    
private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    
private:
    ShapeType _shape_type;
    QGraphicsItem *_obj; 
    QColor _outline_color;
    QColor _inline_color;
    QPointF _start_pos;
    int _size_of_line;
};

#endif // SCENE_H
