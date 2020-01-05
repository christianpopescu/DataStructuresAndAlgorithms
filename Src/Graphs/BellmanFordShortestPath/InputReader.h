#include <istream>
#include <fstream>
#include <vector>
#include <tuple>

class InputReader {
public:
	InputReader();
	~InputReader();
	
	void SetInputStreamConsole();
	void SetInputStreamFile(std::string par_file_name);
	void ReadGraphAsEdges(std::vector<std::tuple<int,int,int>>& edges);
	
protected:
	std::istream* input_stream;
	std::ifstream* inputFile;
	std::string file_name;
};
