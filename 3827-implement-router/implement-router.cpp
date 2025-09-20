
class Router {
public:
    map<int, vector<int>> mp;  
    queue<pair<pair<int, int>, int>> q;
    multiset<pair<pair<int, int>, int>> st;
    int sz;
    
    Router(int memoryLimit) { sz = memoryLimit; }

    bool addPacket(int s, int d, int t) {
        pair<pair<int, int>, int> nw = {{s, d}, t};
        if (st.find(nw) != st.end()) {
            return false;
        }
        q.push(nw);
        
        auto& timestamps = mp[d];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), t);
        timestamps.insert(it, t);
        
        st.insert(nw);
        
        if (q.size() > sz) {
            pair<pair<int, int>, int> fr = q.front();
            int sta = fr.first.first;
            int des = fr.first.second;
            int time = fr.second;
            
            // Remove from mp[des]
            auto& timestamps = mp[des];
            auto it = lower_bound(timestamps.begin(), timestamps.end(), time);
            if (it != timestamps.end() && *it == time) {
                timestamps.erase(it);
            }
            
            // Remove from st
            auto st_it = st.find({{sta, des}, time});
            if (st_it != st.end()) {
                st.erase(st_it);
            }
            
            q.pop();
        }
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty()) {
            return {};
        }

        pair<pair<int, int>, int> fr = q.front();
        int sta = fr.first.first;
        int des = fr.first.second;
        int time = fr.second;
        
        auto& timestamps = mp[des];
        auto it = lower_bound(timestamps.begin(), timestamps.end(), time);
        if (it != timestamps.end() && *it == time) {
            timestamps.erase(it);
        }
        
        auto st_it = st.find({{sta, des}, time});
        if (st_it != st.end()) {
            st.erase(st_it);
        }
        
        q.pop();
        return {sta, des, time};
    }

    int getCount(int des, int sta, int end) {
        auto& timestamps = mp[des];
        if (timestamps.empty()) return 0;
        
        auto lower = lower_bound(timestamps.begin(), timestamps.end(), sta);
        auto upper = upper_bound(timestamps.begin(), timestamps.end(), end);
        
        return distance(lower, upper);
    }
};