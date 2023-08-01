// Link: https://leetcode.com/problems/design-underground-system

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-underground-system
 *  RUNTIME: 161 ms
 *  MEMORY: 59.7 MB
 *  DATE: 5-31-2023, 9:48:21 AM
 *
 */

// Solution:

class UndergroundSystem {
public:
    unordered_map<int, pair<string,int>> customerLog;
    unordered_map<string, vector<double>> travelLog;
    UndergroundSystem() {
        customerLog.clear();
        travelLog.clear();
    }
    
    void checkIn(int id, string startStation, int startTime) {
        customerLog[id] = {startStation, startTime};
    }
    
    void checkOut(int id, string endStation, int endTime) {
        int startTime = customerLog[id].second;
        string startStation = customerLog[id].first;
        customerLog.erase(id);

        string travelId = startStation + '|' + endStation;
        travelLog[travelId].push_back(endTime - startTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string travelId = startStation + '|' + endStation;
        double sum = 0.0, total = travelLog[travelId].size();
        for(auto &val: travelLog[travelId]) {
            sum += val;
        }
        return sum / total;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
