#include "scene.h"

Scene::Scene(QObject *parent) 
    : QGraphicsScene(parent)
    , _shape_type(None)
    , _obj(nullptr)
    , _outline_color(Qt::white)
    , _inline_color(Qt::black)
    , _size_of_line(0)
{}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouse_moved(event->scenePos().x(), event->scenePos().y());
    
    if (get_obj())  
    {
        draw_obj(event, 2);
    
        if (event->button() == Qt::LeftButton) 
          {
            move_obj();  
          }
    }
    
    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (_shape_type != None) 
  {
        if (event->button() == Qt::LeftButton) 
        {
            if (_obj == nullptr) 
            {
                set_start_pos(event->scenePos());
                draw_obj(event, 1);
            }
        }
  } 
  else
  {
      if (event->button() == Qt::LeftButton) 
        {
          select_obj();  
        }  
      if (event->button() == Qt::RightButton) 
        {
            del_obj();
        }
  }
  QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    draw_obj(event, 3);
  QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsScene::mouseDoubleClickEvent(event);
}

void Scene::draw_obj(QGraphicsSceneMouseEvent *event, int action)
{
    switch (_shape_type) {
    case Line:
    {
        draw_line(event, action);
        break;
    }
    case Rect:
    {
        draw_rect(event, action);
        break;
    }
    case Ellipse:
    {
        draw_ellipse(event, action);
        break;
    }
    default:
    {
        break;
    }
    }
}

void Scene::draw_line(QGraphicsSceneMouseEvent *event, int action)
{
    switch (action) {
    case 1:
    {
        //create
        QGraphicsLineItem*obj;
//                = new QGraphicsLineItem(get_start_pos().x(),get_start_pos().y(),0, 0, 
//                                                                                  QPen(get_inline_color(), 
//                                                                                          get_size_of_line(),
//                                                                                          Qt::SolidLine, 
//                                                                                          Qt::RoundCap));
                
        set_obj(obj);
        
        break;
    }
    case 2:
    {
        //recreate
        QPointF p1 = get_start_pos();
        QPointF p2 = event->scenePos();
        
//        QGraphicsLineItem *obj = new QGraphicsLineItem(
        
//        addLine(p1.x(), p1.y(),
//                    p2.x(), p2.y(),
//                    QPen(get_inline_color(), get_size_of_line(),Qt::SolidLine, Qt::RoundCap));
        
        _obj->setFlag(QGraphicsItem::ItemIsSelectable);
        _obj->setFlag(QGraphicsItem::ItemIsMovable);
        
        break;
    }
    case 3:
    {
        //end_of_obj
        if (_obj)  { _obj = nullptr; }
        _shape_type = None;
        not_signal();
    }
    }
}
void Scene::draw_rect(QGraphicsSceneMouseEvent *event, int action)
{
    switch (action) {
    case 1:
    {
        //create
        QGraphicsRectItem *obj = new QGraphicsRectItem(
                                                           get_start_pos().x(),
                                                           get_start_pos().y(),
                                                           0,
                                                           0);
        obj->setBrush(get_outline_color());
        obj->setPen(get_inline_color());
        addItem(obj);
        set_obj(obj);
        
        break;
    }
    case 2:
    {
        //recreate
        QGraphicsRectItem *rect = (QGraphicsRectItem *) _obj;
        
        QPointF p1 = get_start_pos();
        QPointF p2 = event->scenePos();
        
        QRectF new_rect(QPointF(qMin(p1.x(), p2.x()), qMin(p1.y(), p2.y())),
                                QPointF(qMax(p1.x(), p2.x()), qMax(p1.y(), p2.y())));
        rect->setRect(new_rect);
        
        _obj->setFlag(QGraphicsItem::ItemIsSelectable);
        _obj->setFlag(QGraphicsItem::ItemIsMovable);
        
        break;
    }
    case 3:
    {
        //end_of_obj
        if (_obj)  { _obj = nullptr; }
        _shape_type = None;
        not_signal();
    }
    }
}
void Scene::draw_ellipse(QGraphicsSceneMouseEvent *event, int action)
{
    switch (action) {
    case 1:
    {
        //create
        QGraphicsEllipseItem *obj = new QGraphicsEllipseItem(
                                    get_start_pos().x(),
                                    get_start_pos().y(),
                                    0,
                                    0);
        obj->setBrush(get_outline_color());
        obj->setPen(get_inline_color());
        addItem(obj);
        set_obj(obj);
        
        break;
    }
    case 2:
    {
        //recreate
        QGraphicsEllipseItem *ellipse = (QGraphicsEllipseItem *) _obj;
        
        QPointF p1 = get_start_pos();
        QPointF p2 = event->scenePos();
        
        QRectF new_ellipse(QPointF(qMin(p1.x(), p2.x()), qMin(p1.y(), p2.y())),
                                QPointF(qMax(p1.x(), p2.x()), qMax(p1.y(), p2.y())));
        ellipse->setRect(new_ellipse);
        
        _obj->setFlag(QGraphicsItem::ItemIsSelectable);
        _obj->setFlag(QGraphicsItem::ItemIsMovable);
        
        break;
    }
    case 3:
    {
        //end_of_obj
        if (_obj)  { _obj = nullptr; }
        _shape_type = None;
        not_signal();
    }
    }

}

void Scene::move_obj()
{
    move_();
}
void Scene::del_obj()
{
    del_();
    
    if (get_obj()) 
    {
      delete _obj;
      set_obj(nullptr);
    }
}
void Scene::select_obj()
{
    select_();
    
    //set_obj(selectedItems());
}

void Scene::set_shape_type(ShapeType current_shape_type)
{
  _shape_type = current_shape_type;
}
void Scene::set_inline_color(QColor current_color)
{
  _inline_color = current_color;
}
void Scene::set_outline_color(QColor current_color)
{
  _outline_color = current_color;
}
void Scene::set_obj(QGraphicsItem *obj)
{
    _obj = obj;
}
void Scene::set_size_of_line(int size_of_line)
{
    _size_of_line = size_of_line;
}
void Scene::set_start_pos(QPointF start_pos)
{
    _start_pos = start_pos;
}

QColor Scene::get_inline_color()
{
    return _inline_color;
}
QColor Scene::get_outline_color()
{
    return _outline_color;
}
QGraphicsItem * Scene::get_obj()
{
    return _obj;
}
int Scene::get_size_of_line()
{
    return _size_of_line;
}
QPointF Scene::get_start_pos()
{
    return _start_pos;
}
