#include<bits/stdc++.h>
using namespace std;

void generator(int first, int second, int count, int n, vector<int> &result)
{
    if(count==n)
    {
      return;
    }

    result.push_back(first);
    generator(second,first+second,count+1,n,result);
}

vector<int> generateFibonacciNumbers(int n) {
  // Write your code here.
  
  vector<int>result;
  int first=0;
  int second=1;
  int count=0;
  generator(first,second,count,n,result);
  return result;

}




//OR  this might lead to TLE , best approach above one


int generator(int n) {
    if (n <= 1) {
        return n;
    }

    return generator(n - 1) + generator(n - 2);
}

std::vector<int> generateFibonacciNumbers(int n) {
    std::vector<int> fib;
    for (int i = 0; i < n; ++i) {
        fib.push_back(generator(i));
    }
    return fib;
}

int main() {
    int n = 5; // Change this to the desired number of Fibonacci numbers
    std::vector<int> result = generateFibonacciNumbers(n);

    // Print the result
    for (int num : result) {
        std::cout << num << " ";
    }

    return 0;
}


