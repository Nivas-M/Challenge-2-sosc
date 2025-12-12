#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;

bool isVowel(char c) {
  c = tolower(c);
  return string("aeiou").find(c) != string::npos;
}

int main() {
  ifstream inFile("../inputs/input2.txt");
  if (!inFile.is_open())
    return 1;

  string s;
  inFile >> s;

  reverse(s.begin(), s.end());

  string step2 = "";
  for (int i = 0; i < s.length(); ++i) {
    if ((i + 1) % 3 != 0)
      step2 += s[i];
  }

  int vowelCount = 0;
  for (char &c : step2) {
    c += 2;
    if (isVowel(c))
      vowelCount++;
  }

  cout << "Clue 2: " << vowelCount << endl;
  return 0;
}
