

#include <QTextStream>


#include <LXQt/SingleApplication>
#include <LXQt/Settings>


int main (int argc, char **argv)
{
	LXQt::SingleApplication app(argc, argv);

	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	LXQt::Settings *settings = new LXQt::Settings("lxqt");

	QString current_theme = settings->value("theme").toString();

	out << current_theme << endl;

	return 0;

}
