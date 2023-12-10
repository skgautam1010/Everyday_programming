class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int l=0;//buy
        int r=1;//sell
        int profit,result=0;
        while(r<n)
        {
            if(prices[l]<prices[r])
            {
               profit =prices[r]-prices[l];
               result=max(profit,result);
            }
            else
            {
                l=r;
            }
            r++;
        }
        return result;
    }
};