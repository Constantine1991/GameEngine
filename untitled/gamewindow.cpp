#include "gamewindow.h"

GameWindow::GameWindow(QWindow *parent):QWindow(parent)
  , m_update_pending(false)
  , m_animating(false)
  , m_context(0)
  , m_device(0)
{
    this->setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat surface;
    surface.setMajorVersion(2);
    surface.setMinorVersion(0);
    this->setFormat(surface);
    this->setAnimating(true);
}

GameWindow::~GameWindow()
{
}

void GameWindow::initGameWindow()
{}

void GameWindow::updateGameWindow()
{}

void GameWindow::drawGameWindow()
{}

void GameWindow::destroyGameWindow()
{}

void GameWindow::render(QPainter *painter)
{
    Q_UNUSED(painter);
}

void GameWindow::initialize()
{
    this->initGameWindow();
}

void GameWindow::render()
{
    if (!m_device)
    {
        qDebug()<<"NEW";
         m_device = new QOpenGLPaintDevice;
    }
    this->updateGameWindow();
    this->drawGameWindow();
    m_device->setSize(this->size());
    QPainter painter(m_device);
    render(&painter);
}

void GameWindow::renderLater()
{
    if (!m_update_pending) {
        m_update_pending = true;
        QCoreApplication::postEvent(this, new QEvent(QEvent::UpdateRequest));
    }
}

bool GameWindow::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::UpdateRequest:{
        m_update_pending = false;
        renderNow();
        return true;
    }
    case QEvent::KeyPress:{
        Keyboard::update(event);
        return QWindow::event(event);
    }
    case QEvent::KeyRelease:{
        Keyboard::update(event);
        return QWindow::event(event);
    }
    case QEvent::MouseButtonPress:{
        Mouse::update(event);
        return QWindow::event(event);
    }
    case QEvent::MouseButtonRelease:{
        Mouse::update(event);
        return QWindow::event(event);
    }
    case QEvent::MouseMove:{
        Mouse::update(event);
        return QWindow::event(event);
    }
    case QEvent::Close:{
        this->destroyGameWindow();
        return QWindow::event(event);
    }
    default:
        return QWindow::event(event);
    }
}

void GameWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        renderNow();
}

void GameWindow::renderNow()
{
    if (!isExposed())
        return;

    bool needsInitialize = false;

    if (!m_context) {
        m_context = new QOpenGLContext(this);
        m_context->setFormat(requestedFormat());
        m_context->create();

        needsInitialize = true;
        qDebug()<<"NEW CONEX";
    }

    m_context->makeCurrent(this);

    if (needsInitialize) {
        qDebug()<<"NEW Init";
        initializeOpenGLFunctions();
        initialize();
    }

    render();

    m_context->swapBuffers(this);

    if (m_animating)
        renderLater();
}

void GameWindow::setAnimating(bool animating)
{
    m_animating = animating;

    if (animating)
        renderLater();
}
