#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Edge;
void dijkstra(int source, vector<vector<Edge>>&graph, vector<int>&distances){
    priority_queue<Edge, vector<Edge>, greater<Edge>>pq;
    pq.push({0, source});
    distances[source]=0;
    while(!pq.empty()){
        int current_dist = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();
        if(current_dist > distances[current_vertex]) continue;
        for(auto &neighbor : graph[current_vertex]){
            int weight = neighbor.first;
            int next_vertex = neighbor.second;

            if(distances[current_vertex]+weight < distances[next_vertex]){
                distances[next_vertex] = distances[current_vertex]+weight;
                pq.push({distances[next_vertex],next_vertex});
            }
        }
    }
}

int main(){
    int vertices, edges;
    cout<<"Enter the number of vertices and edges: ";
    cin>>vertices>>edges;
    vector<vector<Edge>> graph(vertices+1);
    cout<<"Enter the edges (start_vertex end_vertex weight): "<<endl;
    for(int i = 0; i < edges; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
    int source;
    cout<<"Enter the source vertex: ";
    cin>> source;
    vector<int> distances(vertices+1, INT_MAX);
    dijkstra(source, graph, distances);

    cout<<"Shortest distances from source vertex "<<char(source+'A')<<":"<<endl;
    for(int i = 0; i<vertices; i++){
        cout<<"Vertex "<<char(i+'A')<<":"<<(distances[i]== INT_MAX ? "INF":to_string(distances[i]))<<endl;
    }
}
/*Input
7 13
0 1 1
0 2 3
1 3 7
1 4 5
1 2 1
1 6 2
2 4 3
2 3 9
3 6 12
3 5 1
3 4 2
4 5 2
5 0 10
*/
