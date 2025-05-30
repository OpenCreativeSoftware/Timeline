#pragma once

#include <QMainWindow>
#include <QCloseEvent>

namespace OpenCreativeSoftware {
	class MainWindow : public QMainWindow {
		Q_OBJECT
	public:
		MainWindow();

	protected:
		void closeEvent(QCloseEvent* t_event);
	};
};