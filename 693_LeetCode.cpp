class Solution {
public:
    bool hasAlternatingBits(int n) {
        long long ans = (n^(n>>1));
        ans++;
        cout<<ans;
        return __builtin_popcountll(ans)==1;
    }
};