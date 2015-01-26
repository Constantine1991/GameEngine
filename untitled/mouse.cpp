#include "mouse.h"
#include "QDebug"
QEvent *Mouse::event=0;
QHash<int,int> Mouse::button;
int Mouse::x=0;
int Mouse::y=0;

void Mouse::update(QEvent *event)
{
    Mouse::event=event;
    Mouse::x=((QMouseEvent*)event)->x();
    Mouse::y=((QMouseEvent*)event)->y();
    if(Mouse::button.value(((QMouseEvent*)event)->button())==QEvent::MouseButtonRelease)
        return;
    if(event->type()==QEvent::MouseMove)
        return;
    Mouse::button.insert(((QMouseEvent*)event)->button(),event->type());
}

bool Mouse::buttonPress(Qt::MouseButton button)
{
    if(Mouse::event!=0)
        if(Mouse::button.value(button)==QEvent::MouseButtonPress)
            return true;
    return false;
}

bool Mouse::buttonRelease(Qt::MouseButton button)
{
    if(Mouse::event!=0)
        if(Mouse::button.value(button)==QEvent::MouseButtonRelease)
        {
            Mouse::button.remove(button);
            return true;
        }
    return false;
}
