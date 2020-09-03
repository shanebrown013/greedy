#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include "functionsHW5.h"

using namespace std;

int main() {
int rows;
int columns;
string fileName;
string outputFileName;
ifstream inFS;
ofstream onFS;
string lines;
int value;

cout << "Number of rows: ";
cin >> rows;
// CHECK: If input is good
if ((!cin.good()) || (rows <= 0)) {
  cout << "Error: Invalid entry." << endl;
  return(1);
}
cout << "Number of columns: ";
cin >> columns;
// CHECK: If input is good
if ((!cin.good()) || (columns <= 0)) {
  cout << "Error: Invalid entry." << endl;
  return(1);
}
cout << "File name: ";
cin >> fileName;

//Opening the file
inFS.open(fileName);
if (!inFS.is_open()) {
  cout << "Error: Could not open file." << endl;
  return(1);
}

//Reading the file
vector<vector<int> > Vector;
for (int i = 0; i < rows; i++) {
  vector<int> blankVect;
  for (int j = 0; j < columns; j++) {
    inFS >> value;
    blankVect.push_back(value);
  }
  Vector.push_back(blankVect);
}

// CHECK: too much data (over the amount of rows and/or columns)
if (inFS.fail()) {
  cout << "Error: Invalid data." << endl;
  return(1);
}

//CHECK: If the user enters the incorrect number of rows/columns (lower than actual number)
int notEnough;
inFS >> notEnough;
if (inFS.fail()) {
  inFS.close();
}
else {
  cout << "Error: Invalid number of rows/columns." << endl;
  return(1);
}

// Finding min and max values
int min;
int max = Vector.at(0).at(0);
int VectorSize = Vector.size();
for (unsigned int i = 0; i < VectorSize; i++) {
  for (int j = 0; j < Vector.at(i).size(); j++) {
    if (Vector.at(i).at(j) > max) {
      max = Vector.at(i).at(j);
    }
  }
}
min = max;
for (unsigned int i = 0; i < VectorSize; i++) {
  for (int j = 0; j < Vector.at(i).size(); j++) {
    if (Vector.at(i).at(j) < min) {
      min = Vector.at(i).at(j);
    }
  }
}

//Convert each value to shade of grey
float shadeOfGrey = 0;
vector<vector<int> > r;
vector<vector<int> > g;
vector<vector<int> > b;
for (unsigned int i = 0; i < VectorSize; i++) {
  vector<int> blankVect2;
  for (int j = 0; j < Vector.at(i).size(); j++) {
    float top = Vector.at(i).at(j) - min;
    float bottom = max - min;
    shadeOfGrey = round((top / bottom) * 255);
    blankVect2.push_back(shadeOfGrey);
  }
  r.push_back(blankVect2);
  g.push_back(blankVect2);
  b.push_back(blankVect2);
}

// Finding the longest path to use to initilize shortPath
int longPath = 0;
int dist = 0;
for (int i = 0; i < rows; i++) {
  dist = colorPath(Vector, r, g, b, 252, 25, 63, i);
  if (dist > longPath) {
    longPath = dist;
  }
}
// Calculating and calling shortest path
dist = 0;                   // Path and shortPath keep track of the shortest path regarding
int shortPath = longPath;   // elevation levels
int rowCount = 0;
for (int i = 0; i < VectorSize; i++) {
  dist = colorPath(Vector, r, g, b, 252, 25, 63, i);
  if (dist < shortPath) {
    shortPath = dist;
    rowCount = i;
  }
}
// Changing shortPath to green
for (int i = rowCount; i < rowCount + 1; i++) {
    colorPath(Vector, r, g, b, 31, 253, 13, i);
}


//Writing to output file
outputFileName = fileName + ".ppm";
onFS.open(outputFileName);
if (!onFS.is_open()) {
  cout << "Error: Could not open file." << endl;
  return(1);
}
onFS << "P3\n";
onFS << columns << " " << rows << endl;
onFS << 255 << endl;
int RedSize = r.size();
  for (int i = 0; i < RedSize ; i++) {
    for (int j = 0; j < r.at(i).size(); j++) {
      onFS << r.at(i).at(j) << " ";
      onFS << g.at(i).at(j) << " ";
      onFS << b.at(i).at(j) << " ";
  }
  onFS << endl;
}
 onFS.close();
  return 0;
}
