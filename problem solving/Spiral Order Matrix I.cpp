//Spiral Order Matrix I
//Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

//Example:

//Given the following matrix:

//[
  //  [ 1, 2, 3 ],
    //[ 4, 5, 6 ],
    //[ 7, 8, 9 ]
//]

//You should return

//[1, 2, 3, 6, 9, 8, 7, 4, 5]

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int>result;
    int m=A.size();
    int n=A[0].size();
    int dir=0,l=0,b=m-1,t=0,r=n-1;
    while(t<=b && l<=r)
    {
        if(dir==0)
        {
            for(int k=l;k<=r;k++)
            {
                result.push_back(A[t][k]);
            }
            t++;
        }
        else if(dir==1)
        {
            for(int k=t;k<=b;k++)
            {
                result.push_back(A[k][r]);
            }
            r--;
        }
        else if(dir==2)
        {
            for(int k=r;k>=l;k--)
            {
                result.push_back(A[b][k]);
            }
            b--;
        }
        else if(dir==3)
        {
            for(int k=b;k>=t;k--)
            {
                result.push_back(A[k][l]);
            }
            l++;
        }
        dir=(dir+1)%4;
    }
    return result;
}
