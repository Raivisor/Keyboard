#include "app_controller.hpp"

sea::AppController::AppController() {
	menu_window = std::make_unique<sea::MenuWindow>();
	keyboard_window = std::make_unique<sea::KeyBoardWindow>();

	connect(menu_window.get(), &sea::MenuWindow::goToKeyboardRequested, this, &sea::AppController::onGoToKeyboardRequested);
}

void sea::AppController::start() {
	menu_window->show();
}

void sea::AppController::onGoToKeyboardRequested() {
	menu_window->hide();
	keyboard_window->show();
}
