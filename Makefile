FLAGS = -ansi -Wall -pedantic
CC = gcc

OBJS = utils.o main.o keys.o hexdump.o

k128: $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o k128

main.o: main.c
	$(CC) $(FLAGS) -c main.c

keys.o: keys.c
	$(CC) $(FLAGS) -c keys.c

hexdump.o: hexdump.c
	$(CC) $(FLAGS) -c hexdump.c

utils.o: utils.c
	$(CC) $(FLAGS) -c utils.c

clean:
	rm -rf *~ *.o k128
