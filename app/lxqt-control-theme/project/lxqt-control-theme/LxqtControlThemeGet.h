#ifndef LXQT_CONTROL_THEME_GET_H
#define LXQT_CONTROL_THEME_GET_H

namespace LxqtControlTheme {

class Get {
public:
	Get ();
	~Get ();
	virtual int run ();
	bool _IsPrintPath = false;
	bool getIsPrintPath ();
	Get &setIsPrintPath (bool val);
	bool _IsAppendPath = false;
	bool getIsAppendPath ();
	Get &setIsAppendPath (bool val);

//protected:

//private:

}; // class Get

} // namespace LxqtControlTheme

#endif // LXQT_CONTROL_THEME_GET_H
