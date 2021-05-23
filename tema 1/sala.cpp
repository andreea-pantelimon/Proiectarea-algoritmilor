#include <queue>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream in("sala.in" ) ;
    ofstream out("sala.out" ) ;

    long long n, m, x, y, s = 0, ans = 0, i;

    vector <pair<long long, long long>> v;
    priority_queue<long long> q;
    //am sa folosesc de o coada de prioritati
    //pentru un timp mai bun

    in >> n >> m;

    for(i = 1; i <= n; i++) {
        in >> x >> y;
        //adaug repetarile si greutatea intr-un vector ca si perechi
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end()); //sortez vectorul in ordine crescatoare

    for (i = v.size() - 1; i >= 0; i--) {
        if (q.size() < m) { //cat timp nu depaseste nr de gantere
            q.push(-v[i].second);//adaug in coada
            s += v[i].second; //adaug la suma
        } else {
            if(v[i].second > -q.top()) { //compar repetarile
                s += q.top();
                s += v[i].second;
                q.pop();
                q.push(-v[i].second);
            }
        }
        ans = max(ans, 1LL * v[i].first * s);
    }

    out << ans << "\n";

    //inchid fisierele
    in.close();
    out.close();

    return 0;
}
