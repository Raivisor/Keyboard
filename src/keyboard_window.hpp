#pragma once

#include <QCloseEvent>
#include <QKeyEvent>
#include <QLineEdit>
#include <QObject>
#include <QWidget>

#include "keyboard.hpp"

namespace sea {
	class KeyBoardWindow : public QWidget {
		Q_OBJECT
		private:
			QLineEdit* display;
			KeyBoard* keyboard;

		public:
			KeyBoardWindow(QWidget* parent = nullptr);
			
		protected:
			void keyPressEvent(QKeyEvent* event) override;
			void closeEvent(QCloseEvent* event) override;

		signals:
			void closed();
	};
}
