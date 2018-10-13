#ifndef LXQT_CONTROL_THEME_LIST_H
#define LXQT_CONTROL_THEME_LIST_H

namespace LxqtControlTheme {

class List {
public:
	List ();
	~List ();
	virtual int run ();
	bool _IsPrintPath = false;
	bool getIsPrintPath ();
	List &setIsPrintPath (bool val);
	bool _IsPlusPath = false;
	bool getIsPlusPath ();
	List &setIsPlusPath (bool val);

//protected:

//private:

}; // class List

} // namespace LxqtControlTheme

#endif // LXQT_CONTROL_THEME_LIST_H
