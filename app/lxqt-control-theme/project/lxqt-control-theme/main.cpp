

#include <QTextStream>
#include <QCommandLineParser>


#include <LXQt/SingleApplication>

#include "LxqtControlThemeUtil.h"
#include "LxqtControlThemeList.h"
#include "LxqtControlThemeGet.h"
#include "LxqtControlThemeSet.h"


int main (int argc, char **argv)
{
	// http://doc.qt.io/qt-5/qtextstream.html#details
	QTextStream out(stdout);

	LXQt::SingleApplication app(argc, argv);
	app.setApplicationVersion(QStringLiteral("0.1"));

	//http://doc.qt.io/qt-5/qcommandlineparser.html
	QCommandLineParser parser;
	parser.setApplicationDescription(
		QStringLiteral("LXQt Control Theme")
	);

	parser.addVersionOption();
	parser.addHelpOption();

	//http://doc.qt.io/qt-5/qcommandlineparser.html#addPositionalArgument
	//http://doc.qt.io/qt-5/qcommandlineparser.html#clearPositionalArguments
	parser.addPositionalArgument(
		"command",
		"The command to execute.\n"
		"\n\n"
		"Commands:\n"
		"list - available themes\n"
		"get - current theme\n"
		"set - new theme\n"
		"\n\n"
		"Examples:\n"
		"$ lxqt-control-theme list\n"
		"$ lxqt-control-theme get\n"
		"$ lxqt-control-theme set ambiance\n"
	);

	parser.process(app);


	QStringList args = parser.positionalArguments();

	if (args.isEmpty()) {
		out << endl;
		out << "=== command needed! ===" << endl;
		out << endl;
		parser.showHelp();
	} else {

		QString command = args.first();
		if (command == "list") {
			//out << "Command: " << command << endl;
			LxqtControlTheme::List list;
			//list.setIsPlusPath(true);
			//list.setIsPrintPath(true);
			list.run();
		} else if (command == "get") {
			//out << "Command: " << command << endl;
			LxqtControlTheme::Get get;
			//get.setIsPlusPath(true);
			//get.setIsPrintPath(true);
			get.run();
		} else if (command == "set") {
			if (args.size() < 2) {
				out << endl;
				out << "=== theme_name needed! ===" << endl;
				out << endl;
				//parser.showHelp();
			} else {
				//out << "Command: " << command << endl;
				//out << "ThemeName: " << args.value(1) << endl;
				LxqtControlTheme::Set set;
				set.setNewThemeName(args.value(1));
				if (LxqtControlTheme::Util::isValidThemeName(set.getNewThemeName()) == false) {
					out << endl;
					out << "=== theme_name invalid! ===" << endl;
					out << endl;
					//parser.showHelp();
				} else {
					set.run();
				}
			}
		} else {
			out << endl;
			out << "=== command invalid! ===" << endl;
			out << endl;
			parser.showHelp();
		}

	}

	return 0;

}
