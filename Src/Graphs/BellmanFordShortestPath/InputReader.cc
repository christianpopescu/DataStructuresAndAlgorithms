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
	input_steam = &std::cin;
}

void InputReader::SetInputStreamFile(std::string par_file_name) {
     file_name = par_file_name;
	 inputFile = new std::ifstream(file_name);
	 inputFile->is_open();
	  
}