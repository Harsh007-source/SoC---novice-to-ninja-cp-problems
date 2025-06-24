class Solution {
public:
    string removeOccurrences(string s, string part) {
        int l = part.size();
        while(s.find(part)<s.size()){
        int a = s.find(part);
        s.erase(a,l);
        }
        return s;
    }
};
