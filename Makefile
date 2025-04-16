CXXFLAGS = -g # Debug
finaly: main.o array_info.o
	g++ $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o finaly
