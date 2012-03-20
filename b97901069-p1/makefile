CC=g++
EXEC=mysort
bin/mysort: src/main.o src/fileIO.o src/sortfuc.o 
	$(CC) -o bin/mysort src/main.o src/fileIO.o src/sortfuc.o
src/mysort.o: src/main.cpp src/fileIO.h src/sortfuc.h
	$(CC) -O2 -c src/main.cpp
clean:
	rm -rf bin/$(EXEC) src/*.o
