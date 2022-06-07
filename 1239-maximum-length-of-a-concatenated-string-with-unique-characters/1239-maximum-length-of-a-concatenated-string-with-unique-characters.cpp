class Solution {
public:
    
    bool compare(vector<int>& selected, string& s){
        vector<int> check(26, 0);
        for(int i = 0;i<s.size();i++){
            if(check[s[i]-'a'] == 1) return false;
            check[s[i]-'a'] = 1;
        }
        for (int i = 0;i<s.size();i++){
            if(selected[s[i]-'a'] == 1) return false;
        }
        return true;
    }
    
    int call(int i, vector<int> &selected, vector<string> &nums, int len) {
        if( i >= nums.size()) return len;
        string s = nums[i];
        if(compare(selected, s) == false){
            return call(i+1, selected, nums, len);
        }
        else{
            for(int j = 0;j<s.size(); j++) selected[s[j]-'a'] = 1;
            len += s.size();
            int l1 = call(i+1, selected, nums, len);
            
            //skip
            for(int j = 0;j < s.size();j++) selected[s[j]-'a'] = 0;
            len -= s.size();
            int l2 = call(i+1, selected, nums, len);
            return max(l1, l2);
        }
        
    }
    
    int maxLength(vector<string>& arr) {
        vector<int> selected(26, 0);
        return call(0, selected, arr, 0);
    }
};