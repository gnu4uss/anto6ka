finaly: main.o
	g++ -g -o $@ $^
clean:
	rm -f finaly *.o

