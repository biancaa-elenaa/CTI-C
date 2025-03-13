CC = gcc

CFLAGS = -g -Wall -O3

TARGET = test


all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c biblioteca.c
	$(CC) $(CFLAGS) -c test.c
	$(CC) $(CFLAGS) -o $(TARGET).x biblioteca.o test.o

clean:
	$(RM) $(TARGET).x
