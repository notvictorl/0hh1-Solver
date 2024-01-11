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
  Tile *tiles[SIZE];
};

int main() {
  string read[SIZE];
  auto start = chrono::system_clock::now(); // Start timer for program

  // Testing with board sizes of 4x4
  cout << "Enter the board: \n";
  for (int i = 0; i < SIZE; i++)
    cin >> read[i];
  cout << "\n";

  // initialize the stuctures and convert to enums
  // Tile board[SIZE][SIZE];
  struct Line *row[SIZE];
  struct Line *col[SIZE]; 
 
  int blank_left = SIZE * SIZE;

  for (int i = 0; i < SIZE; i++) {
    string str_row = read[i];
    cout << str_row << "\n";
    for (int j = 0; j < SIZE; j++) {
      Tile new_tile;
      if (str_row.at(j) == '0') { // Blank
        new_tile = BLANK;
      } else if (str_row.at(j) == 'b') { // Blue
        new_tile = BLUE;
        row[i]->num_blue++;
        col[j]->num_blue++;
        blank_left--;
      } else if (str_row.at(j) == 'r') { // Red
        new_tile = RED;
        row[i]->num_red++;
        col[j]->num_red++;
        blank_left--;
      } else {
        cout << "Error\n";
        exit(1);
      }
      row[i]->tiles[j] = &new_tile;
      col[j]->tiles[i] = &new_tile;
    }
  }

  /* while (blank_left > 0) {
    for (int i = 0; i < SIZE; i++) {
      Line *cur_row = row[i];
      if (cur_row->num_red == SIZE / 2 && cur_row->num_blue < SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          if (cur_row->tiles[j] == BLANK) {
            cur_row->tiles[j] == BLUE;
            cur_row->num_blue++;
            col[j]->num_blue++;
            blank_left--;
          }
        }
      } else if (cur_row->num_blue == SIZE / 2 && cur_row->num_red < SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          if (cur_row->tiles[j] == BLANK) {
            cur_row->tiles[j] == RED;
            cur_row->num_red++;
            col[j]->num_red++;
            blank_left--;
          }
        }
      }
    }
    for (int i = 0; i < SIZE; i++) {
      Line *cur_col = col[i];
      if (cur_col->num_red == SIZE / 2 && cur_col->num_blue < SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          if (cur_col->tiles[j] == BLANK) {
            cur_col->tiles[j] == BLUE;
            cur_col->num_blue++;
            row[j]->num_blue++;
            blank_left--;
          }
        }
      } else if (cur_col->num_blue == SIZE / 2 && cur_col->num_red < SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          if (cur_col->tiles[j] == BLANK) {
            cur_col->tiles[j] == RED;
            cur_col->num_red++;
            row[j]->num_red++;
            blank_left--;
          }
        }
      }
    }
  } */

  // Print
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cout << "BRUH";
    }
    cout << "\n";
  }
  
  // End and calculate timer data
  auto end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "Elapsed Time: " << elapsed_seconds.count() << "s\n";  

  exit(0);
}
