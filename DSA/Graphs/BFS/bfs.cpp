//Will be using vectors instead of linked lists, can also be done with std :: list or std :: forward_list in the STL
#include<iostream>
#include<list>
#include<map>
using namespace std;

void printGraph(map<int, list<int> >& grph, int n) {
    cout << "\nThe Adjacency List representation of the graph: \n";
    for(int i=0; i<n; i++) {
        cout << "Vertex " << i << " -> ";
        for(auto x : grph[i]) {
            cout << x << " -> ";
        }
        cout << "NULL";
        cout << endl;
    }
}

void BFS(map<int, list<int> >& grph, int v, int root) {
    bool visited[v];
    for(int i=0; i<v; i++) {
        visited[i] = false;
    }
    list<int> queue;
    queue.push_back(root);
    while(!queue.empty()) {
        root = queue.front();
        if(!visited[root]) {
            visited[root] = true;
            cout << root << " ";
            for(auto x: grph[root]) {
                queue.push_back(x);
            }
        }
        queue.pop_front();
    }
    cout << endl;
}

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    map<int, list<int> > grph;
    cout << "Enter the number of edges: ";
    int e;
    cin >> e;
    for(int i=0; i<e; i++) {
        int v1, v2;
        cout << "Enter the edges (u, v): ";
        cin >> v1 >> v2;
        grph[v1].push_back(v2);
    }
    for(auto x : grph) {
        x.second.sort();
    }
    printGraph(grph, v);
    BFS(grph, v, 0);
    return 0;
}