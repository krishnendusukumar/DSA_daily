class MyCalendarThree {
    private: map<int,int> m;int sum = 0;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int maxi = 0;
        for(auto it:m) {
            maxi += it.second;
            sum = max(sum, maxi);
        }
        return sum;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */