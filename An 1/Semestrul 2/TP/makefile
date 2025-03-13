CC = gcc
CFLAGS = -g -Wall -O2

TARGET = client

all: $(TARGET)

$(TARGET):
	$(CC) $(CFLAGS) -c hs_utils.c
	$(CC) $(CFLAGS) -c client.c
	$(CC) $(CFLAGS) -o $(TARGET).x hs_utils.o client.o

clean:
	$(RM) $(TARGET).x