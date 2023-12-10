// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
bool cmp(Job a,Job b)
{
    return a.profit>b.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here

        sort(arr,arr+n,cmp);
        
        int count=0,sum=0;
        
        int result[n];
        bool slot[n];
        
        for(int i=0;i<n;i++)
        {
            slot[i]=false;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead)-1;j>=0;j--)
            {
                if(slot[j]==false)
                {
                    result[j]=i;
                    slot[j]=true;
                    break;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(slot[i])
            {
                sum +=arr[result[i]].profit;
                count++;
            }
        }
        
        vector<int>res={count,sum};
        return res;
        //process for shorter testcases
      /*  sort(arr,arr+n,cmp);
        
      for(int i=0;i<n;i++)
        {
            cout<<arr[i].dead<<" "<<arr[i].profit<<endl;
        }
        cout<<endl;
        
        int count=1;
        int sum =arr[0].profit;
        int unit=1;
        unit++;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i].dead>=unit)
            {
                sum +=arr[i].profit;
                count++;
                unit++;
            }
        }
        
        vector<int>res={count,sum};
        return res;
        */
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends