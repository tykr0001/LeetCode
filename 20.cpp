class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        bool ans=true;

        for(auto c : s){
            if(c=='(' || c=='{' || c=='['){
                st.emplace(c);
                continue;
            }
            if(st.empty()) {
                ans=false;
                break;
            }
            char close = st.top();
            st.pop();
            if(close=='(' && c !=')') ans=false;
            if(close=='{' && c !='}') ans=false;
            if(close=='[' && c !=']') ans=false;
            if(!ans) break;
        }
        if(!st.empty()) ans = false;
        return ans;
    }
};