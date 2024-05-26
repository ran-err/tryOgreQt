#include "OgreWidget.h"

#include <iostream>

OgreWidget::OgreWidget(QWidget* parent) : QWidget(parent)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NativeWindow);
    setAttribute(Qt::WA_PaintOnScreen);
}

OgreWidget::~OgreWidget()
{

}

void OgreWidget::paintEvent(QPaintEvent* e)
{
    if (!mOgreCtx.getRoot()) {
        try
        {
            mOgreCtx.injectMainWindow(windowHandle());
            mOgreCtx.initApp();
            mOgreCtx.getRoot()->startRendering();
        }
        catch (const std::exception& e) {
            std::cerr << "Error occurred during execution: " << e.what() << '\n';
            return;
        }
        show();
    }

    // mOgreCtx.getRoot()->renderOneFrame();
}


