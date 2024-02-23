

## Build Essential

``` sh
$ sudo apt-get install build-essential
```

``` sh
$ sudo apt-get install liblxqt1-dev
```


## How to build

Create Makefile

``` sh
$ qmake
```

Then

``` sh
$ make
```


## How to test

``` sh
$ ./lxqt-control-theme-set $theme_name
```

ex: theme_name => ambiance <= use [lxqt-control-theme-list](../lxqt-control-theme-list) get theme name.

``` sh
$ ./lxqt-control-theme-set ambiance
```


## More


### [lxqt-config](https://github.com/lxqt/lxqt-config)

* https://github.com/lxqt/lxqt-config/blob/releases-0.12.x/lxqt-config-appearance/lxqtthemeconfig.cpp
* https://github.com/lxqt/lxqt-config/blob/releases-0.12.x/lxqt-config-appearance/lxqtthemeconfig.h


### [liblxqt](https://github.com/lxqt/liblxqt)

* https://github.com/lxqt/liblxqt/blob/releases-0.12.x/lxqtsettings.cpp
* https://github.com/lxqt/liblxqt/blob/releases-0.12.x/lxqtsettings.h


## How to install new lxqt theme

* https://github.com/samwhelp/play-ubuntu-18.04-plan/tree/master/prototype/lxqt-theme


## Config File

``` sh
$ grep '^theme=' ~/.config/lxqt/lxqt.conf
```


## Themes

* https://github.com/lxqt/lxqt/wiki/Theming
