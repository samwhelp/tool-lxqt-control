

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
	//qDebug() << "List::run" << endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach (const LXQt::LXQtTheme &theme, themes) {

		if (getIsPlusPath()) {
			out << theme.name() << " : "  << theme.path() << endl;
		} else if (getIsPrintPath()) {
			out << theme.path() << endl;
		} else {
			out << theme.name() << endl;
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

bool List::getIsPlusPath () {
	return _IsPlusPath;
}

List &List::setIsPlusPath (bool val) {
	_IsPlusPath = val;
	return *this;
}

} // namespace LxqtControlTheme
