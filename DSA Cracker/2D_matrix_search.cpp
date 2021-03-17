/*Search a 2D Matrix
Medium

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

 

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 100
    -104 <= matrix[i][j], target <= 104

*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mid,l=0,h=n-1;
        for(int i=0;i<n;i++)
        {
            mid=(l+h)/2;
            if(matrix[mid][m-1]>=target && matrix[mid][0]<=target)
            {
                for(int j=0;j<m;j++)
                {
                    if(matrix[mid][j]==target)
                    {
                        return true;
                    }
                }
            }
            else if(target<matrix[mid][0])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return 0;
        
    }
};