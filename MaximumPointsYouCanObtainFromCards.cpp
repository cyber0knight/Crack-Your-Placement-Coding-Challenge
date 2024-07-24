class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += cardPoints[i];
        }
        long long minCut = INT_MAX;
        long long cut = 0;
        k = n-k;
        for(int i=0;i<n;i++){
            if(i<k-1){
                cut += cardPoints[i];
                continue;
            }else if(i == k-1){
                cut += cardPoints[i];
                minCut = min(minCut, cut);
                continue;
            }
            cut -= cardPoints[i-k];
            cut += cardPoints[i];
            minCut = min(minCut, cut);
        }
        return (sum - minCut);
    }
};
