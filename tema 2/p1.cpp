#include<cstdio>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

// structura folosita - retin muchiile
struct links{
    int x, y;
};

// arrayul corrupted va retine orasele cu garzi /  in care lorzii cauta
// vectorul towns pastreaza permutarea oraselor
// vectorul mat retine muchiile bidirectionale
// occupied retine orasele ocupate / blocate
// viz retine orasele vizitate
vector<links>mat;
bool corrupted[100005], occupied[100005], viz[100005];
int start[100005];
vector<int>towns;
int lastpoz = 0, ok = 0;

// functie ce imi realizeaza compararea
bool cmp(links a, links b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

// functia dfs
void dfs(int n) {
    int poz = start[n];
    viz[n] = 1;  // initializez pozitia trimisa ca fiind vizitata

    while (mat[poz].x == n) {
        int wow = mat[poz].y;

        // verific ca orasul sa nu fie vizitat si blocat
        if ((viz[mat[poz].y] == 0) && (occupied[mat[poz].y] == 0)) {
            // verific ca orasul sa nu fie ocupat de garzi
            if (corrupted[mat[poz].y] == 1)
                ok = 1;  // atunci nu se poate merge
            else
                dfs(mat[poz].y);
        }

        poz++;
        if (ok == 1)
            break;
    }
}

// functie care face verificarea pentru blocarea oraselor
bool check(int poz) {
    // am sa umplu array-ul occupied cu orasele blocate
    if (lastpoz <= poz) {
        for (int i = lastpoz; i <= poz; i++)
            occupied[towns[i]] = 1;
    } else {
        for (int i = lastpoz; i > poz; i--)
            occupied[towns[i]] = 0;
    }

    // variabila care sa ma ajute sa vad daca conditia este indeplinita
    ok = 0;
    // initializez orasul 1 (de unde incep cautarile) ca fiind nevizitat
    viz[1] = 0;

    for (int i = 0; i < towns.size(); i++)
        viz[towns[i]] = 0;

    dfs(1);  // aplic dfs incepand cu primul oras
    lastpoz = poz;

    return ok;
}

int main() {
    ifstream in("p1.in");
    ofstream out("p1.out");

    int n, m, k, x, y;
    in >> n >> m >> k;

    for (int i = 1; i <= k; i++) {
        in >> x;
        // initilizez orasele cu garzi cu 1
        corrupted[x] = 1;
    }

    for (int i = 1; i < n; i++) {
        in >> x;
        // retin permutarile
        towns.push_back(x);
    }

    links help;

    for (int i = 1; i <= m; i++) {
        in >> x >> y;
        // adaug muchiile bidirectionale in mat
        help.x = x;
        help.y = y;
        mat.push_back(help);
        help.x = y;
        help.y = x;
        mat.push_back(help);
    }

    // ordonez muchiile in ordine crescatoare
    sort(mat.begin(), mat.end(), cmp);

    // umplu array-ul start cu pozitia din care incep
    // legaturile cu nodul n din mat
    for (int i = 0; i < mat.size(); i++) {
        start[mat[i].x] = i;
        i++;
        // doresc sa evit muchile cu acelasi inceput / x
        while (mat[i-1].x == mat[i].x)
            i++;
        i--;
    }

    int st = 0, dr = n-1, med, ans;

    while (st <= dr) {
        // iau med mijlocul sumei celor doua contoare
        med = (st + dr) >> 1;
        int c = check(med);

        // in functie de rezultat deplsez contoarele
        if (c == 0) {
            // daca conditia e indeplinita, retin pozitia med ca raspun
            // si me deplasez cu contorul dr in dreapta cu 1 fata de med;
            ans = med;
            dr = med -1;
        } else {
             st = med + 1;
        }
    }

    out << ans + 1;

    // inchid fisierele
    in.close();
    out.close();

    return 0;
}
