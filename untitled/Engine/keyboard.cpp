#include "keyboard.h"
#include "QDebug"
QEvent *Keyboard::event=0;
QHash<int,int> Keyboard::keys;

void Keyboard::update(QEvent *event)
{
    if(((QKeyEvent*)event)->isAutoRepeat()&&(event->type()==QEvent::KeyRelease))
    {
        ((QKeyEvent*)event)->ignore();
        return;
    }
    Keyboard::event=event;
    Keyboard::keys.insert(((QKeyEvent*)event)->key(),event->type());
}

void Keyboard::destroy()
{
    Keyboard::keys.clear();
}

bool Keyboard::keyPress(Qt::Key key)
{
    if(Keyboard::event!=0)
        if(Keyboard::keys.value(key)==QEvent::KeyPress)
            return true;
    return false;
}

bool Keyboard::keyRelease(Qt::Key key)
{
    if(Keyboard::event!=0)
        if(Keyboard::keys.value(key)==QEvent::KeyRelease)
        {
           Keyboard::keys.remove(key);
           return true;
        }
    return false;
}
