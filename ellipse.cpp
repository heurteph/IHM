#include "ellipse.h"

Ellipse::Ellipse(QPoint b, QPoint e, Qt::PenStyle s, QColor c, int w)
{
    begin = b;
    end   = e;
    style = s;
    color = c;
    width = w;
}

QPoint Ellipse::getBegin(){
    return begin;
}

QPoint Ellipse::getEnd(){
    return end;
}

Qt::PenStyle Ellipse::getStyle(){
    return style;
}

QColor Ellipse::getColor(){
    return color;
}

int Ellipse::getWidth(){
    return width;
}

void Ellipse::setBegin(QPoint b){
    begin = b;
}

void Ellipse::setEnd(QPoint e){
    end = e;
}

void Ellipse::setStyle(Qt::PenStyle s){
    style = s;
}

void Ellipse::setColor(QColor c){
    color = c;
}

void Ellipse::setWidth(int w){
    width = w;
}
