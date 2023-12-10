
/*Powerful Integers

Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.

An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32

Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

 

Constraints:

    1 <= x, y <= 100
    0 <= bound <= 106

*/



class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
        set<int>s;
        int k,i=0,j;
        if(x==1 && y==1)
        {
            if(x+y<=bound)
            {
                s.insert(2);
            }
        }
        else if(x==1)
        {
            k=0;
            while(pow(y,k)+1<=bound)
            {
                s.insert(pow(y,k)+1);
                k++;
            }
        }
        else if(y==1)
        {
            k=0;
            while(pow(x,k)+1<=bound)
            {
                s.insert(pow(x,k)+1);
                k++;
            }
            
        }
        else{
        while(pow(x,i)<bound)
        {
            j=0;
            while(pow(y,j)<bound)
            {
                if((pow(x,i)+pow(y,j))<=bound)
                {
                    s.insert((pow(x,i)+pow(y,j)));
                }
                j++;
            }
            i++;
        }
        }
        vector<int>result(s.begin(),s.end());
        return result;
        
    }
};