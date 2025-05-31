#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <DockManager.h>

namespace OpenCreativeSoftware {
	class MainWindow : public QMainWindow {
		Q_OBJECT
	public:
		MainWindow();

	protected:
		void closeEvent(QCloseEvent* t_event);

	private:
		ads::CDockManager* m_dockManager;
	};
};