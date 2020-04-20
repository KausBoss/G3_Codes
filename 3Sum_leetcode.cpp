    int threeSumClosest(vector<int>& nums, int target) {
        int close=INT_MAX;
        bool flag = false;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            if(flag){
                break;
            }
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1, right =n-1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                int diff = abs(target - sum);
                close = min(close, diff);
                if(sum < target){
                    left++;
                }
                if(sum > target){
                    right--;
                }
                if(diff == 0){
                    close = 0;
                    flag = true;
                    break;
                }
            }
            
        }
        return close;
    }