class Solution {
public:
    
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] > v2[1];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> p;
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<vector<int>>worker;
        vector<int> t(2,0);
        for(int i = 0; i < n; i++) {
            t[0] = speed[i];
            t[1] = efficiency[i];
            worker.push_back(t);
        }
        sort(worker.begin(), worker.end(), compare);
        long res = 0;
        long total = 0;
        long minE;
        for (int i = 0; i < k; i++) {
            total += worker[i][0];
            minE = worker[i][1];
            res = max(res, total*minE);
            heap.push(worker[i][0]);
        }
        for (int i = k; i < n; i++) {
            if (worker[i][0] > heap.top()) {
                total += (-heap.top()+worker[i][0]);
                minE = worker[i][1];
                res = max(res, total*minE);
                heap.pop();
                heap.push(worker[i][0]);
            }
        }
        return (int)(res%1000000007);
    }
};