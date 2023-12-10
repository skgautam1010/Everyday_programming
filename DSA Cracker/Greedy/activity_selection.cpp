// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
 {
        return a.second<b.second;
     
 }
class Solution
{
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            pair<int,int>temp;
            temp=make_pair(start[i],end[i]);
            v.push_back(temp);
        
        }
        sort(v.begin(),v.end(),sortbysec);
        
        int count=0;
        vector<pair<int,int>>new_pair;
        for(int i=0;i<n;i++)
        {
            if(new_pair.size()==0)
            {
                new_pair.push_back(v[i]);
            }
            else if(v[i].first> new_pair[new_pair.size()-1].second)
            {
                new_pair.push_back(v[i]);
            }
        }
        count=new_pair.size();
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends