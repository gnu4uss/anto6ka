CXXFLAGS = -g
finaly: main.o MeasTime.o sorts_high.o
	g++ $(CXXFLAGS) -o $@ $^

finaly: main.o MeasTime.o sorts_high.o
	g++ -g -o $@ $^
clean:
	rm -f *.o finaly
