CFLAGS=-c	-g	-Wall

all:	mct
	./mct

compil: mct
	make	mct

test:	mct.o	lecture.o
	make	clean
	make	mct.o
	make	lecture.o
	gcc	-o	tes	mct.o	lecture.o
	./tes

mct:
	gcc	-o	mct	mct.o	affichage.o	lecture.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

mct.o:	mct.c	mct.h	constantes.h	lecture.h	affichage.h structures.h
	gcc $(CFLAGS) mct.c

lecture.o:	mct.c	mct.h	constantes.h	lecture.h structures.h
		gcc $(CFLAGS) lecture.c

clean:
	rm	-f	mct
	rm	-f	mct.o
	rm	-f	affichage.o
	rm	-f	lecture.o
