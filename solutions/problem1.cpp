#include <fstream>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  ifstream gridFile("../inputs/grid.txt");
  ifstream dirFile("../inputs/directions.txt");

  if (!gridFile.is_open() || !dirFile.is_open())
    return 1;

  vector<string> grid;
  string line;
  while (getline(gridFile, line)) {
    if (!line.empty())
      grid.push_back(line);
  }

  vector<char> dirs;
  char d;
  while (dirFile >> d)
    dirs.push_back(d);

  for (size_t i = 0; i < grid.size() && i < dirs.size(); ++i) {
    if (dirs[i] == 'R') {
      char last = grid[i].back();
      grid[i].pop_back();
      grid[i].insert(0, 1, last);
    } else if (dirs[i] == 'L') {
      char first = grid[i].front();
      grid[i].erase(0, 1);
      grid[i].push_back(first);
    }
  }

  string middleRow = grid[grid.size() / 2];
  int sum = 0;
  for (char c : middleRow)
    sum += c;

  cout << "Clue 1: " << sum << endl;
  return 0;
}
