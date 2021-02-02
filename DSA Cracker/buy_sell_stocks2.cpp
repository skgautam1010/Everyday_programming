class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;//buy
        int r=1;//sell
        int n=prices.size();
        int profit,result=0;
        while(r<n)
        {
            if(prices[l]<prices[r])
            {
                profit=prices[r]-prices[l];
                result +=profit;
            }
            r++;l++;
        }
        return result;
    }
};