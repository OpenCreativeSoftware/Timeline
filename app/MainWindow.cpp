#include <QApplication>
#include <QSettings>
#include <QLabel>

#include "MainWindow.h"

namespace OpenCreativeSoftware {
	MainWindow::MainWindow() : QMainWindow() {
		QApplication::setStyle("Fusion");
		auto palette = QApplication::palette();
		palette.setColor(QPalette::ColorRole::Window, QColor(29, 29, 29));
		palette.setColor(QPalette::ColorRole::Highlight, QColor(62, 150, 242));
		palette.setColor(QPalette::ColorRole::Text, QColor(208, 208, 208));
		palette.setColor(QPalette::ColorRole::WindowText, QColor(208, 208, 208));
		QApplication::setPalette(palette);

		QSettings settings("opencreativesoftware.org", "Timeline");
		if (settings.contains("editorWindowGeometry")) {
			restoreGeometry(settings.value("editorWindowGeometry").toByteArray());
		}
		else {
			auto display = QApplication::primaryScreen();
			setGeometry(0, 0, display->availableGeometry().width(), display->availableGeometry().height());
		}
		setWindowState(Qt::WindowMaximized);

		ads::CDockManager::setConfigFlag(ads::CDockManager::DefaultOpaqueConfig);
		ads::CDockManager::setConfigFlag(ads::CDockManager::DockAreaDynamicTabsMenuButtonVisibility);
		ads::CDockManager::setConfigFlag(ads::CDockManager::FocusHighlighting);
		ads::CDockManager::setConfigFlag(ads::CDockManager::AlwaysShowTabs);
		this->m_dockManager = new ads::CDockManager(this);
		auto* dockWidget = new ads::CDockWidget(tr("OCS Timeline"));
		dockWidget->setWidget(new QLabel(tr("Dock Widget")));
		m_dockManager->addDockWidget(ads::CenterDockWidgetArea, dockWidget);
	}

	void MainWindow::closeEvent(QCloseEvent* t_event) {
		QSettings settings("opencreativesoftware.org", "Timeline");
		settings.setValue("editorWindowGeometry", saveGeometry());
		saveState();
		QMainWindow::closeEvent(t_event);
	}
};