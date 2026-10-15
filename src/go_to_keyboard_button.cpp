#include "go_to_keyboard_button.hpp"

using sea::GoToKeyboardButton;

GoToKeyboardButton::GoToKeyboardButton(QWidget* parent)
	: QPushButton(parent) {
		setFont(QFont("Roboto", 20));
		setText("Перейти к клавиатуре");
}
