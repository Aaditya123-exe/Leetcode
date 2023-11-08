class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy)
        {
            if(t==1)
                return false;
        }
        int xdiff=abs(sx-fx);
        int ydiff=abs(sy-fy);
        int maxdiff=max(xdiff,ydiff);
        if(maxdiff<=t)
            return true;
        return false;
    }
};