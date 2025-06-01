#include <QApplication>
#include <QSettings>
#include <QLabel>
#include <QFile>
#include <Qt-Advanced-Docking-System/src/IconProvider.h>

#include "MainWindow.h"
#include "FontAwesome.h"

static void initResources() {
	Q_INIT_RESOURCE(style);
}

namespace OpenCreativeSoftware {
	MainWindow::MainWindow() : QMainWindow() {
		QApplication::setStyle("Fusion");
		auto palette = QApplication::palette();
		palette.setColor(QPalette::ColorRole::Window, QColor(29, 29, 29));
		palette.setColor(QPalette::ColorRole::Highlight, QColor(62, 150, 242));
		palette.setColor(QPalette::ColorRole::Text, QColor(208, 208, 208));
		palette.setColor(QPalette::ColorRole::WindowText, QColor(176, 176, 176));
		palette.setColor(QPalette::ColorRole::Accent, QColor(62, 150, 242));
		palette.setColor(QPalette::ColorRole::Light, QColor(208, 208, 208));
		QApplication::setPalette(palette);
		initResources();

		QFile uiStyleSheetFile(":ocs/ui.css");
		uiStyleSheetFile.open(QIODevice::ReadOnly);
		QTextStream uiStyleSheetStream(&uiStyleSheetFile);
		QString uiStyleSheet = uiStyleSheetStream.readAll();
		setStyleSheet(uiStyleSheet);
		uiStyleSheetFile.close();

		QSettings settings("opencreativesoftware.org", "Timeline");
		if (settings.contains("editorWindowGeometry")) {
			restoreGeometry(settings.value("editorWindowGeometry").toByteArray());
		}
		else {
			auto display = QApplication::primaryScreen();
			setGeometry(0, 0, display->availableGeometry().width(), display->availableGeometry().height());
		}
		setWindowState(Qt::WindowMaximized);

		FontAwesome::s_instance = new QtAwesome(this);
		FontAwesome::s_instance->initFontAwesome();

		ads::CDockManager::setConfigFlag(ads::CDockManager::DefaultOpaqueConfig);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaDynamicTabsMenuButtonVisibility);
		ads::CDockManager::setConfigFlag(ads::CDockManager::FocusHighlighting);
		ads::CDockManager::setConfigFlag(ads::CDockManager::AlwaysShowTabs);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHasCloseButton, false);
		ads::CDockManager::setConfigFlag(ads::CDockManager::AllTabsHaveCloseButton, true);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaHasUndockButton, false);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaDynamicTabsMenuButtonVisibility, true);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DisableTabTextEliding, true);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DoubleClickUndocksWidget, false);

		ads::CDockManager::iconProvider().registerCustomIcon(ads::eIcon::TabCloseIcon, FontAwesome::s_instance->icon(fa_solid, fa_xmark));
		ads::CDockManager::iconProvider().registerCustomIcon(ads::eIcon::DockAreaMenuIcon, FontAwesome::s_instance->icon(fa_solid, fa_list));

		this->m_dockManager = new ads::CDockManager(this);
		QFile dockingStyleSheetFile(":ocs/docking.css");
		dockingStyleSheetFile.open(QIODevice::ReadOnly);
		QTextStream dockingStyleSheetStream(&dockingStyleSheetFile);
		QString dockingStyleSheet = dockingStyleSheetStream.readAll();
		m_dockManager->setStyleSheet(dockingStyleSheet);
		dockingStyleSheetFile.close();

		ads::CDockWidget* centralDockWidget = new ads::CDockWidget("Central Widget");
		centralDockWidget->setWidget(new QWidget(this));
		centralDockWidget->setFeature(ads::CDockWidget::NoTab, true);
		auto* CentralDockArea = m_dockManager->setCentralWidget(centralDockWidget);

		auto* dockWidget = new ads::CDockWidget(tr("OCS Timeline"));
		dockWidget->setWidget(new QLabel(tr("Dock Widget")));
		m_dockManager->addDockWidget(ads::CenterDockWidgetArea, dockWidget);

		this->m_homeWidget = new HomeWidget(this);

		createActions();
		createMenus();
		createToolbars();

		setUnifiedTitleAndToolBarOnMac(true);
		setAutoFillBackground(true);
	}

	void MainWindow::OpenHomeWidget() {
		m_homeWidget->show();
	}

	void MainWindow::ExitAction() {
		QApplication::quit();
	}

	void MainWindow::createActions() {
		m_homeAction = new QAction(tr("Home"), this);
		m_homeAction->setIcon(FontAwesome::s_instance->icon(fa_solid, fa_home));
		connect(m_homeAction, &QAction::triggered, this, &MainWindow::OpenHomeWidget);

		m_exitAction = new QAction(tr("Exit"), this);
		m_exitAction->setShortcuts(QKeySequence::Quit);
		connect(m_exitAction, &QAction::triggered, this, &MainWindow::ExitAction);
	}

	void MainWindow::createMenus() {
		menuBar()->setNativeMenuBar(true);
		m_fileMenu = menuBar()->addMenu(tr("File"));
		m_fileMenu->addSeparator();
		m_fileMenu->addAction(m_homeAction);
		m_fileMenu->addSeparator();
		m_fileMenu->addAction(m_exitAction);
	}

	void MainWindow::createToolbars() {
		m_mainToolBar = addToolBar(tr("Timeline ToolBar"));
		m_mainToolBar->addAction(m_homeAction);
	}

	void MainWindow::closeEvent(QCloseEvent* t_event) {
		QSettings settings("opencreativesoftware.org", "Timeline");
		settings.setValue("editorWindowGeometry", saveGeometry());
		saveState();
		QMainWindow::closeEvent(t_event);
	}
};