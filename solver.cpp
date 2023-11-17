/* Author: Victor Liu
 * 
 * 0h h1 is a small logic of different colored tiles
 * Rules of 0h h1:
 * Equal number of Reds/Blues on both rows and columns
 * No two rows are the same, No two columns are the same
 * Only a maximum of two of one color in a row/column.
 */

#include <iostream>
#include <string>
#include <time.h>
#include <chrono>

#define SIZE 4

using namespace std;

enum Tile {BLANK, RED, BLUE};

struct Line {
  int num_red;
  int num_blue;
  Tile *tiles[4];
};

int main() {
  string read[SIZE];
  auto start = chrono::system_clock::now(); // Start timer for program

  // Testing with board sizes of 4x4
  cout << "Enter the board: \n";
  for (int i = 0; i < SIZE; i++)
    cin >> read[i];
  cout << "\n";
  // for (int i = 0; i < SIZE; i++)
  //  cout << read[i] << "\n";

  // initialize the stuctures and convert to enums
  struct Line *row[SIZE];
  struct Line *col[SIZE]; 
  for (int i = 0; i < SIZE; i++) {
    string str_row = read[i];
    for (int j = 0; j < SIZE; j++) {
      Tile new_tile;
      if (str_row.at(j) == '0') { // Blank
        new_tile = BLANK;
        row[i]->tiles[j] = &new_tile;
      } else if (str_row.at(j) == 'b') // Blue
        new_tile = BLUE;
      else if (str_row.at(j) == 'r') // Red
        new_tile = RED;
    
    }
  }
  
  // End and calculate timer data
  auto end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "Elapsed Time: " << elapsed_seconds.count() << "s\n";  

  exit(0);
}
