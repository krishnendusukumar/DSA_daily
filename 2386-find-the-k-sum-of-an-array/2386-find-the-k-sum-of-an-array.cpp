class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        long long sum = 0;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] > 0) sum += nums[i];
            else nums[i] = abs(nums[i]);
        }
        
        sort(nums.begin(), nums.end());
        
        vector<long long> subtract;
        pq.push({nums[0], 0});
        
        while(pq.size() > 0 && subtract.size() < k-1) {
            pair<long long, int> p = pq.top();
            pq.pop();
            long long subt = p.first;
            int idx = p.second;
            subtract.push_back(subt);
            if(idx < nums.size()-1) {
                pq.push({nums[idx+1] + subt, idx + 1});
                pq.push({nums[idx+1] + (subt - nums[idx]), idx + 1});
            }
        }
        long long ans = sum;
        for(long long subt:subtract) {
            ans = (sum - subt);
        }
        //return Kth largest sum 
        return ans;
    }
};