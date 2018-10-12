#!/usr/bin/env bash

g++ -o dataDirs main.cpp -fPIC $(pkg-config --cflags --libs Qt5Xdg)
