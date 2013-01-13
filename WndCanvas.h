#ifndef WNDCANVAS_H
#define WNDCANVAS_H

#include <QGraphicsView>


namespace Ui {
class WndCanvas;
}


//-------------------------------------------------------------------------------------------------
class WndCanvas : public QGraphicsView
{
    Q_OBJECT
    
public:
    explicit WndCanvas(int width, int height, QString title);
    ~WndCanvas();
    
    void setSceneSize(int w, int h);
    void moveTo(double x, double y);
    void drawTo(double x, double y);
    virtual void wheelEvent(QWheelEvent* event);

private:
    Ui::WndCanvas *ui;
    QGraphicsScene m_scene;
    QPoint m_pos;
};

#endif // WNDCANVAS_H
