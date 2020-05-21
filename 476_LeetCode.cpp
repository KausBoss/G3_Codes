class Solution {
public:
    int findComplement(int num) {
        int mask =0;
        int n=num;
        int pos=0;
        while(n > 0){
        		mask |= (1<<pos);
        	pos++;
        	n = n>>1;
        }
        return (mask^num);
    }
};