#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  // Step 1: Read in radius
  double radius;
  cout << "Enter a radius: ";
  cin >> radius;

  // Step 2: Compute area
  double area = radius * radius * 3.14159;

  // Step 3: Display the area
  cout << "The area is " << area << endl;

    system("pause");
  return 0;
}
