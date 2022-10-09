// Sieve of eratosthenes

// Count prime numbers less than given number

#include <iostream>
#include <vector>

using namespace std;

void countPrimes(int n)
{
    // Create variable for counting
    int count = 0;

    // Create bool type vector of size n+1 and mark all as true
    vector<bool> prime(n + 1, true);

    // 0 and 1 are not prime numbers, mark as false
    prime[0] = prime[1] = false;

    //Iterate loop from 2 to n
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {   
            // If number is prime increase count
            count++;

            // Mark as false all numbers which are multiple of prime numbers
            for (int j = 2 * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }

    // Print count
    cout << count << endl;
}
int main()
{
    int n;

    n = 20;

    // Call function countPrimes
    countPrimes(n);

    return 0;
}
