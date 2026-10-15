#include "app_controller.hpp"

#include <QApplication>

sea::AppController::AppController() {
	menu_window = std::make_unique<sea::MenuWindow>();
	keyboard_window = std::make_unique<sea::KeyBoardWindow>();

	connect(menu_window.get(), &sea::MenuWindow::goToKeyboardRequested, this, &sea::AppController::onGoToKeyboardRequested);
	connect(keyboard_window.get(), &sea::KeyBoardWindow::closed, this, &sea::AppController::onWindowClosed);
}

void sea::AppController::start() {
	menu_window->show();
}

void sea::AppController::onGoToKeyboardRequested() {
	menu_window->hide();
	keyboard_window->show();
}

void sea::AppController::onWindowClosed() {
	QApplication::quit();
}
