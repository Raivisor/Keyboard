#include <QApplication>

#include "app_controller.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    sea::AppController app_controller;
    app_controller.start();

    return app.exec();
}
