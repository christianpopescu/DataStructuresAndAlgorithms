Run : CompressedFile
	./CompressedFile
CompressedFile : CompressedFile.o
	g++ -std=c++14 CompressedFile.o -o CompressedFile

CompressedFile.o : CompressedFile.cpp
	g++ -std=c++14 -c CompressedFile.cpp 
