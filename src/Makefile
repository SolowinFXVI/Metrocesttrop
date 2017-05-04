CFLAGS=-c	-g	-Wall

all:	mct
	./mct

compil: mct
	make	mct

test:	mct.o	lecture.o	dijkstra.o
	make	clean
	make	mct.o
	make	lecture.o
	make	dijkstra.o
	gcc	-o	tes	mct.o	lecture.o	dijkstra.o
	./tes

mct:
	gcc	-o	mct	mct.o	affichage.o	lecture.o -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

mct.o:	mct.c	mct.h	constantes.h	lecture.h	affichage.h structures.h dijkstra.c dijkstra.h
	gcc $(CFLAGS) mct.c

lecture.o:	mct.c	mct.h	constantes.h	lecture.h structures.h dijkstra.c dijkstra.h
		gcc $(CFLAGS) lecture.c

dijkstra.o:	mct.c mct.h constantes.h lecture.h structures.h dijkstra.c dijkstra.h
		gcc $(CFLAGS)	dijkstra.c

clean:
	rm	-f	mct
	rm	-f	mct.o
	rm	-f	affichage.o
	rm	-f	lecture.o
	rm	-f	dijkstra.o
