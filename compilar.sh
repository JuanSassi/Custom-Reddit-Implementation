#!/bin/bash

g++ -o CustomReddit src/*.cpp -Iinclude $(pkg-config --cflags --libs opencv4)
./CustomReddit