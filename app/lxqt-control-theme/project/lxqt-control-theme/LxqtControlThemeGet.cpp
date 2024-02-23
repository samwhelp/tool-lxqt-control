
#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeGet.h"


namespace LxqtControlTheme {

Get::Get () {

}

Get::~Get () {

}

int Get::run () {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "Get::run" << Qt::endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString current_theme_name = settings->value("theme").toString();

	LXQt::LXQtTheme theme(current_theme_name);

	if (getIsAppendPath()) {
		out << theme.name() << " : "  << theme.path() << Qt::endl;
	} else if (getIsPrintPath()) {
		out << theme.path() << Qt::endl;
	} else {
		out << theme.name() << Qt::endl;
	}

	return 0;
}

bool Get::getIsPrintPath () {
	return _IsPrintPath;
}

Get &Get::setIsPrintPath (bool val) {
	_IsPrintPath = val;
	return *this;
}

bool Get::getIsAppendPath () {
	return _IsAppendPath;
}

Get &Get::setIsAppendPath (bool val) {
	_IsAppendPath = val;
	return *this;
}

} // namespace LxqtControlTheme
