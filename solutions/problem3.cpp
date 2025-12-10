#include <iostream>
#include <fstream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ifstream inFile("../inputs/states.txt");
    if (!inFile.is_open()) return 1;

    int num;
    int doneCount = 0;
    while (inFile >> num) {
        if (isPrime(num)) doneCount++;
    }

    cout << "Clue 3: " << doneCount << endl;
    return 0;
}
