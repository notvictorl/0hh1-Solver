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

void print_board(Line *row[]);

int main() {
  string read[SIZE];

  // Testing with board sizes of 4x4
  cout << "Enter the board: \n";
  for (int i = 0; i < SIZE; i++)
    cin >> read[i];
  cout << "\n";
  
  auto start = chrono::system_clock::now(); // Start timer for program

  // initialize the stuctures and convert to enums
  // Tile board[SIZE][SIZE];
  
  Line *row[SIZE];
  Line *col[SIZE];

  for (int i = 0; i < SIZE; ++i) {
    row[i] = new Line();
    col[i] = new Line();
  } 

  int blank_left = SIZE * SIZE;
  
  // Lambda functions
  auto half_colored = [&] (Line *line) {
    if (line->num_blue == SIZE / 2) {
      for (int j = 0; j < SIZE; j++) {
        Tile *curr = line->tiles[j];
        if (*curr == BLANK) {
          *curr = RED;
          line->num_red++;
          col[j]->num_red++;
          blank_left--;
          return true;
        }
      }
    } else if (line->num_red == SIZE / 2) {
      for (int j = 0; j < SIZE; j++) {
        Tile *curr = line->tiles[j];
        if (*curr == BLANK) {
          *curr = BLUE;
          line->num_blue++;
          col[j]->num_blue++;
          blank_left--;
          return true;
        }
      } 
    }
  };

  for (int i = 0; i < SIZE; ++i) {
    string str_row = read[i];
    for (int j = 0; j < SIZE; ++j) {
      Tile *new_tile = new Tile();
      if (str_row.at(j) == '0') { // Blank
        *new_tile = BLANK;
      } else if (str_row.at(j) == 'b') { // Blue
        *new_tile = BLUE;
        row[i]->num_blue++;
        col[j]->num_blue++;
        blank_left--;
      } else if (str_row.at(j) == 'r') { // Red
        *new_tile = RED;
        row[i]->num_red++;
        col[j]->num_red++;
        blank_left--;
      } else {
        cout << "Error\n";
        exit(1);
      }
      row[i]->tiles[j] = new_tile;
      col[j]->tiles[i] = new_tile;
    }
  }

  cout << "Inputted Board: \n";
  print_board(row);
  
  while (blank_left > 0) {
    for (int i = 0; i < SIZE; i++) {
      Line *cr = row[i]; // Current Row
      if (cr->num_blue == SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          Tile *curr = cr->tiles[j];
          if (*curr == BLANK) {
            *curr = RED;
            cr->num_red++;
            col[j]->num_red++;
            blank_left--;
          }
        }
      } else if (cr->num_red == SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          Tile *curr = cr->tiles[j];
          if (*curr == BLANK) {
            *curr = BLUE;
            cr->num_blue++;
            col[j]->num_blue++;
            blank_left--;
          }
        }
      }
    }
    for (int i = 0; i < SIZE; i++) {
      Line *cc = col[i]; // Current Column
      if (cc->num_blue == SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          Tile *curr = cc->tiles[j];
          if (*curr == BLANK) {
            *curr = RED;
            cc->num_red++;
            row[j]->num_red++;
            blank_left--;
          }
        }
      } else if (cc->num_red == SIZE / 2) {
        for (int j = 0; j < SIZE; j++) {
          Tile *curr = cc->tiles[j];
          if (*curr == BLANK) {
            *curr = BLUE;
            cc->num_blue++;
            row[j]->num_blue++;
            blank_left--;
          }
        }
      }
    } 
  }

  // Print
  cout << "\nSolved Board: \n";
  print_board(row);
  
  // End and calculate timer data
  auto end = chrono::system_clock::now();

  chrono::duration<double> elapsed_seconds = end-start;
  time_t end_time = chrono::system_clock::to_time_t(end);

  cout << "Elapsed Time: " << elapsed_seconds.count() << "s\n";  

  exit(0);
}

void print_board(Line *row[]) {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      Tile curr = *(row[i]->tiles[j]);  
      if (curr == BLANK) cout << "⬛";
      else if (curr == RED) cout << "🟥";
      else if (curr == BLUE) cout << "🟦";
    }
    cout << "\n";
  }
}

bool half_colored(Line *line) {
  
}
