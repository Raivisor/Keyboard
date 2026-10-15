#include "menu_window.hpp"

#include <QVBoxLayout>

using sea::MenuWindow;

MenuWindow::MenuWindow(QWidget* parent) : QWidget(parent) {
	resize(1160, 710);
	setWindowTitle("Добро пожаловать в главное меню!");

	QVBoxLayout* main_layout = new QVBoxLayout(this);
	btn = new GoToKeyboardButton(this);

	main_layout->addWidget(btn);
	connect(btn, &QPushButton::clicked, this, &MenuWindow::goToKeyboardRequested);
}
