#include <iostream>
#include "Circle2.h"
using namespace std;

// Add circle areas
double sum(Circle circleArray[], int size)
{
  // Initialize sum
  double sum = 0;

  // Add areas to sum
  for (int i = 0; i < size; i++)
    sum += circleArray[i].getArea();

  return sum;
}

// Print an array of circles and their total area
void printCircleArray(Circle circleArray[], int size)
{
  cout << "Radius\t\t\t\t" << "Area" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << circleArray[i].getRadius() << "\t\t" <<
      circleArray[i].getArea() << endl;
  }

  cout << "-----------------------------------------" << endl;

  // Compute and display the result
  cout << "The total areas of circles is \t" <<
    sum(circleArray, size) << endl;
}

int main()
{
  const int SIZE = 10;

  // Create a Circle object with radius 1
  Circle circleArray[SIZE];

  for (int i = 0; i < SIZE; i++)
  {
    circleArray[i].setRadius(i + 1);
  }

  printCircleArray(circleArray, SIZE);

    system("pause");
  return 0;
}
