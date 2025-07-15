public class Solution {
    public int LongestValidParentheses(string s) {
        int len=0;
        Stack<int> st = new Stack<int>();
        st.Push(-1);
        int maxLen=0;
        for(int i=0;i<s.Length;i++){
            if(s[i]=='('){
                st.Push(i);
            }
            else{
                int temp = st.Pop();
                if(st.Count==0){
                    st.Push(i);
                }
                else{
                    maxLen = Math.Max(maxLen,i-st.Peek());
                }
            }
        }
        return maxLen;
    }
}