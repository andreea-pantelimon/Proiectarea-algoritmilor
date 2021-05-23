#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

#define MOD 1000000007;

int main() {
    ifstream in("bani.in");
    ofstream out("bani.out");

    int n;
    int type;
    int methods = 1;
    in >> type;
    in >> n;
    int lookup[n + 1][5];


    if(n == 1) //caz de baza
        methods = 5;
    if(n > 1) {
        if(type == 1) {
            for(int i = 0; i < n - 1; i++) {
                //aplic formula de care am spus in readme
                methods = (1LLU * methods * 2) % MOD;
            }
            methods = (1LLU * methods * 5) % MOD;
        } else if(type == 2) {
            //pe coloana 0 - bacnota de 10, pe coloana 1 - bacnota de 50
            //pe coloana 2 - bacnota de 100, pe coloana 3 - bacnota de 200
            //pe coloana 4 - bacnota de 500
            for(int j = 0; j < 5; j++) {
                //initializez pentru 0 si 1 bacnota nr total de modalitati
                lookup[0][j] = 0;
                lookup[1][j] = 1;
            }

            for(int i = 2; i <= n; i++) {
                //aplic formulele pentru fiecare bacnota in parte
                lookup[i][0] = (1LLU * lookup[i - 2][0] * (i - 2)) % MOD;
                lookup[i][0] = (lookup[i][0] + lookup[i - 1][0] + 2) % MOD ;
                lookup[i][1] = (lookup[i - 1][1] + (i - 1)+(i - 2)) % MOD;
                lookup[i][2] = (lookup[i - 1][2] - lookup[i - 2][2] + i*(i - 1)) % MOD;
                lookup[i][3] = (lookup[i - 1][2] + lookup[i - 1][3] - 2 * lookup[i - 2][3]) % MOD;
                lookup[i][4] = (lookup[i - 1][4] + (i - 2)) % MOD;
            }
            //adun elementele de pe ultima linie
            methods = (lookup[n][0] + lookup[n][1] + lookup[n][2] + lookup[n][3] + lookup[n][4]) % MOD;
        }
    }

    out << methods << "\n";

    //inchid fisierele
    in.close();
    out.close();

    return 0;
}