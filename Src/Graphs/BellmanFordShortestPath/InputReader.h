#include <istream>
#include <fstream>

class InputReader {
public:
	InputReader();
	~InputReader();
	
	void SetInputStreamConsole();
	void SetInputStreamFile(std::string par_file_name);
	
private:
	std::istream* input_steam;
	std::ifstream* inputFile;
	std::string file_name;
};
