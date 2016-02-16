#include "stroke.h"

Stroke::Stroke(QPoint b, QPoint e, Qt::PenStyle s, QColor c, int w)
{
    begin = b;
    end   = e;
    style = s;
    color = c;
    width = w;
}

QPoint Stroke::getBegin(){
    return begin;
}

QPoint Stroke::getEnd(){
    return end;
}

Qt::PenStyle Stroke::getStyle(){
    return style;
}

QColor Stroke::getColor(){
    return color;
}

int Stroke::getWidth(){
    return width;
}

void Stroke::setBegin(QPoint b){
    begin = b;
}

void Stroke::setEnd(QPoint e){
    end = e;
}

void Stroke::setStyle(Qt::PenStyle s){
    style = s;
}

void Stroke::setColor(QColor c){
    color = c;
}

void Stroke::setWidth(int w){
    width = w;
}
