#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream output;
  char *p="abcd";
  
  cout<<strlen(p)<<endl;
  //stiing st1;

  // Create a file
  output.open("numbers.txt");

  // Write numbers
  output << 95 << " " << 56 << " " << 34 <<'\b';

  // close file
  output.close();

  cout << "Done" << endl;
    system("pause");
  return 0;
}
