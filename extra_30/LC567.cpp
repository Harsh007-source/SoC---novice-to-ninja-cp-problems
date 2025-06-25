class Solution {
public:

    bool isFreqSame( int freq1[], int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0;i<s1.size();i++){
            freq[s1[i] - 'a']++;            // stores frequency of elements in s1
        }
        int windSize = s1.length();
        for(int i=0;i<s2.length();i++){
            int windIdx = 0;               // it is only to open window of size at each instance,  it stops while loops as
            int s2Idx = i;                 // windowIdx < windowSize
            int windFreq[26] = {0};

            while(windIdx < windSize && s2Idx < s2.length()){
                windFreq[s2[ s2Idx ] - 'a']++;
                windIdx++;s2Idx++;
            }
            if(isFreqSame(freq, windFreq)){
                return true;
            }

        }
        return false;

        }
};
