#include <iostream>
using namespace std;

int main()
{
  const int NUMBER_OF_PRIMES = 50; // Number of primes to display
  const int NUMBER_OF_PRIMES_PER_LINE = 10; // Display 10 per line
  int count = 0; // Count the number of prime numbers
  int number = 2; // A number to be tested for primeness

  cout << "The first 50 prime numbers are \n";

  // Repeatedly find prime numbers
  while (count < NUMBER_OF_PRIMES)
  {
    // Assume the number is prime
    bool isPrime = true; // Is the current number prime?

    // Test if number is prime
    for (int divisor = 2; divisor <= number / 2; divisor++)
    {
      if (number % divisor == 0)
      {
        // If true, the number is not prime
        isPrime = false; // Set isPrime to false
        break; // Exit the for loop
      }
    }

    // Print the prime number and increase the count
    if (isPrime)
    {
      count++; // Increase the count

      if (count % NUMBER_OF_PRIMES_PER_LINE == 0)
      {
        // Print the number and advance to the new line
        cout << number << endl;
      }
      else
        cout << number << " ";
    }

    // Check if the next number is prime
    number++;
  }

    system("pause");
  return 0;
}
