
#include<bits/stdc++.h>

using namespace std;


int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int temp_count=0,final_count=0;
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            temp_count++;
        }
        else{
            temp_count=0;
        }
        if(temp_count>final_count)
        {
            final_count=temp_count;
        }
        
        
    }
    return final_count;
}