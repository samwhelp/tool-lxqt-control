#include <XdgDirs>
#include <QDebug>

int main(int argc, char **argv)
{
	qDebug() << XdgDirs::dataHome(false);
	return 0;
}
