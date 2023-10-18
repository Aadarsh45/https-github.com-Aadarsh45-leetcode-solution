#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> startNodes;
    std::vector<std::vector<int>> graph;
    std::vector<int> time;
    std::vector<bool> visited;
    std::vector<int> ans;

    void toGraph(std::vector<std::vector<int>>& edges, int n) {
        std::vector<int> incoming(n, 0);
        std::vector<int> outgoing(n, 0);
        for (const auto& e : edges) {
            outgoing[e[0] - 1]++;
            incoming[e[1] - 1]++;
        }
        int startCnt = 0;
        for (int i : incoming) {
            if (i == 0) {
                startCnt++;
            }
        }
        startNodes.resize(startCnt);
        int sni = 0;
        for (int i = 0; sni < startNodes.size(); i++) {
            if (incoming[i] == 0) {
                startNodes[sni++] = i;
            }
        }
        graph.resize(n);
        for (int i = 0; i < n; i++) {
            graph[i].resize(outgoing[i]);
        }
        for (const auto& e : edges) {
            graph[e[0] - 1][--outgoing[e[0] - 1]] = e[1] - 1;
        }
    }

    int calculate(int node) {
        if (ans[node] > 0) {
            return ans[node];
        }

        int worstPrereq = 0;
        visited[node] = true;
        for (int child : graph[node]) {
            if (!visited[child]) {
                worstPrereq = std::max(calculate(child), worstPrereq);
            }
        }
        visited[node] = false;
        ans[node] = worstPrereq + time[node];
        return ans[node];
    }

    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {
        toGraph(relations, n);
        this->time = time;
        ans.resize(n);
        visited.assign(n, false);
        int longest = 0;
        for (int node : startNodes) {
            longest = std::max(longest, calculate(node));
        }
        return longest;
    }
};