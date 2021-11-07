#include <iostream>
#include <string>
#include <regex>
using namespace std;
class Utility {
public:
	static bool isnumber(const std::string& line) {
		for (int i = 0; i < line.size(); ++i)
			if (line[i] == ',') return false;
			for (int i = 0; i < line.length(); i++)
			{
				if (isdigit(line[i]) == false)
				{
					return false;
				}
				return true;
			}
		}
	static bool isfloat(const std::string& line) {
		for (int i = 0; i < line.size(); ++i) {
			if (line[i] == ',') {
				for (int i = 0; i < line.length(); i++)
				{
					if (isdigit(line[i]) == false)
						return false;
					return true;
				}
			}
		}
   return false;
	}
	static bool isbool(const std::string& line) {
		if (line == "true" || line == "false" || line == "0" || line == "1") {
			return true;
		}
		return false;
	}
	static bool isemail(const std::string& line)
	{
		if (!(line[0] >= 'a' && line[0] <= 'z')) {
			return false;
		}
		int at = -1, dot = -1;
		for (int i = 0; i < line.length(); ++i) {
			if (line[i] == '@') { at = i; }
			else if (line[i] == '.') { dot = i; }
		}
		if  ((at == -1 || dot == -1) || (at>dot)) { return false; }
		return !(dot >= (line.length() - 1));
	}

	static bool isurl(const std::string& line) {
		const regex pattern("(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
		if (regex_match(line, pattern)) { return true; }
		return false;
	}

};

 
int main() {
	std::cout << std::boolalpha;
	std::cout << "enter a string   ";
	std::string str;
	std::cin >> str;
	std::cout << std::endl;
	std::cout<<"Is integer: "<<Utility::isnumber(str) << std::endl;
	std::cout <<"Is float: "<< Utility::isfloat(str)<<std::endl;
	std::cout << "Is bool: " << Utility::isbool(str) << std::endl;
	std::cout << "Is Email: " << Utility::isemail(str) << std::endl;
	std::cout << "Is URL:  " << Utility::isurl(str);
}