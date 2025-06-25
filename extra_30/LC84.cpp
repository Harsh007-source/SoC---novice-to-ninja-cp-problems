class Solution {
public:
void LSE(vector<int> heights, vector<int>& l){
    stack<int> s; // stores index
    for(int i=0;i<heights.size(); i++){
        while(s.size() >0 && heights[s.top()] >= heights[i]){
            s.pop();
        }
        if(s.size() ==0){
            l.push_back(-1);
        }else{
            l.push_back(s.top());
        }
        s.push(i);
    }

}

    void RSE(vector<int> heights, vector<int>& r){
        stack<int> s;   // stores idx
        for(int i= heights.size()-1; i>=0;i--){
            while(s.size() > 0 && heights[ s.top() ] >= heights[i]){
                s.pop();
            }
            if(s.size() ==0){
                r[i] =  heights.size() ;
            }else{
                r[i] =  s.top();
            }
            s.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxA = 0;
        vector<int> l;
        vector<int> r(heights.size(), 0);
        LSE(heights, l);  // left smaller nearest
        RSE(heights, r);  // right smaller nearest
        for(int i=0; i<heights.size(); i++){
            
            int width = r[i] - l[i] -1;
            int currA = heights[i]*width;
            maxA = max(maxA, currA);
        }
        return maxA;
    }
};
