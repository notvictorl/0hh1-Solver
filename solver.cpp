#include <iostream>
#include <string>
#include <time.h>
#include <chrono>

using namespace std;

enum tile {BLANK, RED, BLUE};

int main() {
  string read;
  auto start = chrono::system_clock::now(); // Start timer for program

  cout << "Enter the board: ";
  cin >> read;
  cout << read + "\n";
  
  // End and calculate timer data
  auto end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "Elapsed Time: " << elapsed_seconds.count() << "s\n";  

  exit(0);
}
