

#include <QTextStream>


#include <LXQt/Settings>


#include "LxqtControlThemeUtil.h"


namespace LxqtControlTheme {

bool Util::isValidThemeName (QString val) {

	const QList<LXQt::LXQtTheme> themes = LXQt::LXQtTheme::allThemes();

	foreach (const LXQt::LXQtTheme &theme, themes) {
		QString theme_name = theme.name();

		if (val == theme_name) {
			return true;
		}
	}

	return false;
}

} // namespace LxqtControlTheme
