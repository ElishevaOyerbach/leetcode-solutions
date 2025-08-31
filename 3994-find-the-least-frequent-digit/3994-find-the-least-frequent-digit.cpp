class Solution {
public:
    int getLeastFrequentDigit(int n) {
        n=llabs(n);
        int freq[10] = {0};

        if(n==0) return 0;

        while(n>0){
            int d = n%10;
            freq[d]++;
            n/=10;
        }
        int ans = -1, minF = INT_MAX;
        for(int d=0; d<=9; d++){
            if(freq[d]>0){
                if(freq[d]<minF ||( freq[d]==minF && d<=ans)){
                    minF = freq[d];
                    ans=d;
                }
            }
        }
        return ans;
    }
};