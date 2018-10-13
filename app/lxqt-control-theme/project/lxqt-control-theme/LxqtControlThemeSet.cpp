

#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeSet.h"


namespace LxqtControlTheme {

Set::Set () {

}

Set::~Set () {

}

int Set::run () {
	// http://doc.qt.io/qt-5/qdebug.html
	//qDebug() << "Set::run" << endl;

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);


	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString old_theme_name = settings->value("theme").toString();

	out << "Old: " << old_theme_name << endl;

	settings->setValue("theme", getNewThemeName());

	settings->sync();

	out << "New: " << getNewThemeName() << endl;

	return 0;
}

QString Set::getNewThemeName () {
	if (_NewThemeName.length() == 0) {
		setNewThemeName("ambiance");
	}
	return _NewThemeName;
}

Set &Set::setNewThemeName (QString val) {
	_NewThemeName = val.trimmed();
	return *this;
}


} // namespace LxqtControlTheme
