class Solution {
public:
    string simplifyPath(string path) {
        string token ;
        stringstream part(path);
        stack<string>st;

        //tokenize the path on basis of '/' i.e. extract chars btw / /
        while(getline(part, token, '/')){
            if(token =="" || token == "."){
                continue;
            }

            if(token != ".."){
                st.push(token);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
            
        }
        if(st.empty()){
            return "/";
        }

        string ans="";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop(); 
        }

        return ans;
    }
};
