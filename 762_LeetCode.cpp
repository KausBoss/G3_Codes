class Solution {
public:
    int countPrimeSetBits(int L, int R) {
         int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
         int n = sizeof(prime)/sizeof(int);
         int ans=0;
         for(int i=L; i<=R; i++){
         	int bit = __builtin_popcount(i);
         	for(int j=0; j<n; j++){
         		if(prime[j] == bit){
         			ans++;
         			break;
         		}
         	}
         }
         return ans;
    }
};