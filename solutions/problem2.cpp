#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return string("aeiou").find(c) != string::npos;
}

int main() {
    ifstream inFile("../inputs/input2.txt");
    if (!inFile.is_open()) return 1;

    string s;
    inFile >> s;

    // 1. Reverse
    reverse(s.begin(), s.end());

    // 2. Remove every 3rd character (1-based index: 3, 6, 9...)
    string step2 = "";
    for (int i = 0; i < s.length(); ++i) {
        if ((i + 1) % 3 != 0) step2 += s[i];
    }

    // 3. Shift ASCII +2 and 4. Count Vowels
    int vowelCount = 0;
    for (char &c : step2) {
        c += 2;
        if (isVowel(c)) vowelCount++;
    }

    cout << "Clue 2: " << vowelCount << endl; // Expected: 5
    return 0;
}
