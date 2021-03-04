/*
 *  Euler Project: Problem 7
 * What is the 10 001st prime number?
 */
 /*------------------------------------------------*
 * Finds n-th prime number using Sieve's algorithm
 * ------------------------------------------------*
 */
#include <iostream>  
#include <cmath>
#include <algorithm>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
  
int primes_sieve(int n){
    int bound = int(2*n*log(n));
    int valid_primes[bound];
    unsigned int count = 0;
    fill_n(valid_primes, bound, 1);
    for (int i=2; i<bound; i++){
        if (valid_primes[i]==1){
            count++;
            if (count==n)
                return i;
        }
        for (int j = 2*i; j<bound; j=j+i){
            valid_primes[j] = 0;
        }
    }
    return -1;
}
int main()  
{  
    int n;  
    cout << "Enter n: ";  
    cin >> n;
    // Measure the elapsed time
    auto start = high_resolution_clock::now(); 
    // Call function
    int res = primes_sieve(n);
    // Ending timepoint
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    cout<<n<<"th prime number is: "<< res<<endl; 
    cout<<"Elapsed time is: "<<(duration.count())/1000000.0<<" seconds"<<endl;
    
    return 0;
}
