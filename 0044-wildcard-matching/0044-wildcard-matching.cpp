class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0, j=0, match=0, strIndex=-1;
        int len=p.size();

        while(i<s.size()){
            if(j < len && (p[j] == s[i] || p[j] == '?')){
                i++;
                j++;
            }
            else if(j<len && p[j] == '*'){
                    match = i;
                    strIndex=j;
                    j++;
                }
            
            else if(strIndex != -1){
                    j=strIndex+1;
                    match++;
                    i=match;
                }
            
            else{
                return false;
            }

        }
         while(j< len && p[j]=='*'){
             j++;
        }
            
        return j==len;
    }
};