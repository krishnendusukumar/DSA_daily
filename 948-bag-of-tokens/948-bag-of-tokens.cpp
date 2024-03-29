class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        if(n == 0) return n;
        sort(tokens.begin(),tokens.end());
        int i = 0, j = n-1;
        int count= 0, counter = 0;
        int score = 0;
        int res= 0;
        while(i <= j) {
            if(tokens[i] <= power) {
                // score++;
                power -= tokens[i++];
                res = max(res, ++score);
            }
            else if(score > 0){
                // if(i == j) return score;
                score--;
                power += tokens[j--];
            }
            else break;
        }
        return res;
    }
};