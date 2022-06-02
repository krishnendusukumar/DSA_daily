class Solution {
public:
    string addStrings(string num1, string num2) {
       int l1 = num1.size()-1, l2 = num2.size()-1, carry = 0;
        string ans ="";
        while(l1>=0 || l2>=0 || carry>0){
           if(l1>=0)  carry += num1[l1--]-'0';
            if(l2>=0) carry += num2[l2--]-'0';
            ans += char(carry%10 + '0');
            carry = carry/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};