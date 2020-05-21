class Solution {
public:
    int totalHammingDistance(vector<int> N) {
        int n=N.size();
        int bit=0;
        for(auto x:N){
        	if(x!=0)bit = max(bit, (int)floor(log2(x)));
        }
        int ans=0;
        for(int i=0; i<=bit; i++){
        	int mset=0, nset=0;
        	for(int j=0; j<n; j++){
        		if(N[j]&1){
        			mset++;
        		}
        		else{
        			nset++;
        		}
        		N[j] = N[j]>>1;
        	}
        	ans += mset*nset;
        }
        return ans;
    }
};