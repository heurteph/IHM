#include "rectangle.h"

Rectangle::Rectangle(QPoint b, QPoint e, Qt::PenStyle s, QColor c, int w)
{
    begin = b;
    end   = e;
    style = s;
    color = c;
    width = w;
}

QPoint Rectangle::getBegin(){
    return begin;
}

QPoint Rectangle::getEnd(){
    return end;
}

Qt::PenStyle Rectangle::getStyle(){
    return style;
}

QColor Rectangle::getColor(){
    return color;
}

int Rectangle::getWidth(){
    return width;
}

void Rectangle::setBegin(QPoint b){
    begin = b;
}

void Rectangle::setEnd(QPoint e){
    end = e;
}

void Rectangle::setStyle(Qt::PenStyle s){
    style = s;
}

void Rectangle::setColor(QColor c){
    color = c;
}

void Rectangle::setWidth(int w){
    width = w;
}
