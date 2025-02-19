class Solution {
public:
    const int MOD = 1337;
    int powerMod(int x, int y) {
        int res = 1;
        x %= MOD; 
        while (y > 0) {
            if (y % 2 == 1) { 
                res = (res * x) % MOD;
            }
            x = (x * x) % MOD;
            y /= 2;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1; 
        
        int lastDigit = b.back();
        b.pop_back();
        
        int part1 = powerMod(superPow(a, b), 10) % MOD; 
        int part2 = powerMod(a, lastDigit) % MOD; 
        
        return (part1 * part2) % MOD;
    }
};
