#include <bits/stdc++.h>

using namespace std;
#define ll long long

int lengthOfLIS(vector<int>& nums) {
    if(nums.size()==0){return 0;}
    int dp[nums.size()];
    for(int i=0; i<nums.size();i++){
        dp[i]=1;
    }
    int ans=1;
    for(int i=1; i<nums.size(); i++){
    	for(int j=0; j<i; j++){
    		if(nums[i]>nums[j] && dp[j]+1 > dp[i]){
    			dp[i]=dp[j]+1;
    		}
    	}
    	ans=max(ans, dp[i]);
    }
    return ans;
}


int printVal(vector<int> nums){
	if(nums.size()==0){return 0;}
	int print[nums.size()];
	for(int i=0; i<nums.size();i++){
		print[i]=-1;
	}
	int start=0;
    int dp[nums.size()];
    for(int i=0; i<nums.size();i++){
        dp[i]=1;
    }
    int ans=1;
    for(int i=1; i<nums.size(); i++){
    	for(int j=0; j<i; j++){
    		if(nums[i]>nums[j] && dp[j]+1 > dp[i]){
    			dp[i]=dp[j]+1;
    			print[i]=j;
    		}
    	}
    	if(dp[i]>ans){start=i;}
    	ans=max(ans, dp[i]);
    }
    while(print[start]!=-1){
    	cout<<nums[start]<<" ";
    	start =print[start];
    }

    cout<<nums[start]<<endl;
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	vector<int> v{10,9,2,5,3,7,101,18};
	cout<<printVal(v); 
}

//top down approach
//try for printing the elements
