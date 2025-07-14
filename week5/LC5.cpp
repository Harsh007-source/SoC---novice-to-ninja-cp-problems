class Solution {
public:
    string longestPalindrome(string s) {
        string LPS = "";
        for(int i=0; i<s.length(); i++){
            int low = i;
            int high = i;
            
            //odd length palin
            while(low >=0 && high<s.length() && s[low] == s[high]){
                low--; 
                high++;
            }
            
            string palin = s.substr(low+1, high-low-1);
            if(palin.length() > LPS.length()){
                LPS = palin;
            }

            //even length palin
            low = i-1;
            high = i;

            while(low >=0 && high<s.length() && s[low] == s[high]){
                low--;
                high++;
            }

            palin = s.substr(low+1, high-low-1);
            if(palin.length() > LPS.length()){
                LPS = palin;
            }
        }
        return LPS;
    }
};
