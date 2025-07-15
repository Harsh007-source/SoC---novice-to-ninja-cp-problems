class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long size = 0; // actual size of tape
        for(int i=0; i<s.length(); i++){
            if(s[i] >= '1' && s[i] <= '9'){
                size = size*(s[i] - '0');
            }else{
                size++;
            }
        }

        for(int i=s.length()-1; i>=0; i--){
            k = k%size;
            if(k==0 && s[i] >='a' && s[i] <= 'z'){  // s[i] is a alpha
                string temp;
                temp.push_back(s[i]);
                return temp;
            }
            else if(k !=0 && s[i] >='a' && s[i] <= 'z'){
                size = size-1;
            }
            if(s[i] >= '1' && s[i] <= '9' ){  //s[i] is numeric
                size = size/(s[i] - '0');
            }
        }
        return "";
    }
};
