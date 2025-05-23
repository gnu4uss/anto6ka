CXXFLAGS = -g
finaly: main.o MeasTime.o
	g++ $(CXXFLAGS) -o $@ $^
clean:
	rm -f *.o finaly sorting_times.dat
