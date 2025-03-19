all:
	g++ -Wall -std=c++17 *.cpp `pkg-config --cflags --libs gtkmm-4.0`

pch:
	g++ -Wall -std=c++17 -c pch.h `pkg-config --cflags gtkmm-4.0`
