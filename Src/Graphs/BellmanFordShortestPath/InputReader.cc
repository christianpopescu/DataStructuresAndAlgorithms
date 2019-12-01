#include <iostream>
#include <string>
#include "InputReader.h"

InputReader::InputReader() {
	SetInputStreamConsole();
}

InputReader::~InputReader() {
	if (inputFile != nullptr) {
	   inputFile->close();
	   delete inputFile;
	}
}

void InputReader::SetInputStreamConsole() {
	input_stream = &std::cin;
}

void InputReader::SetInputStreamFile(std::string par_file_name) {
     file_name = par_file_name;
	 inputFile = new std::ifstream(file_name);
	 inputFile->is_open();
	 input_stream = inputFile;
	  
}

void InputReader::ReadGraphAsEdges(std::vector<std::tuple<int,int,int>>& edges) {
	int nb_edges = 0;
	(*input_stream) >> nb_edges;
	int a,b,w;
	for (int i = 0 ; i<nb_edges; ++i) {
		(*input_stream) >> a >> b >> w;
		edges.push_back(std::make_tuple(a,b,w));
	}
		
}