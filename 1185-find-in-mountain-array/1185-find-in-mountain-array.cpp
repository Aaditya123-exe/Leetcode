/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int low=0,high=arr.length()-1;
        int peak=0;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            int mval=arr.get(mid);
            int lval=arr.get(mid+1);
            if(mval<lval)
            {
                low=mid+1;
            }
            else
            {
                peak=mid;
                high=mid;
            }
        }
        low=0,high=peak;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mval=arr.get(mid);
            if(mval==target)
                return mid;
            else if(mval<target)
                low=mid+1;
            else
                high=mid-1;
        }
        low=peak+1;
        high=arr.length()-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int mval=arr.get(mid);
            if(mval==target)
                return mid;
            else if(mval>target)
                low=mid+1;
            else
                high=mid-1;
        }
        return -1;
    }
};



// class Solution {
// public:
//     int findInMountainArray(int target, MountainArray &mountainArr) 
//     {
//         int start = 0;
//         int end = mountainArr.length()-1;
//         int mid = start + (end - start)/2;
//         while(start < end)
//         {
//             if(mountainArr.get(mid) < mountainArr.get(mid+1))
//                 start = mid +1;
//             else 
//                 end = mid;
//             mid = start + (end - start)/2;
//         }
//         int peak = mid;
//         start = 0;
//         end = peak;
//         mid = start + (end - start)/2;
//         while(start <= end)
//         {
//             int middle = mountainArr.get(mid);
//             if(middle == target)
//                 return mid;
//             if(middle < target )
//                 start = mid + 1;
//             else 
//                 end = mid - 1;
//             mid = start + (end - start)/2;
//         }
        
//         start = peak;
//         end = mountainArr.length()-1;
//         mid = start + (end - start)/2;
//         while(start <= end)
//         {
//             int middle = mountainArr.get(mid);
//             if(middle == target)
//                 return mid;
//             if(middle > target )
//                 start = mid + 1;
//             else 
//                 end = mid - 1;
//             mid = start + (end - start)/2;
//         }

//       return -1;
//     }
// };