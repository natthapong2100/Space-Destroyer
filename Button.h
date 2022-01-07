#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>

class Button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
private:
    QGraphicsTextItem * text;
public:
    Button(QString name, QGraphicsItem * parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    // place mouse cursor approach to button (have the enter, leave)
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);

signals:
    void clicked();
};
#endif // BUTTON_H
