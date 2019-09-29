#include <iostream>
#include <fstream>
#include <stack>

//cleans data by erasing everything between <...>

int cleanData() {
    std::ifstream dirtyData;
    std::ofstream cleanData;
    dirtyData.open ("quote.txt");
    cleanData.open ("Quote.txt");
    std::string line;
    std::stack<char> reverseString;
    while (getline(dirtyData,line)) {
        
        for (int i = 0; i < line.length(); i++) {
            reverseString.push(line[i]);
            if (line[i] == '>') {
                while (reverseString.top() != '<') { 
                    reverseString.pop();
                }
                if (reverseString.top() == '<') {
                    reverseString.pop();
                }
            }
        }
    }
    std::stack <char> forwarString;
    for (int j = 0; j < 8; j++) {reverseString.pop();}
    while (!reverseString.empty()) {
        if (reverseString.size() == 22) {break;}
        forwarString.push(reverseString.top());
        reverseString.pop();
    }
    while (!forwarString.empty()) {
        cleanData << forwarString.top();
        forwarString.pop();
    }
    dirtyData.close();
    cleanData.close();
    return 0;
}
