#include <iostream>
#include <fstream>
#include "QuickSort.h"
using namespace std;

// Function prototype
int initializeSegments(int segmentSize, char* originalFile, char* f1);

void mergeTwoSegments(int segmentSize, fstream &f1, fstream &f2,
  fstream &f3);

void merge(int numberOfSegments, int segmentSize,
  char* f1, char* f2, char* f3) ;

void copyHalfToF2(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2);

void mergeOneStep(int numberOfSegments, int segmentSize, char* f1,
  char* f2, char* f3);

void mergeSegments(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2, fstream &f3);

void copyFile(char * f1, char * target);

int main()
{
  const int MAX_ARRAY_SIZE = 100000;

  // Implement Phase 1: Create initial segments
  int numberOfSegments =
    initializeSegments(MAX_ARRAY_SIZE, "largedata.dat", "f1.dat");

  // Implement Phase 2: Merge segments recursively
  merge(numberOfSegments, MAX_ARRAY_SIZE, "f1.dat", "f2.dat", "f3.dat");
}

/** Sort orginal file into sorted segments */
int initializeSegments(int segmentSize, char* originalFile, char* f1)
{
  int *list = new int[segmentSize];

  fstream input;
  input.open(originalFile, ios::in | ios::binary);
  fstream output;
  output.open(f1, ios::out | ios::binary);

  int numberOfSegments = 0;
  while (!input.eof()) {
    int i = 0;
    for ( ; !input.eof() && i < segmentSize; i++) {
      input.read(reinterpret_cast<char *> (& list[i]), sizeof(list[i]));
    }

    if (input.eof()) i--;
    if (i <= 0)
      break;
    else
      numberOfSegments++;

    // Sort an array list[0..i-1]
    quickSort(list, i);

    // Write the array to f1.dat
    for (int j = 0; j < i; j++) {
      output.write(reinterpret_cast<char *> (& list[j]), sizeof(list[j]));
    }
  }

  input.close();
  output.close();
  delete [] list;
  return numberOfSegments;
}

void merge(int numberOfSegments, int segmentSize,
  char* f1, char* f2, char* f3)
{
  if (numberOfSegments > 1)
  {
    mergeOneStep(numberOfSegments, segmentSize, f1, f2, f3);
    merge((numberOfSegments + 1) / 2, segmentSize * 2, f3, f1, f2);
  }
  else
  { // rename f1 as the final sorted file
    copyFile(f1, "sortedlargedata.dat");
    cout << "\nSorted into the file sortedlargedata.dat" << endl;
  }
}

void copyFile(char * f1, char * target)
{
  fstream input;
  input.open(f1, ios::in | ios::binary);

  fstream output;
  output.open(target, ios::out | ios::binary);
  int i = 0;
  while (!input.eof()) // Continue if not end of file
  {
    int value;
    input.read(reinterpret_cast<char *> (& value), sizeof(value));
    if (input.eof()) break;
    output.write(reinterpret_cast<char *> (& value), sizeof(value));
  }

  input.close();
  output.close();
}

void mergeOneStep(int numberOfSegments, int segmentSize, char* f1,
  char* f2, char* f3)
{
  fstream f1Input;
  f1Input.open(f1, ios::in | ios::binary);

  fstream f2Output;
  f2Output.open(f2, ios::out | ios::binary);

  // Copy half number of segments from f1.dat to f2.dat
  copyHalfToF2(numberOfSegments, segmentSize, f1Input, f2Output);
  f2Output.close();

  // Merge remaining segments in f1 with segments in f2 into f3
  fstream f2Input;
  f2Input.open(f2, ios::in | ios::binary);
  fstream f3Output;
  f3Output.open(f3, ios::out | ios::binary);

  mergeSegments(numberOfSegments / 2, segmentSize, f1Input, f2Input, f3Output);

  f1Input.close();
  f2Input.close();
  f3Output.close();
}

/** Copy first half number of segments from f1.dat to f2.dat */
void copyHalfToF2(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2)
{
  for (int i = 0; i < (numberOfSegments / 2) * segmentSize; i++)
  {
    int value;
    f1.read(reinterpret_cast<char *> (& value), sizeof(value));
    f2.write(reinterpret_cast<char *> (& value), sizeof(value));
  }
}

/** Merge all segments */
void mergeSegments(int numberOfSegments, int segmentSize, fstream &f1,
  fstream &f2, fstream &f3)
{
  for (int i = 0; i < numberOfSegments; i++)
  {
    mergeTwoSegments(segmentSize, f1, f2, f3);
  }

  // f1 may have one extra segment, copy it to f3
  while (!f1.eof())
  {
    int value;
    f1.read(reinterpret_cast<char *> (& value), sizeof(value));
    if (f1.eof()) break;
    f3.write(reinterpret_cast<char *> (& value), sizeof(value));
  }
}

/** Merge two segments */
void mergeTwoSegments(int segmentSize, fstream &f1, fstream &f2,
  fstream &f3)
{
  int intFromF1;
  f1.read(reinterpret_cast<char *> (& intFromF1), sizeof(intFromF1));
  int intFromF2;
  f2.read(reinterpret_cast<char *> (& intFromF2), sizeof(intFromF2));
  int f1Count = 1;
  int f2Count = 1;

  while (true)
  {
    if (intFromF1 < intFromF2)
    {
      f3.write(reinterpret_cast<char *>(&intFromF1), sizeof(intFromF1));
      if (f1.eof() || f1Count++ >= segmentSize)
      {
        if (f1.eof()) break;
        f3.write(reinterpret_cast<char *>(&intFromF2), sizeof(intFromF2));
        break;
      }
      else
      {
        f1.read(reinterpret_cast<char *> (& intFromF1), sizeof(intFromF1));
      }
    }
    else
    {
      f3.write(reinterpret_cast<char *>(&intFromF2), sizeof(intFromF2));
      if (f2.eof() || f2Count++ >= segmentSize)
      {
        if (f2.eof()) break;
        f3.write(reinterpret_cast<char *>(&intFromF1), sizeof(intFromF1));
        break;
      }
      else {
        f2.read(reinterpret_cast<char *> (& intFromF2), sizeof(intFromF2));
      }
    }
  }

  while (!f1.eof() && f1Count++ < segmentSize) {
    int value;
    f1.read(reinterpret_cast<char *> (& value), sizeof(value));
    if (f1.eof()) break;
    f3.write(reinterpret_cast<char *> (& value), sizeof(value));
  }

  while (!f2.eof() && f2Count++ < segmentSize) {
    int value;
    f2.read(reinterpret_cast<char *> (& value), sizeof(value));
    if (f2.eof()) break;
    f3.write(reinterpret_cast<char *> (& value), sizeof(value));
  }
}
