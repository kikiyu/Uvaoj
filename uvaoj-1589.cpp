#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 7;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

typedef struct info {
    char type;
    int row;
    int col;
    info(){};
    info(char t, int r, int c){ type = t; row = r; col = c;};
} info_t;

bool isValidG(int r, int c) {
    if (r < 1 || r > 3)
        return false;
    if (c < 4 || c > 6)
        return false;
    return true;
}

int getInter(int bgr, int bgc, const vector<info_t>& infos, unsigned int s) {
    int ret = 0;
    int rgr = infos[s].row;
    int rgc = infos[s].col;

    if (rgr == bgr) {
        int minc = min(bgc, rgc);
        int maxc = max(bgc, rgc);
        for (unsigned int i = 0; i < infos.size(); i++) {
            if (i == s)
                continue;
            if (infos[i].row == rgr && infos[i].col < maxc && infos[i].row > minc)
                ++ret;
        }
    }
    else if (rgc == bgc) {
        int minr = min(bgr, rgr);
        int maxr = max(bgr, rgr);
        for (unsigned int i = 0; i < infos.size(); i++) {
            if (i == s)
                continue;
            if (infos[i].col == rgc && infos[i].row < maxr && infos[i].row > minr)
                ++ret;
        }    
    }  
    
    return ret;
}

bool exist(const vector<info_t>& infos, int r, int c) {
    for (unsigned int i = 0; i < infos.size(); i++) {
        if (infos[i].row == r && infos[i].col == c)
            return true;
    }
    return false;
}

bool check(const int bgr, const int bgc, const vector<info_t>& infos) {
    //printf("check bgr %d bgc %d\n", bgr, bgc);
    for (unsigned int i = 0; i < infos.size(); i++) {
        /* the piece is captured by the general */
        if (infos[i].row == bgr && infos[i].col == bgc)
            continue;
        /* check whether the piece can capture the general */
        switch (infos[i].type) {
            case 'G':
                if (infos[i].col == bgc && getInter(bgr, bgc, infos, i) == 0)
                    return true;
                break;
            case 'R':
                if ((infos[i].col == bgc || infos[i].row == bgr) 
                    && (getInter(bgr, bgc, infos, i) == 0))
                    return true;
                break;
            case 'H':
            {
                int dr = bgr - infos[i].row;
                int dc = bgc - infos[i].col;
                if (abs(dr) == 2 && abs(dc) == 1) {
                    if (!exist(infos, infos[i].row + dr/2, infos[i].col))
                        return true;
                }
                if (abs(dr) == 1 && abs(dc) == 2) {
                    if (!exist(infos, infos[i].row, infos[i].col + dc/2))
                        return true;
                }
                break;
            }
            case 'C':
                if ((infos[i].col == bgc || infos[i].row == bgr) 
                    && getInter(bgr, bgc, infos, i) == 1)
                    return true;
                break;
            default:
                cout << "error type " << infos[i].type << endl;
                abort();
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    int bgr, bgc;

    while ((cin >> n >> bgr >> bgc) && (n != 0 || bgr != 0 || bgc != 0)) {
        vector<info_t> infos;
        for (int i = 0; i < n; i++) {
            char t;
            int r, c;
            cin >> t >> r >> c;
            infos.push_back(info(t, r, c));
        }

        bool checkMate = true;
        for (int i = 0; i < 4; i++) {
            int newr = bgr + dx[i];
            int newc = bgc + dy[i];
            if (isValidG(newr, newc) && !check(newr, newc, infos)) {
                checkMate = false;
                break;
            }
        }
        cout << (checkMate? "YES" : "NO") << endl;

    }

    return 0;
}