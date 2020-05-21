class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flip=0;
        while(c>0 || a>0 || b>0){
        	if(c&1){
        		if(!(a&1) && !(b&1)){
        			flip++;
        		}
        	}
        	else{
        		if(a&1){ flip++;}
        		if(b&1){ flip++;}
        	}
        	a= a>>1;
        	b= b>>1;
        	c= c>>1;
        }
        return flip;
    }
};