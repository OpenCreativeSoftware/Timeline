#include <QApplication>
#include <QDebug>

#include "Timeline.h"
#include "MainWindow.h"

using namespace OpenCreativeSoftware;

int main(int argc, char** argv) {
	QApplication app(argc, argv);
	qDebug() << "Hello, OCS Timeline!";
	app.setOrganizationName("OpenCreativeSoftware");
	app.setOrganizationDomain("opencreativesoftware.org");
	app.setApplicationDisplayName("OCS Timeline");
	app.setApplicationName("Timeline");
#ifdef OCS_TIMELINE_TIMESTAMP
	app.setApplicationVersion(OCS_TIMELINE_TIMESTAMP);
#endif

	MainWindow window;
	window.show();

	return app.exec();
}
