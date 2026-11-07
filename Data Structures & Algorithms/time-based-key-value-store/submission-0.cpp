class TimeMap {
private: 
     unordered_map<string, map<int, string>> keyTmstmpVal;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        keyTmstmpVal[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = keyTmstmpVal[key].upper_bound(timestamp);
        return it == keyTmstmpVal[key].begin() ? "" : prev(it)->second;
    }
};
