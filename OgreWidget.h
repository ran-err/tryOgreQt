#ifndef TRYOGREQT_OGREWIDGET_H
#define TRYOGREQT_OGREWIDGET_H

#include "OgreContext.h"
#include <QWidget>
#include <QPaintEvent>

class OgreWidget : public QWidget
{
    Q_OBJECT
public:
    OgreWidget(QWidget* parent = nullptr);
    ~OgreWidget() override;

protected:
    void paintEvent(QPaintEvent* e) override;

private:
    OgreContext mOgreCtx;
};

#endif //TRYOGREQT_OGREWIDGET_H
