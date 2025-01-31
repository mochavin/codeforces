#include "bits/stdc++.h"
using namespace std;

const int MAX_NODES = 1e6 + 5;
vector<int> adjacencyList[MAX_NODES];
int weights[MAX_NODES];
int entryTime[MAX_NODES];   // DFS entry time for each node
int nodeAtEntryTime[MAX_NODES]; // Maps entry time back to node
int exitTime[MAX_NODES];    // DFS exit time (end of subtree)
int prefixMax[MAX_NODES];   // Max weight in prefix up to entryTime[i]
int suffixMax[MAX_NODES];   // Max weight in suffix from entryTime[i]
bool visited[MAX_NODES];    // To track visited nodes during DFS
int currentTime;            // Global timer for DFS

// Perform DFS to compute entry and exit times for each node
void dfs(int currentNode) {
  if (visited[currentNode]) return;
  visited[currentNode] = true;
  entryTime[currentNode] = ++currentTime;
  nodeAtEntryTime[currentTime] = currentNode;
  for (int neighbor : adjacencyList[currentNode]) {
    dfs(neighbor);
  }
  visited[currentNode] = false; // Reset for other traversals (unconventional but works for trees)
  exitTime[currentNode] = currentTime;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int testCases;
  cin >> testCases;

  while (testCases--) {
    int numberOfNodes;
    cin >> numberOfNodes;

    // Reset adjacency lists and reset currentTime (with a redundant loop, kept as original)
    for (int i = 1; i <= numberOfNodes; ++i) {
      adjacencyList[i].clear();
      currentTime = 0; // Incorrect placement, but kept as per original code
    }

    // Read node weights
    for (int i = 1; i <= numberOfNodes; ++i) {
      cin >> weights[i];
    }

    // Read and build the tree
    for (int i = 1; i < numberOfNodes; ++i) {
      int u, v;
      cin >> u >> v;
      adjacencyList[u].push_back(v);
      adjacencyList[v].push_back(u);
    }

    // Compute entry and exit times via DFS from root (node 1)
    currentTime = 0; // Correctly reset currentTime here would be better
    dfs(1);

    // Compute prefix maximums based on DFS entry order
    prefixMax[0] = 0;
    for (int i = 1; i <= numberOfNodes; ++i) {
      prefixMax[i] = max(prefixMax[i - 1], weights[nodeAtEntryTime[i]]);
    }

    // Compute suffix maximums in reverse DFS entry order
    suffixMax[numberOfNodes + 1] = 0;
    for (int i = numberOfNodes; i >= 1; --i) {
      suffixMax[i] = max(suffixMax[i + 1], weights[nodeAtEntryTime[i]]);
    }

    // Find the node with maximum weight that has a larger weight outside its subtree
    int maxValidNode = 0; // 0 indicates no valid node
    for (int i = 1; i <= numberOfNodes; ++i) {
      // Check max in prefix (before entryTime) and suffix (after exitTime)
      int maxOutside = max(prefixMax[entryTime[i] - 1], suffixMax[exitTime[i] + 1]);
      if (maxOutside > weights[i] && weights[i] > weights[maxValidNode]) {
        maxValidNode = i;
      }
    }

    cout << maxValidNode << '\n';
  }
}