

#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeList.h"


namespace LxqtControlTheme {

List::List() {

}

List::~List() {

}

int List::run() {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "List::run" << endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach(const LXQt::LXQtTheme &theme, themes) {
		QString theme_name = theme.name();
		//theme_name[0] = theme_name[0].toTitleCase();
		out << theme_name << endl;

	}


	return 0;
}

} // namespace LxqtControlTheme
