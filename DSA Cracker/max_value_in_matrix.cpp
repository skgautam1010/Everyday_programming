/*
Find a specific pair in Matrix

    Difficulty Level : Hard
    Last Updated : 07 Jan, 2019

Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) over all choices of indexes such that both c > a and d > b.

Example:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 }, 
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
The maximum value is 18 as mat[4][2] 
- mat[1][0] = 18 has maximum difference. 

The program should do only ONE traversal of the matrix. i.e. expected time complexity is O(n2)
*/

#include <bits/stdc++.h>
using namespace std;
#define N 5
  
// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.

//brute force approach O(N^4)
/*
int findMaxValue(int mat[][N])
{
	int maxValue=INT_MIN;

	for(int a=0;a<N-1;a++)
	{
		for(int b=0;b<N-1;b++)
		{
			for(int c=a+1;c<N;c++)
			{
				for(int d=b+1;d<N;d++)
				{
					if((mat[c][d]-mat[a][b])>maxValue)
					{
						maxValue=mat[c][d]-mat[a][b];
					}
				}
			}
		}
	}
	return maxValue;
}

*/

//optimised value O(N^2)

int findMaxValue(int mat[N][N])
{
	int maxValue=INT_MIN;

	int maxArr[N][N];

	maxArr[N-1][N-1]=mat[N-1][N-1];

	int maxv=mat[N-1][N-1];
	for (int i=N-2;i>=0;i--)
	{
		if(mat[i][N-1]>maxv)
		{
			maxv=mat[i][N-1];
		}
		maxArr[i][N-1]=maxv;
	}
	maxv=mat[N-1][N-1];
	for (int j=N-2;j>=0;j--)
	{
		if(mat[N-1][j]>maxv)
		{
			maxv=mat[N-1][j];
		}
		maxArr[N-1][j]=maxv;
	}


	for (int i = N-2;i>=0;i--)
	{
		for (int j=N-2;j>=0;j--)
		{
			if((maxArr[i+1][j+1]-mat[i][j])>maxValue)
			{
				maxValue=maxArr[i+1][j+1]-mat[i][j];
			}

			maxArr[i][j]=max(mat[i][j],max(maxArr[i][j+1],maxArr[i+1][j]));
		}
	}

	return maxValue;

}


int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat)<<"\n";
  
    return 0;
}