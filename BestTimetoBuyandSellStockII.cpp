class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int profit = 0;
        int m = p[0];
        int cost = 0;
        for(int i=1;i<p.size();i++)
        {
            cost = p[i]-m;
            if(cost>0)
            {
                profit +=cost;
                m = p[i];
            }
            else
            {
                m = min(m,p[i]);
            }
        }
        return profit;
    }
};