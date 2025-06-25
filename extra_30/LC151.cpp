class Solution {
public:
    string reverseWords(string s) {          // O(n)
        reverse(s.begin(), s.end());
        string ans = "";              
        
        for(int i= 0;i<s.size(); i++){
            string word = "";
            while(i<s.size() && s[i] != ' '){
                word = word + s[i];
                i++;
            }
            if(word.size() >0){
                reverse(word.begin(), word.end());
                ans = ans + word+' ';                  // -----> for loop i++
            }
            
        }
        ans.erase(ans.size()-1,1);
        return ans;
    }
};
