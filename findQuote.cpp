#include <iostream>
#include <fstream>

//Finds specific area where quote is located from webpage html

int findQuote() {
  std::ifstream data;
  std::ofstream quote;
  system("curl https://en.wikiquote.org/wiki/Main_Page -s -o data.txt");
  data.open ("data.txt");
  quote.open ("quote.txt");
  std::string line;
  std::string lookString = "Quote of the day";
  int track = 0;

  while (getline(data,line)) {
    std::size_t found = line.find(lookString);
   
    if (found != std::string::npos) {
      if (track == 0) {
        track = 1;
      } else {
        track = 0;
      }
    }

    if (track == 1) {
      quote << line << "\n";
    }
  }
  quote.close();
  data.close();
  return 0;
}