#include "Timezone.h"
#include "tz40widget.h"
#include <QWidget>

#ifndef TZ40_H
#define TZ40_H


class TZ40 : public Timezone
{
public:
    tz40Widget *widget;
    TZ40(QString description, QString image):Timezone(description, image)
    {
        widget = new tz40Widget();
        // Don't need to do anything
    }

    bool canEnterRoom();
    QWidget* getTimezoneWidget();
};

#endif // TZ40_H
