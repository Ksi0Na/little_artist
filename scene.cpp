#include "scene.h"

Scene::Scene(QObject *parent) 
    : QGraphicsScene(parent)
    , _shape_type(None)
    , _current_obj(nullptr)
    , _outline_color(Qt::white)
    , _inline_color(Qt::black)
{}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouse_moved(event->scenePos().x(), event->scenePos().y());
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit mouse_left_clicked(event->scenePos().x(), event->scenePos().y());
    
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
