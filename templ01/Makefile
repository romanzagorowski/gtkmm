all:
	g++ -Wall -std=c++17 main.cpp `pkg-config --cflags --libs gtkmm-3.0`

pch:
	g++ -std=c++17 -c pch.h `pkg-config --cflags gtkmm-3.0`

clean:
	rm -f a.* pch.h.gch

