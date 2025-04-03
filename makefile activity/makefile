CC = gcc
CFLAGS = -Wall -ansi -pedantic
OBJ = main.o game.o map.o setup.o
EXEC = play

ifdef BORDERLESS
CFLAGS += -DBORDERLESS
endif

$(EXEC) : $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

main.o : main.c setup.h
	$(CC) $(CFLAGS) main.c -c

game.o : game.c game.h map.h macros.h
	$(CC) $(CFLAGS) game.c -c

setup.o : setup.c setup.h game.h map.h macros.h
	$(CC) $(CFLAGS) setup.c -c

map.o : map.c map.h macros.h
	$(CC) $(CFLAGS) map.c -c

clean :
	rm -f $(EXEC) $(OBJ)
