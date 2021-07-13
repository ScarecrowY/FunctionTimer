CC=g++

main: main.cpp
	${CC} -o $@ $^ 

clean:
	rm -f main