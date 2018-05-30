#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cassert>
using namespace std;

char puzzle[5][5] = { 0, };
int i_blank = -1;
int j_blank = -1;

int check(int r, int c) {
	if (r < 0 || r >= 5)
		return false;
	if (c < 0 || c >= 5)
		return false;
	return true;
}

bool execute(char cmd) {
	int i_target = i_blank;
	int j_target = j_blank;

	switch (cmd) {
	case 'A':
		i_target -= 1;
		break;
	case 'B':
		i_target += 1;
		break;
	case 'L':
		j_target -= 1;
		break;
	case 'R':
		j_target += 1;
		break;
	default:
		return true;
	}
	if (!check(i_target, j_target))
		return false;

	swap(puzzle[i_blank][j_blank], puzzle[i_target][j_target]);
	i_blank = i_target;
	j_blank = j_target;
	return true;
}

void printPuzzle(int no, bool valid) {
	if (no != 1)
		cout << endl;

	printf("Puzzle #%d:\n", no);

	if (!valid) {
		printf("This puzzle has no final configuration.\n");
		return;
	}
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++)
			printf("%c ", puzzle[i][j]);
		printf("%c\n", puzzle[i][4]);
	}
}
int main() {
	string line;
	int no = 0;
	while (getline(cin, line) && line[0] != 'Z') {
		strcpy(puzzle[0], line.c_str());
		for (int i = 1; i < 5; i++) {
			getline(cin, line);
			strcpy(puzzle[i], line.c_str());
		}

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (puzzle[i][j] == ' ') {
						i_blank = i;
						j_blank = j;
						break;
					}
			}
		}

		char cmd;
		bool valid = true;
		while ((cin>> cmd) && (cmd != '0')) {
			if (isalpha(cmd) && valid)
				valid = execute(cmd);
		}
		getchar();

		printPuzzle(++no, valid);
	}

	//getchar(); getchar();

	return 0;
}
