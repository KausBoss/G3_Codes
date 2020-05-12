//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
class Solution {
public:
    int maxProfit(vector<int> p) {
    	int n=p.size();
        if(n==0){return 0;}
        int min_seen=p[0];
        int last = 0;
        vector<int> seedha(n, 0);
        for(int i=1; i<n; i++){
        	seedha[i] = (p[i]-min_seen > last) ? p[i]-min_seen:last;
        	last = seedha[i];
        	min_seen = min(min_seen, p[i]);
        }
         vector<int> ulta(n, 0);
        int max_seen=p[n-1];
        last=0;
        for(int i=n-1; i>=0; i--){
        	ulta[i]=max_seen-p[i]>last?max_seen-p[i]:last;
        	last = ulta[i];
        	max_seen = max(max_seen, p[i]); 
        }
        int ans=-1;
        for(int i=0; i<n-1; i++){
        	ans = max(ans, seedha[i]+ulta[i+1]);
        }
        ans = max(ans, max(seedha[n-1], ulta[0]));
        return ans;
    }
};