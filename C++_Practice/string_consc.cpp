#include <bits/stdc++.h>
using namespace std;
 
void printRLE(string s)
{
    int sum=0;
    for (int i = 0; s[i] != '\0'; i++) {
 
        int count = 1;
        while (s[i] == s[i + 1]) {
            i++;
            count++;
        }
        if(count%2==0)
        {
            sum +=count;
        }
    }
 
    cout << sum<<endl;
}
 
// Driver code
int main()
{
    printRLE("vdkkmmmnn");
    return 0;
}