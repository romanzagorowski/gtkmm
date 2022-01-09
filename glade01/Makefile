all:
	g++ -Wall main.cpp `pkg-config --cflags --libs gtkmm-3.0`

pch:
	g++ -c pch.h `pkg-config --cflags gtkmm-3.0`

clean:
	rm -f a.* pch.h.gch

