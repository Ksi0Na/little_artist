#ifndef LABEL_NOW_H
#define LABEL_NOW_H

#include <QObject>
#include <QLabel>

class label_now : public QObject
{
    Q_OBJECT
public:
    explicit label_now(QObject *parent = nullptr);
    
    void set_l_n(QLabel *l_n);
    
public slots:
    void pen();
    void ellipse();
    void rect();
    void move();
    void select();
    void del();
    void not_signal();
    
private:
     QLabel *_l_n;
};

#endif // LABEL_NOW_H
