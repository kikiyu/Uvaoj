#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

void fileIO() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

double maxA[12][32];
int maxB[12][32];
	
void preWork() {
	for (int m = 0; m <= 9; m++) {
		for (int e = 1; e <= 30; e++) {
			double mant = 1 - pow(2, -(m + 1));
			long long exp = pow(2, e) - 1;
			double lgC = log10(mant) + exp * log10(2);
			int B = floor(lgC);
			double A = pow(10, lgC - B);
			maxA[m][e] = A;
			maxB[m][e] = B;
			//printf("kiki m %d e %d A %.15lf B %d\n", m, e, A, B);
			//printf("%.15lfe%d\n", A, B);
		}
	}
}
int main() {
	//fileIO();
	preWork();

	string line;
	while (getline(cin, line) && line != "0e0") {
		size_t pos = line.find('e');
		double a = stod(line.substr(0, pos));
		int b = stoi(line.substr(pos + 1));
		//cout << a << " " << b << endl;

		for (int m = 0; m <= 9; m++) {
			for (int e = 1; e <= 30; e++) {
				if (maxB[m][e] == b && (fabs(maxA[m][e] - a) < 1e-4)) 
					cout << m << " " << e << endl;
			}
		}

	}
	return 0;
}