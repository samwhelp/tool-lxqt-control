

#include <QTextStream>


#include <LXQt/SingleApplication>
#include <LXQt/Settings>


int main (int argc, char **argv)
{
	LXQt::SingleApplication app(argc, argv);

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	if (argc < 2) {
		out << "Must assign theme name!" << Qt::endl;
		return 1;
	}

	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString old_theme = settings->value("theme").toString();

	out << "Old: " << old_theme << Qt::endl;

	QString new_theme = "ambiance";

	new_theme = argv[1];

	settings->setValue("theme", new_theme);

	settings->sync();

	out << "New: " << new_theme << Qt::endl;

	return 0;

}
