#include <XdgDirs>
#include <QDebug>

int main(int argc, char **argv)
{
	QTextStream out(stdout);

	foreach (const QString &dir, XdgDirs::dataDirs()) {
		//qDebug() << dir;
		out << dir << endl;
	}
	return 0;
}
