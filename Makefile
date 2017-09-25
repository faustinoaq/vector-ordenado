CC=clang -Wall
TARGET=vector_ordenado

compile:
	$(CC) $(TARGET).c -o $(TARGET) && ./$(TARGET)