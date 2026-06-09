class Solution {
public:
    unordered_map<string, vector<string>> graph;
    vector<string> res;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& flight: tickets) {
            string from = flight[0];
            string to = flight[1];
            graph[from].push_back(to);
        }

        for (auto&[from, nei]: graph)
        {
            sort(nei.begin(), nei.end(), greater<>());
        }

        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(string cur) {
        while (graph[cur].size()) {
            string dst = graph[cur].back();
            graph[cur].pop_back();
            dfs(dst);
        }
        res.push_back(cur);
    }
};
