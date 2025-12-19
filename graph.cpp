#include <iostream>
#include <queue>

using namespace std;

class Graph {
private:
    int** adjMatrix;
    int maxVertices;
    int n;
    bool* visited;

    void DFS(int v) {
        visited[v - 1] = true;
        cout << v << " ";
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v - 1][i] == 1 && !visited[i]) {
                DFS(i + 1);
            }
        }
    }

public:
    Graph(int maxV, int currv) {
        maxVertices = maxV;
        n = currv;
        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++) {
            adjMatrix[i] = new int[maxVertices];
            for (int j = 0; j < maxVertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
        visited = new bool[maxVertices];
    }

    ~Graph() {
        for (int i = 0; i < maxVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
        delete[] visited;
    }

    Graph(const Graph& other) {
        maxVertices = other.maxVertices;
        n = other.n;
        adjMatrix = new int*[maxVertices];
        for (int i = 0; i < maxVertices; i++) {
            adjMatrix[i] = new int[maxVertices];
            for (int j = 0; j < maxVertices; j++) {
                adjMatrix[i][j] = other.adjMatrix[i][j];
            }
        }
        visited = new bool[maxVertices];
    }

    bool addVertex(int& v) {
        if (n < maxVertices) {
            n++;
            v = n;
            return true;
        }
        return false;
    }

    bool addEdge(int u, int v) {
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adjMatrix[u - 1][v - 1] = 1;
            adjMatrix[v - 1][u - 1] = 1;
            return true;
        }
        return false;
    }

    bool removeEdge(int u, int v) {
        if (u >= 1 && u <= n && v >= 1 && v <= n) {
            adjMatrix[u - 1][v - 1] = 0;
            adjMatrix[v - 1][u - 1] = 0;
            return true;
        }
        return false;
    }

    bool isEmpty() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] == 1) return false;
            }
        }
        return true;
    }

    bool isComplete() {
        if (n <= 1) return true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && adjMatrix[i][j] == 0) return false;
            }
        }
        return true;
    }

    void clear() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int Degree(int v) {
        if (v < 1 || v > n) return -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (adjMatrix[v - 1][i] == 1) count++;
        }
        return count;
    }

    void DFS() {
        for (int i = 0; i < n; i++) visited[i] = false;
        int startV;
        cout << "Enter start vertex: ";
        cin >> startV;
        if (startV >= 1 && startV <= n) {
            DFS(startV);
            for (int i = 0; i < n; i++) {
                if (!visited[i]) DFS(i + 1);
            }
        }
        cout << endl;
    }

    void BFS() {
        for (int i = 0; i < n; i++) visited[i] = false;
        int startV;
        cout << "Enter start vertex: ";
        cin >> startV;
        if (startV < 1 || startV > n) return;

        queue<int> q;
        visited[startV - 1] = true;
        q.push(startV);

        while (true) {
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                cout << curr << " ";
                for (int i = 0; i < n; i++) {
                    if (adjMatrix[curr - 1][i] == 1 && !visited[i]) {
                        visited[i] = true;
                        q.push(i + 1);
                    }
                }
            }

            bool found = false;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i + 1);
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        cout << endl;
    }
};
int main() {
    int maxV = 5, initialV = 4;
    Graph g(maxV, initialV);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    g.display();

    cout << "\nTesting Degree of vertex 1: " << g.Degree(1) << endl;

    cout << "\nDFS Traversal:" << endl;
    g.DFS();

    cout << "\nBFS Traversal:" << endl;
    g.BFS();

    return 0;
}