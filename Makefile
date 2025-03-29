CXXFLAGS = -g # Debug
finaly: main.o dz1.cpp
	g++ $(CXXFLAGS) -o $@ $^

clean:
	rm -f *.o finaly
