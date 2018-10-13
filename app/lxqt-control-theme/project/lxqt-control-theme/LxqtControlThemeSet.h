#ifndef LXQT_CONTROL_THEME_SET_H
#define LXQT_CONTROL_THEME_SET_H

namespace LxqtControlTheme {

class Set {
public:
	Set ();
	~Set ();
	virtual int run ();
	QString _NewThemeName;
	QString getNewThemeName ();
	Set &setNewThemeName (QString val);


//protected:

//private:

}; // class Set

} // namespace LxqtControlTheme

#endif // LXQT_CONTROL_THEME_SET_H
