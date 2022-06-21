class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int n = h.size();
       priority_queue<int> p;
        for(int i=0;i<n-1;i++){
            if(h[i+1] - h[i]<=0) continue;
            else{
                int d = h[i+1] - h[i];
                p.push(-d);
                if(p.size()>l){
                    b+=p.top();
                    p.pop();
                }
                if(b<0) return i;
            }
        }
        return h.size()-1;
    }
};


    