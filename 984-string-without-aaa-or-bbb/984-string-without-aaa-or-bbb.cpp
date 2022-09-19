class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b', string res = "") {
        if(B > A) return strWithout3a3b(B, A, b, a, res);
        while(A){
            res += a;
            A--;
            if(A>B) res+= a, A--;
            if(B-->0) res += b;
        }
        return res;
    }
};