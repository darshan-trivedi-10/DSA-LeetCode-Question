#include <unordered_map>
#include <string>

class UndergroundSystem {
    struct CustomerTrack {
        std::string stationName;
        int checkInTime;
    };

    std::unordered_map<int, CustomerTrack> customerTrack;
    std::unordered_map<std::string, std::pair<double, int>> averageTime;

public:
    UndergroundSystem() {}

    void checkIn(int id, const std::string& stationName, int t) {
        customerTrack[id] = {stationName, t};
    }

    void checkOut(int id, const std::string& stationName, int t) {
        const auto& track = customerTrack[id];
        double totalTime = t - track.checkInTime;
        std::string key = track.stationName + "_" + stationName;
        averageTime[key].first += totalTime;
        averageTime[key].second++;
    }

    double getAverageTime(const std::string& startStation, const std::string& endStation) {
        std::string key = startStation + "_" + endStation;
        const auto& timeData = averageTime[key];
        return timeData.first / timeData.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
