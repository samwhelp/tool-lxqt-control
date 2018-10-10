
#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeGet.h"


namespace LxqtControlTheme {

Get::Get() {

}

Get::~Get() {

}

int Get::run() {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "Get::run" << endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString current_theme = settings->value("theme").toString();

	out << current_theme << endl;

	return 0;
}

} // namespace LxqtControlTheme
