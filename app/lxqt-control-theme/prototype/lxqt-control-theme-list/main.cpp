

#include <QTextStream>


#include <LXQt/Settings>


int main (int argc, char **argv)
{
	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach(const LXQt::LXQtTheme &theme, themes)
	{
		QString theme_name = theme.name();
		//theme_name[0] = theme_name[0].toTitleCase();
		out << theme_name << Qt::endl;

	}

	return 0;

}
