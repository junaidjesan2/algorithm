    #include <bits/stdc++.h>
    using namespace std;
    const int MAX = 1000;
    vector<int> adj[MAX];
    void countedNodes(int node)
    {
        if (adj[node].empty())
        {
            cout << -1 << endl;
            return;
        }
        sort(adj[node].begin(), adj[node].end(), greater<int>());
        for (int connectedNode : adj[node])
        {
            cout << connectedNode << " ";
        }
        cout << endl;
    }
    int main()
    {
        int N, E;
        cin >> N >> E;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int Q;
        cin >> Q;
        while (Q--)
        {
            int X;
            cin >> X;
            countedNodes(X);
        }
        return 0;
    }