OBJECTS = main.o player.o
CFLAGS = -lncurses
NAME = output

build: $(OBJECTS)
	g++ $(OBJECTS) -o $(NAME) $(CFLAGS)

clean:
	rm -f *.o
	rm -f $(NAME)

run:
	make build -B && echo && ./$(NAME)
