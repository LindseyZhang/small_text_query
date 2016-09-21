#include <fstream>
#include <iostream>
#include "TextQuery.h"

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cout << "argument less than 2\n";
  } else {
    TextQuery text_query;
    std::ifstream file(argv[1]);
    text_query.ReadFile(file);
    std::string input;
    while(true) {
      std::cout << "please input the word need to search:" << std::endl;
      std::cin >> input;
      if ( input, (input == "q" || input == "Q")) {
	std::cout << " exit query!" << std::endl;
	break;
      } else {
	std::cout << text_query.QueryWord(std::string(input));
      }
    }
  }
  return 0;
}
