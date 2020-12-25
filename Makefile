CFLAGS = -std=c89 -pedantic
TARGET = citta

all: $(TARGET)
clean: 
	rm -f *.o $(TARGET) *~
