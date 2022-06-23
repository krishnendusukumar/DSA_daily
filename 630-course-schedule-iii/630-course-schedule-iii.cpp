class Solution {
public:
    
    static bool sortbysec(vector<int>& a,
              vector<int>&b)
{
    return (a[1] < b[1]);
}
    
    int scheduleCourse(vector<vector<int>>& v) {
        sort(v.begin(),v.end(), sortbysec);
        long long sum = 0;
       priority_queue<int> q;
     for(auto i : v) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};