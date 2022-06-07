class Solution {
public:
    void merge(vector<int>& num1, int m, vector<int>& num2, int n) {
        int i = 0;
        int j = 0;
        vector<int> nums;
        while(i < m && j < n){
            if(num1[i] < num2[j]) {
                nums.push_back(num1[i++]);
            }
            else if(num1[i] > num2[j]) {
                nums.push_back(num2[j++]);
            }
            else{
                nums.push_back(num1[i++]);
                nums.push_back(num2[j++]);
            }
        }
        while(j < n){
            nums.push_back(num2[j++]);
        }
        while(i < m){
            nums.push_back(num1[i++]);
        }
        for (int k = 0;k<nums.size(); k++){
            num1[k] = nums[k];
        }
        return;
    }
};