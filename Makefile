CC=clang
CFILES=main.c menu.c calculations.c
OBJECTS=main.o menu.o calculations.o

output: $(OBJECTS)
	$(CC) $(OBJECTS) -o output

%.o: %.c
	$(CC) -c $(CFILES)

clean:
	rm $(OBJECTS) output
