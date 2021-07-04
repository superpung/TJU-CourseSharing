#include <iostream>
using namespace std;

// Swap two variables
void swap(int *pValue1, int *pValue2)
{
  // Swap n1 with n2
  int temp = *pValue1;
  *pValue1 = *pValue2;
  *pValue2 = temp;
}

int main()
{
  // Declare and initialize variables
  int num1 = 1;
  int num2 = 2;
  int *p1=&num1,*p2=&num2;
  int a[10];
  int *p=a;

   int n;
   char ch,str[10];
   
   cin>>n;
   cin.get(ch);   
   for(int i=0;i<n;i++)
   {
      cin.getline(str,10);
      cout<<str<<endl;
   }

  cout << "Before invoking the swap function, num1 is "
    << num1 << " and num2 is " << num2 << endl;

  // Invoke the swap function to attempt to swap two variables
  swap(p1, p2);

  cout << "After invoking the swap function, num1 is " << num1 <<
    " and num2 is " << num2 << endl;

    system("pause");
  return 0;
}
