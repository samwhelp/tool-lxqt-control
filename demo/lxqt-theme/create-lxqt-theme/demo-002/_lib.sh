
THE_LXQT_THEMES_DIR_PATH="/usr/local/share/lxqt/themes"
THE_LXQT_THEME_NAME="demo2"
THE_LXQT_THEME_MAIN_FILE_NAME="lxqt-panel.qss"


find_theme_root_dir_path () {
	echo "$THE_LXQT_THEMES_DIR_PATH/$THE_LXQT_THEME_NAME"
}


find_theme_main_file_path () {
	echo "$THE_LXQT_THEMES_DIR_PATH/$THE_LXQT_THEME_NAME/$THE_LXQT_THEME_MAIN_FILE_NAME"
}
