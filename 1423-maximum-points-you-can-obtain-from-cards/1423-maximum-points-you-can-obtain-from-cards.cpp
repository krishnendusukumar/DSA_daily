class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, res = 0;;
        int i = 0;
        while(i < n - k) sum += cardPoints[i++];
        int j = 0;
              res = sum;
        while(i < n) {
            sum =  sum - cardPoints[j++] + cardPoints[i++];
            res = min(res, sum);
        }
              int ans = 0;
              for(int it: cardPoints) ans += it;
              return ans - res;
    }
};