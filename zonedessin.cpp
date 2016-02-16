#include "zonedessin.h"

zoneDessin::zoneDessin(QWidget *parent)
{
    //default style
    style = Qt::SolidLine;
    color = QColor("black");
    width = 1;
    form = t_Stroke;

    setMinimumSize(QSize(400,400));
}


void zoneDessin::paintEvent(QPaintEvent *){
    QPen pen;
    QPainter painter(this);

    for(std::list<Stroke*>::iterator it = lines.begin(); it != lines.end(); ++it){

        pen.setStyle((*it)->getStyle());
        pen.setColor((*it)->getColor());
        pen.setWidth((*it)->getWidth());
        painter.setPen(pen);
        painter.drawLine((*it)->getBegin(),(*it)->getEnd());
    }

    for(std::list<Rectangle*>::iterator it = rectangles.begin(); it != rectangles.end(); ++it){

        pen.setStyle((*it)->getStyle());
        pen.setColor((*it)->getColor());
        pen.setWidth((*it)->getWidth());
        painter.setPen(pen);

        QPainterPath painterPath;
        painterPath.addRect(((*it)->getBegin()).x(),
                            ((*it)->getBegin()).y(),
                            ((*it)->getEnd()).x() - ((*it)->getBegin()).x(),
                            ((*it)->getEnd()).y() - ((*it)->getBegin()).y());
        painter.drawPath(painterPath);
    }
    for(std::list<Ellipse*>::iterator it = ellipses.begin(); it != ellipses.end(); ++it){

        pen.setStyle((*it)->getStyle());
        pen.setColor((*it)->getColor());
        pen.setWidth((*it)->getWidth());
        painter.setPen(pen);

        QPainterPath painterPath;
        painterPath.addEllipse(((*it)->getBegin()).x(),
                              ((*it)->getBegin()).y(),
                              ((*it)->getEnd()).x() - ((*it)->getBegin()).x(),
                              ((*it)->getEnd()).y() - ((*it)->getBegin()).y());
        painter.drawPath(painterPath);
    }
}


/* Mouse */


void zoneDessin::mousePressEvent(QMouseEvent * e){
    if(e->button() == Qt::LeftButton){
        if(form == t_Stroke){
            Stroke * stroke = new Stroke(e->pos(),e->pos(),style,color,width);
            lines.push_back(stroke);
        }
        else if(form == t_Rectangle){
            Rectangle * rectangle = new Rectangle(e->pos(),e->pos(),style,color,width);
            rectangles.push_back(rectangle);
        }
        else if(form == t_Ellipse){
            Ellipse * ellipse = new Ellipse(e->pos(),e->pos(),style,color,width);
            ellipses.push_back(ellipse);
        }
        update();
    }
}

void zoneDessin::mouseReleaseEvent(QMouseEvent * e){
    if(e->button() == Qt::LeftButton){
        if(form == t_Stroke){
            Stroke * stroke = lines.back();
            stroke->setEnd(e->pos());
        }
        else if(form == t_Rectangle){
            Rectangle * rectangle = rectangles.back();
            rectangle->setEnd(e->pos());
        }
        else if(form == t_Ellipse){
            Ellipse * ellipse = ellipses.back();
            ellipse->setEnd(e->pos());
        }
        update();
    }
}

void zoneDessin::mouseMoveEvent(QMouseEvent * e){
    if(form == t_Stroke){
        Stroke * stroke = lines.back();
        stroke->setEnd(e->pos());
    }
    else if(form == t_Rectangle){
        Rectangle * rectangle = rectangles.back();
        rectangle->setEnd(e->pos());
    }
    else if(form == t_Ellipse){
        Ellipse * ellipse = ellipses.back();
        ellipse->setEnd(e->pos());
    }
    update();
}


/* Style, Color, Width */


void zoneDessin::setPenStyle(Qt::PenStyle s){
    style = s;
    update(); //inutile
}

void zoneDessin::setPenColor(QColor c){
    color = c;
    update(); //inutile
}

void zoneDessin::setPenWidth(int w){
    width = w;
    update(); //inutile
}


/* Erasing options */

void zoneDessin::eraseAll(){
    lines.clear();
    update();
}

void zoneDessin::eraseLast(){
    if(!lines.empty()){
        lines.pop_back();
        update();
    }
}

/* Forms */

void zoneDessin::setForm(Form f){
    form = f;
    update(); //inutile
}
