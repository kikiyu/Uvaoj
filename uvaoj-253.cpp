#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

/* Record the numbers in the clockwise direction. */
/* Record 7 rather than 4 numbers to avoid overflow */
const string sides[] = {"2453245", "1364136", "1562156", "1265126", "1463146", "2354235"};

bool matchCube(string cubea, string cubeb) {
    /*
     * Two faces can decide the representation of a cube.
     * 1. The face on the top, 6 cases.
     * 2. The face on the front, 4 cases. 
     * Hence, 24 cases in total.
     */
    for (int i = 0; i < 24; i++) {
        int top = i / 4;
        int rot = i % 4;

        string cur;
        cur += cubea[top];
        cur += cubea[sides[top][0+rot] - '0' - 1];
        cur += cubea[sides[top][3+rot] - '0' - 1];
        cur += cubea[sides[top][1+rot] - '0' - 1];
        cur += cubea[sides[top][2+rot] - '0' - 1];
        cur += cubea[5-top];

        //cout << "cur: " << cur << endl;
        if (cur == cubeb)
            return true;
    }
    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    string line;
    while (getline(cin, line)) {
        string cubea, cubeb;
    
        cubea = line.substr(0, 6);
        cubeb = line.substr(6, 6);

        if (matchCube(cubea, cubeb))
            cout << "TRUE\n";
        else
            cout << "FALSE\n";
    }

    return 0;
}