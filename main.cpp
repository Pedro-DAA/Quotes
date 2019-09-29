#include <fstream>
#include <iostream>
#include "findQuote.cpp"
#include "cleanData.cpp"

int main () {
    findQuote();
    cleanData();
    remove("data.txt");
    remove("quote.txt");
    return 0;
}