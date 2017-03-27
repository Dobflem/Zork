#include "Timezone.h"
#include "tz90widget.h"
#include <QWidget>
#include <QObject>

#ifndef TZ90_H
#define TZ90_H


class TZ90 : public QObject, public Timezone
{
Q_OBJECT
public:
    tz90widget *widget;
    TZ90():Timezone("Nineties", "nineties.jpg", "map-90s.png", "byebyebye.mp3")
    {
        this->widget = new tz90widget();
        this->setupSignalsAndSlots();
    }

    bool canEnterRoom(Backpack *b);
    QWidget* getTimezoneWidget();

public slots:
    void transparentTokenClicked();
    void clickedToken(bool);

private:
    void setupSignalsAndSlots();
};

#endif // TZ90_H
