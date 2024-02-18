#include<bits/stdc++.h>

using namespace std;


//Optimal Approach 
vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.
    int n=arr.size();
    k=k%n;
    reverse(arr.begin(),arr.begin()+k);
   
    /*cout<<"After first reverse\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";*/
    reverse(arr.begin()+k,arr.end());
    /*cout<<"After second reverse\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";*/
    reverse(arr.begin(),arr.end());
    /*cout<<"After final reverse\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";*/
    return arr;
}

//Brute Force Approach

vector<int> rotateArray(vector<int>arr, int k) {
    // Write your code here.


    //Brute Force Approach 
    vector<int>temp;
    int n=arr.size();
    k=k%n;
    int i=0;
    while(i<k)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while(i<n)
    {
        arr[i-k]=arr[i];
        i++;
    }
    for(int i=n-k;i<n;i++)
    {
        arr[i]=temp[i-(n-k)];
    }

    return arr;
}


int main()
{

    int k;
    cin>>k;
    int n,temp;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
            cin>>temp;
            arr.push_back(temp);
    }
    arr=rotateArray(arr,k);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\n";
    }
    return 0;
}
