#include "keyboard_window.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>

using sea::KeyBoardWindow;

KeyBoardWindow::KeyBoardWindow(QWidget* parent) : QWidget(parent) {
	const int keyboard_width = 1160;
	resize(keyboard_width, 710);
    setWindowTitle("Грустная Клавиатура");
	
	QPixmap pixmap("img/grustnii-smail.png");
	QLabel* image = new QLabel(this);
	image->setFixedSize(200, 200);
	image->setPixmap(pixmap);
	image->setScaledContents(true);
	
	QHBoxLayout* smail_layout = new QHBoxLayout();
	smail_layout->addWidget(image);

    display = new QLineEdit();
	display->setMinimumHeight(80);
	display->setFont(QFont("Roboto", 40));
    display->setReadOnly(true);
	display->setText("Помоги мне заработать лучше...");

	keyboard = new KeyBoard(keyboard_width);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
	main_layout->addLayout(smail_layout);
    main_layout->addWidget(display);
    main_layout->addWidget(keyboard);

    connect(keyboard, &KeyBoard::keyboardButtonPressed, this, &KeyBoardWindow::onKeyboardButtonPressed);
}

void KeyBoardWindow::keyPressEvent(QKeyEvent* event) {
	const int code  = event->key();
	handleInput(code);
	QWidget::keyPressEvent(event);
}

void KeyBoardWindow::onKeyboardButtonPressed(int code) {
	handleInput(code);
}

void KeyBoardWindow::closeEvent(QCloseEvent* event) {
	emit closed();
	QWidget::closeEvent(event);
}

void KeyBoardWindow::handleInput(int code) {
	if(keyboard->is_key_allowed(code)) {
		display->setText(display->text() + keyboard->get_key_text(code));
		keyboard->animate_button(code);
	}
}
