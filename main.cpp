#include "OgreWidget.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <iostream>

int main(int argc, char **argv)
{
    QApplication qapp(argc, argv);

    /// BEGIN: Qt embedded Ogre
    auto* mainwindow = new QMainWindow();
    auto* label = new QLabel("some text");
    auto* ogrewidget = new OgreWidget();
    ogrewidget->setFixedWidth(800);
    ogrewidget->setFixedHeight(600);

    auto* placeholder = new QWidget();
    auto* layout = new QHBoxLayout(placeholder);
    layout->addWidget(label);
    layout->addWidget(ogrewidget);
    mainwindow->setCentralWidget(placeholder);
    mainwindow->show();
    /// END: Qt embedded Ogre

    qapp.exec();

    return 0;
}
