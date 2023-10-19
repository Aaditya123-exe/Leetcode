class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int row=0;
        while(l<=r)
        {
            long mid=(l+r)/2;
            if(matrix[mid][0]==target)
                return true;
            if(matrix[mid][0]<target)
            {
                row=mid;
                l=mid+1;
            }
            else
                r=mid-1;   
        }
        int col=lower_bound(matrix[row].begin(),matrix[row].end(),target)-matrix[row].begin();
        int val=matrix[row][(col<matrix[0].size())?col:matrix[0].size()-1];
        return val==target;
    }
};