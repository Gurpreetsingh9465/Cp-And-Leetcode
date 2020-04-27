class Solution {
public:
    
    
    bool cust_bs(vector<vector<int>> &matrix, int target, int j) {
        int low = 0;
        int high = matrix.size()-1;
        int mid;
        while(low<=high) {
            mid = (high+low)/2;
            if(matrix[mid][j] == target) {
                return true;
            }
            if(matrix[mid][j] > target) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        if(matrix[0].size() == 0)
            return 0;
        int j_h = lower_bound(matrix[0].begin(), matrix[0].end(), target) - matrix[0].begin();
        
        if(j_h == matrix[0].size())
            j_h--;
        if(matrix[0][j_h] == targset)
            return true;
        
        for(int j=0;j<=j_h;j++) {
            if(cust_bs(matrix,target,j)) {
                return true;
            }
        }
        return false;
    }
};