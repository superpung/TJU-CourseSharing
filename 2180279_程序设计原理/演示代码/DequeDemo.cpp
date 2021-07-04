#include <iostream>
#include <deque>
using namespace std;

int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  deque<double> doubleDeque(values, values + 7);

  cout << "Initial contents in doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.assign(4, 11.5);
  cout << "\nAfter the assign function, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.at(0) = 22.4;
  cout << "\nAfter the at function, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  deque<double>::iterator itr = doubleDeque.begin();
  doubleDeque.insert(itr + 1, 555);
  doubleDeque.insert(itr + 1, 666);
  cout << "\nAfter the insert function, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.erase(itr + 2, itr + 4);
  cout << "\nAfter the erase function, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.clear();
  cout << "\nAfter the clear function, doubleDeque: ";
  cout << "Size is " << doubleDeque.size() << endl;
  cout << "Is empty? " <<
        (doubleDeque.empty() ? "true" : "false") << endl;

  doubleDeque.push_front(10.10);
  doubleDeque.push_front(11.15);
  doubleDeque.push_front(12.34);
  cout << "After the insertion, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

  doubleDeque.pop_front();
  doubleDeque.pop_back();
  cout << "\nAfter the pop functions, doubleDeque: ";
  for (int i = 0; i < doubleDeque.size(); i++)
    cout << doubleDeque[i] << " ";

    system("pause");
  return 0;
}
