#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <QEvent>
#include <QKeyEvent>
#include <QHash>

class Keyboard
{
public:
    static void update(QEvent *event);
    static void destroy();
    static bool keyPress(Qt::Key key);
    static bool keyRelease(Qt::Key key);
private:
    static QHash<int,int> keys;
    static QEvent *event;
};

#endif // KEYBOARD_H
