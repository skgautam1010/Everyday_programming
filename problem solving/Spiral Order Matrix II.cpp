//Spiral Order Matrix II
//Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.


/*Input 1:
    A = 3

Output 1:
    [   [ 1, 2, 3 ],
        [ 8, 9, 4 ],
        [ 7, 6, 5 ]   ]
*/


vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> result( A , vector<int> (A, 0)); 
    int l=0,t=0,b=A-1,r=A-1;
    int dir=0,i=1;
    while(i<=A*A)
    {
        if(dir==0)
        {
            for(int k=l;k<=r;k++)
            {
                result[t][k]=i++;
            }
            t++;
        }
        else if(dir==1)
        {
            for(int k=t;k<=b;k++)
            {
                result[k][r]=i++;
            }
            r--;
        }
        else if(dir==2)
        {
            for(int k=r;k>=l;k--)
            {
                result[b][k]=i++;
            }
            b--;
        }
        else if(dir==3)
        {
            for(int k=b;k>=t;k--)
            {
                result[k][l]=i++;
            }
            l++;
        }
        dir=(dir+1)%4;
    }
    return result;
    
}
