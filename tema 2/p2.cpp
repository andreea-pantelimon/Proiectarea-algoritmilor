#include<cstdio>
#include<vector>
#include<algorithm>
#include<climits>
#include<fstream>
#include<queue>

const int MAX = 100005;
const int INF = 0x3f3f3f3f;

using namespace std;

int main() {
    ifstream in("p2.in");
    ofstream out("p2.out");

    int n, m, cost, x, y, start, end;
    in >> n >> m >> start >> end;

    // in vectorul adj o sa retin nodurile adiacente cu
    // costul lor
    vector<pair<int, int>> adj[MAX];

    for (int i = 0; i < m; i++) {
        in >> x >> y >> cost;
        // formez adj
        adj[x].push_back(make_pair(y, cost));
    }

    // in vectorul d retin costurile / drumul parcurs
    // in visited retin daca nodul se afla in coada q
    vector<int> d(n + 1, INF);
    bool visited[MAX];
    queue<int> q;

    // initializez visited de start si d de start
    // si introduc nodul de inceput in coada
    visited[start] = true;
    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = false;

        // parcurg vectorul adj
        for (const pair<int, int>& yc : adj[u]) {
            int v = yc.first;
            int c = yc.second;

            // conditia de relaxare care trebuie indeplinita
            if (d[u] != INF && d[v] > d[u] + c) {
                // initialiezez drumul in pozitia v
                d[v] = d[u] + c;

                if (!visited[v]) {
                    // am grija sa trec nodul ca vizitat si
                    // sa il adaug in coada
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    // in final rezultatul se va afla in d[end]
    // unde end reprezinta nodul destinatie
    out << d[end];

    // inchid fisierele
    in.close();
    out.close();

    return 0;
}
