prog: main.cpp lodepng.o imagetext.o
	g++ -o prog main.cpp lodepng.o imagetext.o

lodepng.o: lodepng.hpp lodepng.cpp
	g++ -c lodepng.cpp

imagetext.o: imagetext.cpp imagetext.hpp
	g++ -c imagetext.cpp