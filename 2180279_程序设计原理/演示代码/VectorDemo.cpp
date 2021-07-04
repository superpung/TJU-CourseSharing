#include <iostream>
#include <vector>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  vector<double> doubleVector(values, values + 7);

  cout << "Initial contents in doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.assign(4, 11.5);

  cout << "\nAfter the assign function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.at(0) = 22.4;
  cout << "\nAfter the at function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  vector<double>::iterator itr = doubleVector.begin();
  doubleVector.insert(itr + 1, 555);
  doubleVector.insert(itr + 1, 666);
  cout << "\nAfter the insert function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.erase(itr + 2, itr + 4);
  cout << "\nAfter the erase function, doubleVector: ";
  for (int i = 0; i < doubleVector.size(); i++)
    cout << doubleVector[i] << " ";

  doubleVector.clear();
  cout << "\Size is " << doubleVector.size() << endl;
  cout << "Is empty? " <<
        (doubleVector.empty() ? "true" : "false") << endl;

    system("pause");
  return 0;
}
