/*

Rotate a matrix by 90 degree in clockwise direction without using any extra space

    Difficulty Level : Medium
    Last Updated : 05 Feb, 2021

Given a square matrix, turn it by 90 degrees in clockwise direction without using any extra space.

Examples: 

Input:
1 2 3 
4 5 6
7 8 9  
Output:
7 4 1 
8 5 2
9 6 3

Input:
1 2
3 4
Output:
3 1
4 2 */




#include <bits/stdc++.h>
using namespace std;
#define N 3

/*
void rotate90Clockwise(int a[N][N])
{
	int temp;

	for(int i=0;i<N/2;i++)
	{
		for(int j=i;j<N-1-i;j++)
		{
			temp=a[i][j];
			a[i][j]=a[N-1-j][i];
			a[N-1-j][i]=a[N-1-i][N-1-j];
			a[N-1-i][N-1-j]=a[j][N-1-i];
			a[j][N-1-i]=temp;
		}
	}
}
*/


void rotate90Clockwise(int a[N][N])
{
	for(int j=0;j<N;j++)
	{
		for (int i = N-1; i >= 0; i--)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
} 




void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int arr[N][N] = { { 1, 2, 3 },
                      { 4, 5, 6 },
                      { 7 ,8 ,9 } };
    rotate90Clockwise(arr);
 //   printMatrix(arr);
    return 0;
}