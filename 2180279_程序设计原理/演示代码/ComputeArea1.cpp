#include <iostream>

int main()
{
  // Step 1: Read in radius
  double radius;
  std::cout << "Enter a radius: ";
  std::cin >> radius;

  // Step 2: Compute area
  double area = radius * radius * 3.14159;

  // Step 3: Display the area
  std::cout << "The area is " << area << std::endl;

    system("pause");
  return 0;
}
