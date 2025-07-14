public class Solution {
    public int CountDigitOne(int n) {

        int count=0;
        for(long factor = 1; factor<=n;factor*=10){
            long low=n%factor;
            long current = (n/factor)%10;
            long hight = n/(factor*10);
        
        if(current==0){
            count+=(int)(hight*factor);
        }
        else if (current == 1) {
                count += (int)(hight * factor + low + 1);
            }
            else {
                count += (int)((hight + 1) * factor);
            }
        }
        return count; 
    }
}
