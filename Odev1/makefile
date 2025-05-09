Tum: derleme calistirma

derleme: 
	g++ -I ./include/ -o ./lib/Dna.o -c ./src/Dna.cpp
	g++ -I ./include/ -o ./lib/Gen.o -c ./src/Gen.cpp
	g++ -I ./include/ -o ./lib/Kromozom.o -c ./src/Kromozom.cpp

calistirma:
	g++ -I ./include/ -o ./bin/Main ./lib/Dna.o ./lib/Kromozom.o ./lib/Gen.o ./src/Main.cpp
	./bin/Main
