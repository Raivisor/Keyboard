#pragma once

#include "keyboard_window.hpp"
#include "menu_window.hpp"

#include <memory>
#include <QObject>

namespace sea {
	class AppController : public QObject {
		Q_OBJECT
		private:
			std::unique_ptr<KeyBoardWindow> keyboard_window;
			std::unique_ptr<MenuWindow> menu_window;
		public:
			AppController();

			void start();
		private slots:
			void onGoToKeyboardRequested();
			void onWindowClosed();
	};
}
