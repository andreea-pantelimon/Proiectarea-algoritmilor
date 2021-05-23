#include<iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct ItemValue {//structura ce contine x-ul si y-ul unui gard
    int start;
    int end;
};

bool compareFence(ItemValue &o1, ItemValue &o2) {
    if (o1.start == o2.start)
        return (o1.end > o2.end);//sortare descrescatoare functie de end
    return (o1.start < o2.start);//sortare crescatoare functie de start
}

int main() {
    ifstream in("gard.in");
    ofstream out("gard.out");

    int n;

    in >> n;

    ItemValue* val;
    val = new ItemValue[n];

    for (int i = 0; i < n; i++) {//introduc coordonatele in vectorul val
        in >> val[i].start;
        in >> val[i].end;
    }

    std::sort(val, val+n, compareFence);//sortez vectorul

    int i = 0;
    int j = 2;
    int count = 0;

    for (j = 1; j < n; j++) {
        if ((val[i].start <= val[j].start) && (val[i].end >= val[j].end)) {
            count++;
        } else {
            i = j;//doresc sa sar elementele care nu respecta conditia
        }
    }

    out << count << "\n";

    //inchid fisierele
    in.close();
    out.close();

    return 0;
}

