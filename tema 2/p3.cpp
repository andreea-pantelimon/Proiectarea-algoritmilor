#include<fstream>
#include<vector>
#include<iomanip>
#include<queue>

const int MAX = 100005;

using namespace std;

// vector in care retin nodurile ce formeaza path-ul
vector<int> path;

// functie pentru citirea path-ului
void printPath(vector<int> parent, int n) {
    if (parent[n] == -1) {
        path.push_back(1);
        return;
    }

    printPath(parent, parent[n]);
    path.push_back(n);
}

int main() {
    ifstream in("p3.in");
    ofstream out("p3.out");

    int n, m, x, y;
    double cost, e;
    in >> n >> m >> e;

    int source = 1;  // startul lui Robin

    vector<pair<int, double>> adj[MAX];

    for (int i = 0; i < m; i++) {
        in >> x >> y >> cost;
        // introduc muchiile in vector
        adj[x].push_back(make_pair(y, cost));
        adj[y].push_back(make_pair(x, cost));
    }

    // vectorul d va reprezenta energia - va fi initializat cu -1
    // vectorul nodes va reprezenta un vector in care retin noduri
    // vectorul visited tin evidenta nodurilor vizitate
    vector<double> d(n + 1, -1);
    vector<int> nodes(n + 1, -1);
    vector<bool> visited(n + 1, false);

    // ma folosesc de un priority_queue
    priority_queue<pair<double, int>> pq;

    // initializez startul cu energia totala si adaug in pq
    d[source] = e;
    pq.push(make_pair(d[source], source));

    while (!pq.empty()) {
        int u = pq.top().second;  // iau nodul
        pq.pop();

        if (visited[u] == false) {  // verific daca este vizitat
            for (const pair<int, double>& yc : adj[u]) {
                int v = yc.first;  // extrag din adj nodul si energia acestuia
                double cost = yc.second;

                // conditia de relaxare care trebuie indeplinita
                if (visited[v] == false && d[v] < d[u] * (1 - cost / 100)) {
                    d[v] = d[u] * (1 - cost / 100);  // schimb energia
                    pq.push(make_pair(d[v], v));
                    nodes[v] = u;
                }
            }

            visited[u] = true;
        }
    }

    // ma folosesc de set precision pentru a printa cat mai exact energia finala
    out << setprecision(13) << d[n] << "\n";
    printPath(nodes, n);

    for (int i = 0; i < path.size(); i++)
        out << path[i] << " ";

    // inchid fisierele
    in.close();
    out.close();

    return 0;
}
