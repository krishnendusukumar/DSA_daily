class Solution {
public:
    
    bool helper(vector<vector<int>>& matrix, int target, int i, int j, int m) {
        int low = i, high = j-1;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(matrix[mid][m] == target) return true;
            else if(matrix[mid][m] > target) high = mid - 1;
            else if(matrix[mid][m] < target) low = mid+1;
        }
        return false;
    }
    
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0, h = m-1;
        int jmax = h;
        while(l <= h) {
            int mid = l + (h-l)/2;
            if(matrix[0][mid] == target) return true;
            else if(matrix[0][mid] > target) {
                jmax = mid-1;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        int j = 0, i = 0;
        while(j <= jmax) {
            if(helper(matrix, target, 0, n, j)) return true;
            else j++;
        }
        return false;
    }
};