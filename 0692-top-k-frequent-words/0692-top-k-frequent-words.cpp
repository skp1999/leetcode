bool cmp(pair<string, int>& a, pair<string, int>& b) {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second;
    }

class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string, int> m;
        for(auto& i:words) {
            m[i]++;
        }
        
        vector<pair<string, int>> v;
        for(auto i:m) {
            v.push_back(i);
        }
        
        sort(v.begin(), v.end(), cmp);
//         for(auto i:v) {
//             cout<<i.first<<" "<<i.second<<endl;
//         }
        
        for(auto i:v) {
            if(k>0) {
                ans.push_back(i.first);
                k--;
            }
        }
        
        return ans;
    }
};