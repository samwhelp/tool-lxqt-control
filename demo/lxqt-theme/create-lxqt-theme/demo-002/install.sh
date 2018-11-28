#!/usr/bin/env bash


source ./_lib.sh


__main__ () {

	local theme_root_dir_path="$(find_theme_root_dir_path)"
	local theme_main_file_path="$(find_theme_main_file_path)"

	echo "create_dir: $theme_root_dir_path"
	sudo mkdir -p "$theme_root_dir_path"

	echo "create_file: $theme_main_file_path"
	sudo touch "$theme_main_file_path"

	echo "please launch: "
	echo "$ lxqt-config-appearance"

}


__main__
