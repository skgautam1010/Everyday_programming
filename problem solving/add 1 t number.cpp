
/*Add One To Number

    Asked in:  
    Google
    Microsoft

Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

    NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
    For example, for this problem, following are some good questions to ask :

        Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?

        A : For the purpose of this question, YES
        Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
        A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/

vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    vector<int>sol;
    reverse(A.begin(),A.end());
    int carry=1;
    for(int i=0;i<n;i++)
    {
        A[i]=A[i]+carry;
        if(A[i]==10)
        {
            sol.push_back(A[i]%10);
        }
        else
        {
            sol.push_back(A[i]);
        }
        carry=A[i]/10;
        
    }
    if(carry!=0)
    {
        sol.push_back(carry);
    }
    reverse(sol.begin(),sol.end());
    int k=0;
    while(sol[k]==0)
    {
        sol.erase(sol.begin());
    }
    return sol;
    
}
