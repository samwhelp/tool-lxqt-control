#!/usr/bin/env bash


source ./_lib.sh


__main__ () {

	local theme_root_dir_path="$(find_theme_root_dir_path)"

	echo "remove: $theme_root_dir_path"
	rm -rf "$theme_root_dir_path"

}


__main__
