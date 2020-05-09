#include "label_now.h"
#include <QIcon>

label_now::label_now(QObject *parent) 
    : QObject(parent)
    , _l_n(nullptr)
{}

void label_now::set_l_n(QLabel *l_n)
{
    _l_n = l_n;
}

void label_now::pen()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/pen.png").pixmap(40,40));
    }
}

void label_now::ellipse()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/ellipse.png").pixmap(40,40));
    }
}

void label_now::rect()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/rect.png").pixmap(40,40));
    }
}

void label_now::move()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/move.png").pixmap(40,40));
    }
}

void label_now::select()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/select.png").pixmap(40,40));
    }
}

void label_now::del()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/del.png").pixmap(40,40));
    }
}

void label_now::not_signal()
{
    if(_l_n)
    {
        _l_n->setPixmap(QIcon(":/pictures/not_signal.png").pixmap(40,40));
    }
}
