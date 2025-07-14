class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans = 0;

        for(int i=0; i<s.length(); i++){
            char a = s[i];
            if(a=='('){     //opening
                st.push(i);
            }else{          // closing
                st.pop();
                if(st.empty()){  // empty
                    st.push(i);
                }else{           // not empty
                    int len = i-st.top();
                    ans = max(ans, len);
                }
            }
        }
        return ans;
        
    }
};
