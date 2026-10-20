#include <bits/stdc++.h>
#define ll long long int
#define INF 1000000000000000
#define pb push_back

using namespace std;

// Adjacency List to store the weighted graph
vector<pair<ll, ll> > graph[2501];

// array to store the distance to any node
ll dist[2501];
// array to store the parent of any node
ll par[2501];
// array to store the number of time a node has been relaxed
ll cnt[2501];

ll n, m, u, v, w, q;
// array to keep track of whether a node is already in the
// queue
bool in_queue[2501];
// array to keep track of visited nodes
bool visited[2501];
ll x;

// Function to run Shortest Path Fast Algorithm
bool spfa(ll start)
{
    // Initialize the distance of starting node = 0
    dist[start] = 0;
    // Initialize the parent of starting node = -1
    par[start] = -1;

    // Queue to run SPFA
    queue<ll> q;

    // Push the starting node in the queue
    q.push(start);
    in_queue[start] = true;

    while (!q.empty()) {
        // Pop the front element of the queue
        ll ele = q.front();
        visited[ele] = true;
        in_queue[ele] = false;
        q.pop();
        // Iterate over all the children of the current node
        for (auto child : graph[ele]) {
            // If the distance to the child node is greater
            // than the distance of the current node + edge
            // weight, then relax the child node
            if (dist[child.first]
                > dist[ele] + child.second) {
                // Incrment the relaxation count of the
                // child node
                cnt[child.first]++;
                // If the child has been relaxed more than n
                // times, then there is a cycle
                if (cnt[child.first] > n) {
                    x = child.first;
                    par[child.first] = ele;
                    return false;
                }
                // Update the minimum distance to the child
                // node
                dist[child.first]
                    = dist[ele] + child.second;
                // Push the child node if it is already not
                // in queue
                if (!in_queue[child.first]) {
                    q.push(child.first);
                    in_queue[child.first] = true;
                }
                // Update the parent of the child node with
                // the current node
                par[child.first] = ele;
            }
        }
    }
    return true;
}
int main()
{
    cin>>n>>m;
    // Initialize the distance to all nodes as INF
    for (int i = 0; i <= n; i++)
        dist[i] = INF;
    vector<vector<ll> > edges;
    for(int i=0;i<m;i++){
        int v1,v2; 
        long int w; 
        cin>>v1>>v2>>w; 
        edges.push_back({v1,v2,w});
    }
    for (ll i = 0; i < m; i++) {
        graph[edges[i][0]].push_back(
            { edges[i][1], edges[i][2] });
    }
    for (ll i = 1; i <= n; i++) {
        // If there is a negative weight cycle in the graph
        if (!spfa(i)) {
            cout << "YES" << endl;
            ll ele = x;
            stack<ll> st;
            bool is_stack[2501] = {};
            // Push all the elements in the stack using the
            // parent array
            while (!is_stack[ele]) {
                is_stack[ele] = true;
                st.push(ele);
                ele = par[ele];
            }
            // Print all the nodes in the negative weight
            // cycle
            cout << ele << " ";
            while (st.top() != ele) {
                cout << st.top() << " ";
                st.pop();
            }
            cout << ele << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
