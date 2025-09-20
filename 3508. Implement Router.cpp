class Router {
public:
    int n;
    queue<string> q; // router
    unordered_map<int, vector<int>> detination_timestamp;
    unordered_map<string, vector<int>> packetStore; // string -> {S,D,T}

    Router(int memoryLimit) { n = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {

        string packet = to_string(source) + "_" + to_string(destination) + "_" +
                        to_string(timestamp);

        if (packetStore.find(packet) != packetStore.end()) {
            return false;
        }

        if (q.size() == n) {
            forwardPacket();
        }

        q.push(packet);
        packetStore[packet] = {source, destination, timestamp};
        detination_timestamp[destination].push_back(timestamp);

        return true;
    }

    vector<int> forwardPacket() {

        if (q.size() == 0) {
            return {};
        }

        string key = q.front();
        vector<int>packet = packetStore[key];
        q.pop();

        int D = packet[1];
        detination_timestamp[D].erase(detination_timestamp[D].begin());
        packetStore.erase(key);

        return packet;
    }

    int getCount(int destination, int startTime, int endTime) {

        auto it = detination_timestamp.find(destination);

        if(it == detination_timestamp.end() || it->second.empty()){
            return 0;
        }

        vector<int> &timeStamps = it->second;

        int i = lower_bound(timeStamps.begin(),timeStamps.end(),startTime) - timeStamps.begin();
        int j = upper_bound(timeStamps.begin(),timeStamps.end(),endTime) - timeStamps.begin();

        return j - i;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
