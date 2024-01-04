static: compile-static link-static

all: compile link

run: all
	.\main.exe

compile:
	g++ -c main.cpp -I"C:\libraries\SFML-2.6.1\include"

link:
	g++ main.o -o main -L"C:\libraries\SFML-2.6.1\lib" -lsfml-graphics -lsfml-window -lsfml-system

compile-static:
	g++ -c main.cpp -I"C:\libraries\SFML-2.6.1\include" -DSFML_STATIC

link-static:
	g++ main.o -o main -L"C:\libraries\SFML-2.6.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

clean:
	del -f main *.o