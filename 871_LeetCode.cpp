#include <bits/stdc++.h>

using namespace std;
#define ll long long

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> pq;
    int ret = 0, stationId = 0, range = startFuel;
    while (range < target) {
        while (stationId < stations.size() && stations[stationId][0] <= range) {
            pq.push(stations[stationId++][1]);
        }
        if (pq.empty()) return -1;
        range += pq.top();
        pq.pop();
        ++ret;
    }
    return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	// vector<vector<int>> v{{13,21},{26,115},{100,47},{225,99},{299,141},{444,198},{608,190},{636,157},{647,255},{841,123}};
	// int Fuel=299;
	// int target=1000;
    vector<vector<int>> v{{10,60},{20,30},{30,30},{60,40}};
    int Fuel=10;
    int target=100;
	cout<<minRefuelStops(target, Fuel, v);
}