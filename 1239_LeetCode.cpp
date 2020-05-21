class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<string> v;
        for(auto x: arr){
        	bool np=false;
        	int freq[26]={0};
        	for(auto y: x){
        		freq[y - 'a']++;
        		if(freq[y-'a'] > 1){
        			np=true;
        			break;
        		}
        	}
        	if(!np){ v.push_back(x);}
        }
        int n=v.size();
        vector<int> bit(n, 0);

        for(int i=0; i<n; i++){
        	for(int j=0; j<v[i].size(); j++){
        		bit[i] |= (1<<(v[i][j] - 'a'));
        	}
        }

        int ans=0;

        for(int i=0; i<(1<<n); i++){
        	int len, an, pos, t=i;
        	len = pos = 0;
            an = -1;
        	while(t > 0){
        		if(t&1){
        			len += v[pos].length();
        			if(an == -1){
                        an = bit[pos];
                    }
                    else{
                        an &= bit[pos];
                        if (an > 0){
                            len = INT_MIN;
                        }
                    }
        		}
        		pos++;
        		t = t>>1;
        	}
        	if(an == 0){
                cout<<len<<" "<<i<<endl;
        		ans = max(ans, len);
        	}
        }
        return ans;
    }
};