

#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeList.h"


namespace LxqtControlTheme {

List::List () {

}

List::~List () {

}

int List::run () {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "List::run" << Qt::endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach (const LXQt::LXQtTheme &theme, themes) {

		if (getIsAppendPath()) {
			out << theme.name() << " : "  << theme.path() << Qt::endl;
		} else if (getIsPrintPath()) {
			out << theme.path() << Qt::endl;
		} else {
			out << theme.name() << Qt::endl;
		}

	}


	return 0;
}

bool List::getIsPrintPath () {
	return _IsPrintPath;
}

List &List::setIsPrintPath (bool val) {
	_IsPrintPath = val;
	return *this;
}

bool List::getIsAppendPath () {
	return _IsAppendPath;
}

List &List::setIsAppendPath (bool val) {
	_IsAppendPath = val;
	return *this;
}

} // namespace LxqtControlTheme
