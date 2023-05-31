class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, std::string stationName, int t) {
        checkInData[id] = {stationName, t};
    }
    
    void checkOut(int id, std::string stationName, int t) {
        auto& [startStation, startTime] = checkInData[id];
        std::string route = startStation + "_" + stationName;
        totalTime[route] += t - startTime;
        tripCount[route]++;
    }
    
    double getAverageTime(std::string startStation, std::string endStation) {
        std::string route = startStation + "_" + endStation;
        return static_cast<double>(totalTime[route]) / tripCount[route];
    }

private:
    std::unordered_map<int, std::pair<std::string, int>> checkInData;
    std::unordered_map<std::string, int> totalTime;
    std::unordered_map<std::string, int> tripCount;
};
