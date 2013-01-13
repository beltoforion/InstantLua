#include "WndCanvas.h"
#include "ui_wndcanvas.h"

#include <QGraphicsEllipseItem>
#include <QWheelEvent>
#include <QDebug>

//-------------------------------------------------------------------------------------------------
WndCanvas::WndCanvas(int width, int height, QString title)
    :QGraphicsView((QWidget*)0)
    ,ui(new Ui::WndCanvas)
    ,m_pos(0,0)
{
    ui->setupUi(this);

    setWindowTitle(title);
    setScene(&m_scene);
    setBackgroundBrush(QBrush(Qt::white));
    setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);

    setMinimumSize(400, 400);
    setSceneSize(width, height);
}

//-------------------------------------------------------------------------------------------------
WndCanvas::~WndCanvas()
{
    delete ui;
}

//-------------------------------------------------------------------------------------------------
void WndCanvas::setSceneSize(int w, int h)
{
    resize(w + 2*geometry().x() + 5, h + geometry().y() + 5);

    m_scene.setSceneRect(0, 0, w, h);
    QGraphicsEllipseItem *pEllipse = new QGraphicsEllipseItem(NULL, &m_scene);
    pEllipse->setRect(0,0,w,h);
}

//-----------------------------------------------------------------------------
void WndCanvas::moveTo(double x, double y)
{
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::drawTo(double x, double y)
{
    QGraphicsLineItem *pLine = new QGraphicsLineItem(NULL, &m_scene);
    pLine->setLine(m_pos.x(), m_pos.y(), x, y);
    m_pos = QPoint(x, y);
}

//-----------------------------------------------------------------------------
void WndCanvas::wheelEvent(QWheelEvent* event)
{
    QTransform t = transform();
    qDebug() << "m11=" << t.m11() << "; m22=" << t.m22();
    qDebug() << "scene_width=" << m_scene.width() << "; scene_height=" << m_scene.height();
    qDebug() << "width=" << geometry().width() << "; height=" << geometry().height();

    double fx = (event->delta() > 0) ? 1.1 : 1.0/1.1,
           fy = fx;

/*
    if (t.m11()*m_scene.width()<geometry().width())
        fx = 1;

    if (t.m22()*m_scene.height()<geometry().height())
        fy = 1;
*/

    scale(fx, fy);
}
