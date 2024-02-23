

#include <QTextStream>


#include <LXQt/Settings>


int main (int argc, char **argv)
{
	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach(const LXQt::LXQtTheme &theme, themes) {
		out << theme.path() << Qt::endl;
	}

	return 0;

}
