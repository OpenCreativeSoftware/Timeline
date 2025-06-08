#pragma once

#include <QMainWindow>
#include <QCloseEvent>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>

#include <DockManager.h>

#include "widget/home/Home.h"

namespace OpenCreativeSoftware {
	class MainWindow : public QMainWindow {
		Q_OBJECT
	public:
		MainWindow();

	public slots:
		void OpenNewProjectSetup();
		void OpenHomeWidget();
		void ExitAction();

	protected:
		void closeEvent(QCloseEvent* t_event);
		void createActions();
		void createMenus();
		void createToolbars();

	private:
		ads::CDockManager* m_dockManager;
		HomeWidget* m_homeWidget;

		QMenu* m_fileMenu;

		QToolBar* m_mainToolBar;

		QAction* m_newProjectAction;
		QAction* m_homeAction;
		QAction* m_exitAction;
	};
};