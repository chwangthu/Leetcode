//Feb 12 2018
//If tx == ty the process must be stopped, directedly judge
//Assume tx > ty
//1) If sy == ty, you can only substract tx by ty, directedly judge
//2) If sy < ty, still substract tx by ty utill tx < ty, that is tx % ty 
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(tx < sx || ty < sy) return false;
        if(tx == ty) return (sx == sy && sx == tx);
        //tx > ty
        if(tx < ty) //let tx be always the bigger one
        {
            swap(sx, sy);
            swap(tx, ty);
        }
        if(sy == ty) return ((tx - sx) % ty == 0);
        return reachingPoints(sx, sy, tx % ty, ty); //ty > sy
    }
};