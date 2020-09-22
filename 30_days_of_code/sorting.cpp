#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int num_of_swaps=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        for(int j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                num_of_swaps++;
            }
        }
        if (num_of_swaps==0)
        {
            break;
        }
    }
    int felement=a[0];
    int lelement=a[n-1];
    cout<<"Array is sorted in "<<num_of_swaps<<" swaps.\n";
    cout<<"First Element: "<<felement<<endl;
    cout<<"Last Element: "<<lelement<<endl;
    // Write Your Code Here
    return 0;
}
