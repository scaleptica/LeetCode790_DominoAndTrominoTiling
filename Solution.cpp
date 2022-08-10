class Solution {    //true=khali=1
    /*Watch video for understanding=> https://www.youtube.com/watch?v=CecjOo4Zo-g*/
public:
    int mod = 1e9 + 7;
    int makestate(bool t1, bool t2){
        if(t1&&t2){return 0;}
        if(!t1&&!t2){return 3;}
        if(t1&&!t2){return 2;}
        return 1;
    }
    
    int rec(int i, bool t1, bool t2, vector<vector<int>> &dp, int n){
        if(i==n)return 1;
        int state = makestate(t1, t2);
        if(dp[i][state]!=-1){return dp[i][state];}
        long count = 0;
        bool t3 = i+1<n;
        bool t4 = i+1<n;
        
        if(t1 && t2 && t3){count += rec(i+1, false, true, dp, n);}
        if(t1 && t2 && t4){count += rec(i+1, true, false, dp, n);}
        if(t1 && !t2 && t3 && t4){count += rec(i+1, false, false, dp, n);}
        if(!t1 && t2 && t3 && t4){count += rec(i+1, false, false, dp, n);}
        if(t1 && t2){count += rec(i+1, true, true, dp, n);}
        if(t1 & t2 & t3 & t4){count += rec(i+1, false, false, dp, n);}
        if(!t1 && !t2){count += rec(i+1, true, true, dp, n);} 
        if(t1 && !t2 && t3){count += rec(i+1, false, true, dp, n);}
        if(!t1 && t2 && t4){count += rec(i+1, true, false, dp, n);}


        return dp[i][state] = count%mod;
    }
    
    int numTilings(int n) {
        vector<vector<int>> dp(n+1, vector<int>(5, -1));
        return rec(0, true, true, dp, n);
    }
};
