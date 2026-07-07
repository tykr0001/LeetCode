class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);
        reverse(str.begin(), str.end());
        n = stoll(str);
        long long sum=0;
        long long x=0;
        while(n>0){
            if(n%10==0) {
                n/=10;
                continue;
            }
            sum+=n%10;
            x*=10;
            x+=n%10;
            n/=10;
        }
        return x*sum;
    }
};