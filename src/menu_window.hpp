#pragma once

#include "go_to_keyboard_button.hpp"

#include <QWidget>

namespace sea {
	class MenuWindow : public QWidget {
		Q_OBJECT
		private:
			GoToKeyboardButton* btn;
		public:
			MenuWindow(QWidget* parent = nullptr);
		signals:
			void goToKeyboardRequested();
	};
}
