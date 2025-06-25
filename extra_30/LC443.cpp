class Solution {
public:
    int compress(vector<char>& chars) {
        int idx =0;
        for(int i=0;i<chars.size();i++){
            char curr = chars[i];
            int count = 0;
            while(i<chars.size() && chars[i] == curr){
                count ++;
                i++;
            }
            if(count == 1){
                chars[idx] = curr;
                idx++;
            }
            else if(count >1){
                chars[idx] = curr;
                idx++;
                string str = to_string(count);
                for(char val : str){
                    chars[idx] = val;
                    idx++;
                }
                 
            }
            i--;
           
        }
        chars.resize(idx);
        return chars.size();
    }
};
