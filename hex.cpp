#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const char* usage = "Usage:\n\n"
"Example 1: `hex 10` returns 0xA\n"
"Example 2: `hex 0xa` returns 10";

string int_to_hex( long i ) {
  stringstream stream;
  stream << "0x"<< std::uppercase << std::hex << i;
  return stream.str();
}

int main(int argc, char const *argv[]) {
	if (argc !=2){
		cerr << usage << endl;
		return -1;
	}

	if (string(argv[1]) == "-h" || string(argv[1]) == "-?") {
		cout << "Usage:" << usage << endl;
		return 0;
	}

	if (argv[1][0] == '0' && argv[1][1] == 'x')	{
		char* pEnd;
		long int value = strtol (argv[1], &pEnd, 16);
		if(*pEnd == 0) {
			cout << value << endl;
			return 0;
		}
		else {
			cerr << argv[1] << " is not a valid hex number." << endl;
			return -1;
		}
	} else {
		char* pEnd;
		long int value = strtol (argv[1], &pEnd, 10);
		if(*pEnd == 0) {
			cout << int_to_hex(value) << endl;
			return 0;
		}
		else {
			cerr << argv[1] << " is not a valid integer." << endl;
			return -1;
		}
	}
}
