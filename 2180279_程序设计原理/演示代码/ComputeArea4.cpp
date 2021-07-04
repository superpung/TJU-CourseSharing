#include <iostream>
using namespace std;

int main() {
  const double PI = 3.14159;

  // Step 1: Read in radius
  double radius = 20;

  // Step 2: Compute area
  double area = radius * radius * PI;

  // Step 3: Display the area
  cout << "The area is ";
  cout << area << std::endl;

    system("pause");
  return 0;
}
