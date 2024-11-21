#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Graph {
private:
    unordered_map<string, unordered_set<string>> adjList;

public:
    void printGraph() {
        for (auto [vertex, edges] : adjList) {
            cout << vertex << ": [";
            for (auto edge : edges) {
                cout << edge << " ";
            }
            cout << "]" << endl;
        }
    }

    bool addVertex(string vertex) {
        if (adjList.count(vertex) == 0) {
            adjList[vertex];
            return true;
        }
        return false;
    }

    bool addEdge(string vertex1, string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).insert(vertex2);
            adjList.at(vertex2).insert(vertex1);
            return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2) {
        if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    bool removeVertex(string vertex) {
        if (adjList.count(vertex) == 0) return false;
        for (auto otherVertex : adjList.at(vertex)) {
            adjList.at(otherVertex).erase(vertex);
        }
        adjList.erase(vertex);
        return true;
    }

    vector<string> bfs(string start) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            string current = q.front();
            q.pop();
            result.push_back(current);

            for (const string& neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return result;
    }

    vector<string> dfs(string start) {
        vector<string> result;
        unordered_set<string> visited;
        stack<string> s;

        s.push(start);

        while (!s.empty()) {
            string current = s.top();
            s.pop();

            if (visited.find(current) == visited.end()) {
                visited.insert(current);
                result.push_back(current);

                for (const string& neighbor : adjList[current]) {
                    if (visited.find(neighbor) == visited.end()) {
                        s.push(neighbor);
                    }
                }
            }
        }

        return result;
    }
};
