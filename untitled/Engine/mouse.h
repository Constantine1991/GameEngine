#ifndef MOUSE_H
#define MOUSE_H
#include <QEvent>
#include <QMouseEvent>

class Mouse
{
public:
    static int x;
    static int y;
    static void update(QEvent *event);
    static void destroy();
    static bool buttonPress(Qt::MouseButton button);
    static bool buttonRelease(Qt::MouseButton button);
private:
    static QEvent *event;
    static QHash<int,int> button;
};

#endif // MOUSE_H
