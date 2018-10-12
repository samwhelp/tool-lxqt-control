#!/usr/bin/env bash


g++ -o dataHome main.cpp -fPIC $(pkg-config --cflags --libs Qt5Xdg)
