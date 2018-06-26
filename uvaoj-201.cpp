#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int n;
bool hedges[10][10], vedges[10][10];
        
int findSquare(int s) {
    int ret = 0;
    for (int si = 1; si + s <= n; si++) {
        for (int sj = 1; sj + s <= n; sj++) {
            bool check = true;
            for (int d = 0; d < s; d++) {
                /* check horizontal lines */
                if (!hedges[si][sj+d] || !hedges[si+s][sj+d]) {
                    //printf("hfalse si %d sj %d d %d\n", si, sj, d);
                    check = false;
                    break;
                }
                /* check vertical lines */
                if (!vedges[si+d][sj] || !vedges[si+d][sj+s]) {
                    //printf("vfalse si %d sj %d d %d\n", si, sj, d);
                    //printf("vedges[si+d][sj] %d vedges[si+d][sj+s] %d\n", vedges[si+d][sj], vedges[si+d][sj+s]);
                    check = false;
                    break;
                }
            }
            if (check) {
                //printf("si %d sj %d s %d\n", si, sj, s);
                ++ret;
            }
        }
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int kase = 1;
    while (cin >> n) {
        memset(hedges, 0, sizeof(hedges));
        memset(vedges, 0, sizeof(vedges));

        int m;
        cin >> m;
        for (int k = 0; k < m; k++) {
            char type;
            int i, j;
            cin >> type >> i >> j;
            if (type == 'H')
                hedges[i][j] = true;
            else
                vedges[j][i] = true;
        }
       
        if (kase != 1)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", kase++);

        bool found = false;
        for (int i = 1; i < n; i++) {
            int ret = findSquare(i);
            if (ret) {
                found = true;
                printf("%d square (s) of size %d\n", ret, i);
            }
        }
        if (!found)
            printf("No completed squares can be found.\n");
    }
    
    
}