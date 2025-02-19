class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> events;
        
        for (auto& b : buildings) {
            events.emplace_back(b[0], -b[2]);
            events.emplace_back(b[1], b[2]);  
        }
        sort(events.begin(), events.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second; 
            return a.first < b.first; 
        });

        multiset<int> heights = {0}; 
        vector<vector<int>> skyline;
        int prevHeight = 0;

        for (auto& [x, h] : events) {
            if (h < 0) { 
                heights.insert(-h); 
            } else {
                heights.erase(heights.find(h)); 
            }
            
            int currHeight = *heights.rbegin();
            
            if (currHeight != prevHeight) {
                skyline.push_back({x, currHeight});
                prevHeight = currHeight;
            }
        }

        return skyline;
    }
};
