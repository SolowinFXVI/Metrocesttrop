CFLAGS=-c	-g	-Wall

all:	mct
	./mct	metro.txt

compil: mct
	make	mct

mct:
	gcc	-o	mct	mct.o	affichage.o	lecture.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

mct.o:	mct.c	mct.h	constantes.h	lecture.h	affichage.h
	gcc $(CFLAGS) mct.c

clean:
	rm	-f	mct
	rm	-f	mct.o
	rm	-f	affichage.o
	rm	-f	lecture.o
