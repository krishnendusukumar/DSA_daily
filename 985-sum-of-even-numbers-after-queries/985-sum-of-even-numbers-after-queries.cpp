class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& q) {
        vector<int> arr;
        int sum = 0;
        for(int it: nums) if(it % 2 == 0) sum += it;
        for(int i = 0 ;i < q.size(); i++) {
            int ind = q[i][1];
            int add = q[i][0];
            
            if(nums[ind] % 2 == 0) {
                if(add % 2 == 0) {
                    nums[ind] += add;
                    sum += add;
                    arr.push_back(sum);
                }
                else {
                    sum -= nums[ind];
                    nums[ind] += add;
                    arr.push_back(sum);
                }
            }
            else {
                if(add % 2 == 0) {
                    nums[ind] += add;
                    arr.push_back(sum);
                }
                else {
                    nums[ind] += add;
                    sum += nums[ind];
                    arr.push_back(sum);
                }
            }
        }
        if(arr.size() == 0) return {0};
        return arr;
    }
};