#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QLayout>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>
#include <QColor>
#include <QStyle>
#include <QAction>

#include <iostream>

#include "stroke.h"
#include "rectangle.h"
#include "ellipse.h"

enum Form{t_Stroke, t_Rectangle, t_Ellipse};


class zoneDessin : public QWidget
{
Q_OBJECT

private:
    Qt::PenStyle style;
    QColor color;
    int width;

    Form form;
    std::list<Stroke*> lines;
    std::list<Rectangle*> rectangles;
    std::list<Ellipse*> ellipses;

protected:
    void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

public:
    zoneDessin(QWidget * parent = 0);
    void setPenStyle(Qt::PenStyle);
    void setPenColor(QColor);
    void setPenWidth(int);
    void eraseAll();
    void eraseLast();
    void setForm(Form);
};

#endif // ZONEDESSIN_H
