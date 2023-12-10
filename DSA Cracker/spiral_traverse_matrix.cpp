/*
Spirally traversing a matrix
Medium Accuracy: 48.39% Submissions: 24227 Points: 4

Given a matrix of size R*C. Traverse the matrix in spiral form.

Example 1:

Input:
R = 4, C = 4
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12},
           {13, 14, 15,16}}
Output: 
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
Explanation:

Example 2:

Input:
R = 3, C = 4  
matrix[][] = {{1, 2, 3, 4},
           {5, 6, 7, 8},
           {9, 10, 11, 12}}
Output: 
1 2 3 4 8 12 11 10 9 5 6 7
Explanation:
Applying same technique as shown above, 
output for the 2nd testcase will be 
1 2 3 4 8 12 11 10 9 5 6 7.
*/


// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>result;
        int l=0,t=0,b=r-1,right=c-1;
        int dir=0;
        
        while(t<=b && l<=right)
        {
            if(dir==0)
            {
                for(int k=l;k<=right;k++)
                {
                    result.push_back(matrix[t][k]);
                }
                t++;
            }
            else if(dir==1)
            {
                for(int k=t;k<=b;k++)
                {
                    result.push_back(matrix[k][right]);
                }
                right--;
            }
            else if(dir==2)
            {
                for(int k=right;k>=l;k--)
                {
                    result.push_back(matrix[b][k]);
                }
                b--;
            }
            else if(dir==3)
            {
                for(int k=b;k>=t;k--)
                {
                    result.push_back(matrix[k][l]);
                }
                l++;
            }
            dir=(dir+1)%4;
        }
        
        
        return result;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends