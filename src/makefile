CC = cl
CFLAGS = /EHsc
SRC = main.c binTree.c
HEADERS = binTree.h
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) /Fe:$(TARGET)

clean:
	del $(TARGET)
