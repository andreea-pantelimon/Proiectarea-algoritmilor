#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#define MOD 1000000007;

int main()
{
    ifstream in("bomboane.in");
    ofstream out("bomboane.out");

    int n, m, i, j, x, y, l = 0, r = 0;
    // l si r reprezinta capetele
    //r va fi pentru x (partea inferioara a intervalului)
    //l va fi pentru y (partea superioara a intervalului)

    in >> n >> m;

    const int MAX = 2000;
    int dp[55][MAX + 5];
    dp[0][0] = 1; //caz de baza

    for(i = 1; i <= n; i++) {
        //citesc intervalele
        in >> x >> y;

        for(j = l; j <= r; j++) {
            if(j + x <= m) //am grija sa nu depasesc nr de bomboane
                dp[i][j + x] = (dp[i][j + x] + dp[i - 1][j]) % MOD;
            if(j + y <= m)
                dp[i][j + y + 1] = (dp[i][j + y + 1] - dp[i - 1][j]) % MOD;
        }

        if(l + x > m)
            //in cazul in care nr de bomboane a fost depasit
            //doresc sa revin la m!
            l = m;
        else
            l += x;

        if(r + y > m)
            //la fel ca mai sus
            r = m;
        else
            r += y;

        //adaug pe ultima pozitia valoarea obtinuta (nr total de combinari)
        for(j = l; j <= r; j++)
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
    }

    out << dp[n][m] << "\n";

    //inchid fisierele
    in.close();
    out.close();

    return 0;
}
