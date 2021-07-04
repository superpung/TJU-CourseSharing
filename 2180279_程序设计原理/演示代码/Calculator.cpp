#include <iostream>
using namespace std;

int main(int argc, char * argv[])
{
  // Check number of strings passed
  if (argc != 4)
  {
    cout << "Usage: Calculator operand1 operator operand2";
    exit(0);
  }

  // The result of the operation
  int result = 0;

  // Determine the operator
  switch (argv[2][0])
  {
    case '+':
      result = atoi(argv[1]) + atoi(argv[3]);
    break;
    case '-':
      result = atoi(argv[1]) - atoi(argv[3]);
    break;
    case '*':
      result = atoi(argv[1]) * atoi(argv[3]);
    break;
    case '/':
      result = atoi(argv[1]) / atoi(argv[3]);
  }

  // Display result
  cout << argv[1] << ' ' << argv[2] << ' ' << argv[3] << " = " << result;
}
