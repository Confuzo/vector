#PROJETO EDB

PROG = driver_vector
CC = g++
CPPFLAGS = -O0 -g -std=c++11
OBJS = driver_vector.o
HEADER1 = ./include/vector.h
SRC_DIR     = ./src/
BIN_DIR     = ./bin/

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)
	mv *.o $(PROG) $(BIN_DIR)

driver_vector.o: $(HEADER1)
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)driver_vector.cpp

clean:
	rm -f $(BIN_DIR)*.o $(PROG)