

#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeSet.h"


namespace LxqtControlTheme {

Set::Set() {

}

Set::~Set() {

}

int Set::run() {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "Set::run" << endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);


	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString old_theme = settings->value("theme").toString();

	out << "Old: " << old_theme << endl;

	//QString new_theme = "ambiance";
	new_theme = new_theme.trimmed();
	if (new_theme.length() == 0) {
		new_theme = "ambiance";
	}

	settings->setValue("theme", new_theme);

	settings->sync();

	out << "New: " << new_theme << endl;

	return 0;
}

bool Set::isValidThemeName (QString theme_name) {

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach (const LXQt::LXQtTheme &theme, themes) {
		QString the_name = theme.name();

		if (theme_name == the_name) {
			return true;
		}
	}

	return false;
}

} // namespace LxqtControlTheme
