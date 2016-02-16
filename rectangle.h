#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include <QStyle>
#include <QColor>

class Rectangle
{
private:
    QPoint begin;
    QPoint end;
    Qt::PenStyle style;
    QColor color;
    int width;

public:
    Rectangle(QPoint,QPoint,Qt::PenStyle,QColor,int);

    QPoint getBegin();
    QPoint getEnd();
    Qt::PenStyle getStyle();
    QColor getColor();
    int getWidth();

    void setBegin(QPoint);
    void setEnd(QPoint);
    void setStyle(Qt::PenStyle);
    void setColor(QColor);
    void setWidth(int);
};

#endif // RECTANGLE_H
