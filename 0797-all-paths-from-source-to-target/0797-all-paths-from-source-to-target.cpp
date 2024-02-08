class Solution {
public:
    void dfs(vector<vector<int>>& graph, int curr, vector<int>& path, vector<vector<int>>& result) {
        // 현재 노드가 (n-1) 노드이면, 찾은 path를 result에 추가
        if (curr == graph.size()-1) {
            result.push_back(path);
            return;
        }
        
        // 현재 노드의 adj를 돌면서,
        for (int i=0; i<graph[curr].size(); i++) {
            path.push_back(graph[curr][i]);             // path에 방문한 노드 추가
            dfs(graph, graph[curr][i], path, result);   // recursive하게 반복
            path.erase(path.end()-1);                   // result에 추가한 path는 지우기
        }
        return;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path {0};
        dfs(graph, 0, path, result);
        return result;
    }
};