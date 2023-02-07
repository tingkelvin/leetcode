#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    map<int, vector<int>> roadMap;
    map<int, int> roadSize;
    priority_queue<pair<int, int>>pq;

    for(auto& road: roads){
        roadMap[road[0]].push_back(road[1]);
        roadMap[road[1]].push_back(road[0]);
        roadSize[road[0]]++;
        roadSize[road[1]]++;
    }

    for(auto itr = roadSize.begin(); itr != roadSize.end(); itr++){
        pq.push(make_pair(itr->second, itr->first));
    }

    int maxRank = 0;

    maxRank += pq.top().first;
    int firstCity = pq.top().second;
    pq.pop();

    int secondCity = pq.top().second;
    int secondRank = pq.top().first;
    pq.pop();

    if(find(roadMap[firstCity].begin(), roadMap[firstCity].end(), secondCity) == roadMap[firstCity].end()){
        return maxRank + secondRank;
    }
    while(pq.size()){
        if(pq.top().second != secondRank)
            break;
        if(find(roadMap[firstCity].begin(), roadMap[firstCity].end(), pq.top().first) == roadMap[firstCity].end()){
            return maxRank + pq.top().second;
        }
        pq.pop();
    }

    return maxRank + secondRank - 1;
    // for(auto& i : roadSize){
    //     cout << i.first << " " << i.second << endl;
    // }


    return -1;
}


int main() {
    int n = 4;
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}};
    cout << maximalNetworkRank(n, roads) << endl;

    n = 5;
    roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << maximalNetworkRank(n, roads) << endl;

    n = 8;
    roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    cout << maximalNetworkRank(n, roads) << endl;
    //
    // n = 8;
    // roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7},{4,5}};
    // cout << maximalNetworkRank(n, roads) << endl;
    //
    // n = 8;
    // roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7},{4,5},{0,4}};
    // cout << maximalNetworkRank(n, roads) << endl;
    // return 0;
}
