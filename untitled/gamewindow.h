#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QCoreApplication>
#include <QWindow>
#include <QOpenGLFunctions>
#include <QOpenGLPaintDevice>
#include <QPainter>
#include "keyboard.h"
#include "mouse.h"

class GameWindow : public QWindow,protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit GameWindow(QWindow *parent = 0);
    ~GameWindow();
    virtual void initGameWindow();
    virtual void updateGameWindow();
    virtual void drawGameWindow();
    virtual void destroyGameWindow();
protected:
    bool event(QEvent *event);
    void exposeEvent(QExposeEvent *event);
public:
    bool m_update_pending;
    bool m_animating;

    QOpenGLContext *m_context;
    QOpenGLPaintDevice *m_device;

    virtual void render(QPainter *painter);
    virtual void render();
    virtual void initialize();
    void setAnimating(bool animating);
public slots:
    void renderLater();
    void renderNow();
};

#endif // MAINWINDOW_H
