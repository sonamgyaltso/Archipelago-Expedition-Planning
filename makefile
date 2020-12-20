
Project: main.o 
	g++ -o Project main.o
  
main.o: main.cpp Arch.h
	g++ -c main.cpp 
  
clean:
	rm main.o Project
