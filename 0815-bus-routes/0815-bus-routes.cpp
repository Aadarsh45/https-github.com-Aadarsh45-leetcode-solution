class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();
        unordered_map<int, unordered_set<int>> stopToRoutes;

        for (int i = 0; i < n; ++i) {
          for (int stop : routes[i]) {
            stopToRoutes[stop].insert(i); //The routes stop is part of
            }
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedStops;  

        q.push({source, 0});
        visitedStops.insert(source);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {  //Level wise computation
                int currentStop = q.front().first;
                int busChanges = q.front().second;
                q.pop();

                for (int route : stopToRoutes[currentStop]) { //Find the routes that currentstop is part of
                    for (int nextStop : routes[route]) {
                        if (!visitedStops.count(nextStop)) {
                            if (nextStop == target) return busChanges + 1;

                            visitedStops.insert(nextStop);
                            q.push({nextStop, busChanges + 1});
                        }
                    }
                    routes[route].clear(); // Marking the route as visited since all stops part of route visited 
                }
            }
        }

        return -1;
    }
};