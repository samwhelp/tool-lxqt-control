

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

	//http://doc.qt.io/qt-5/qactionlineparser.html
	QCommandLineParser parser;
	parser.setApplicationDescription(
		QStringLiteral("LXQt Control Theme")
	);

	parser.addVersionOption();
	parser.addHelpOption();

	//http://doc.qt.io/qt-5/qactionlineparser.html#addPositionalArgument
	//http://doc.qt.io/qt-5/qactionlineparser.html#clearPositionalArguments
	parser.addPositionalArgument(
		"action",
		"The action to execute.\n"
		"\n\n"
		"Actions:\n"
		"list - available themes\n"
		"get - current theme\n"
		"set - new theme\n"
		"\n\n"
		"Examples:\n"
		"$ lxqt-control-theme list\n"
		"$ lxqt-control-theme get\n"
		"$ lxqt-control-theme set ambiance\n"
	);

	QCommandLineOption option_print_path(
		QStringList() << "p" << "print-path",
		"Print path only."
	);
	parser.addOption(option_print_path);

	QCommandLineOption option_append_path(
		QStringList() << "a" << "append-path",
		"Print theme name and path."
	);
	parser.addOption(option_append_path);

	parser.process(app);


	QStringList args = parser.positionalArguments();

	if (args.isEmpty()) {
		out << Qt::endl;
		out << "##" << Qt::endl;
		out << "## ## action needed!" << Qt::endl;
		out << "##" << Qt::endl;
		out << "## Examples: " << Qt::endl;
		out << "##	$ lxqt-control-theme list" << Qt::endl;
		out << "##	$ lxqt-control-theme get" << Qt::endl;
		out << "##	$ lxqt-control-theme set ambiance" << Qt::endl;
		out << "##" << Qt::endl;
		out << Qt::endl;
		//parser.showHelp();
	} else {

		QString action = args.first();
		if (action == "list") {
			//out << "Command: " << action << Qt::endl;
			LxqtControlTheme::List list;
			list
				.setIsAppendPath(parser.isSet("append-path"))
				.setIsPrintPath(parser.isSet("print-path"))
				.run()
			;
		} else if (action == "get") {
			//out << "Command: " << action << Qt::endl;
			LxqtControlTheme::Get get;
			get
				.setIsAppendPath(parser.isSet("append-path"))
				.setIsPrintPath(parser.isSet("print-path"))
				.run()
			;
		} else if (action == "set") {
			if (args.size() < 2) {
				out << Qt::endl;
				out << "##" << Qt::endl;
				out << "## ## theme_name needed!" << Qt::endl;
				out << "##" << Qt::endl;
				out << "## Examples: " << Qt::endl;
				out << "##	$ lxqt-control-theme set ambiance" << Qt::endl;
				out << "##" << Qt::endl;
				out << Qt::endl;
				//parser.showHelp();
			} else {
				//out << "Command: " << action << Qt::endl;
				//out << "ThemeName: " << args.value(1) << Qt::endl;
				LxqtControlTheme::Set set;
				set.setNewThemeName(args.value(1));
				if (LxqtControlTheme::Util::isValidThemeName(set.getNewThemeName()) == false) {
					out << Qt::endl;
					out << "##" << Qt::endl;
					out << "## ## theme_name invalid!" << Qt::endl;
					out << "##" << Qt::endl;
					out << "## Examples: " << Qt::endl;
					out << "##	$ lxqt-control-theme list" << Qt::endl;
					out << "##	$ lxqt-control-theme set ambiance" << Qt::endl;
					out << Qt::endl;
					//parser.showHelp();
				} else {
					set.run();
				}
			}
		} else {
			out << Qt::endl;
			out << "##" << Qt::endl;
			out << "## ## action invalid!" << Qt::endl;
			out << "##" << Qt::endl;
			out << "## Examples: " << Qt::endl;
			out << "##	$ lxqt-control-theme list" << Qt::endl;
			out << "##	$ lxqt-control-theme get" << Qt::endl;
			out << "##	$ lxqt-control-theme set ambiance" << Qt::endl;
			out << "##" << Qt::endl;
			out << Qt::endl;
			//parser.showHelp();
		}

	}

	return 0;

}
