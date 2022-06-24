class Solution {
public:
    bool isPossible(vector<int>& target) {
        unsigned int sum = 0;
        priority_queue<int> q;
        for (int i=0;i<target.size();i++) 
            sum+=target[i], q.push(target[i]);
        while(q.top()!=1){
            int x = q.top();
            sum-=x;
            q.pop();
            if(x<=sum || sum < 1) return false;
            x = x%sum;
            sum+=x;
            if(x>0) q.push(x);
            else q.push(sum);
        }
        return true;
    }
};