#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{9, 4, 4, 4, 7};
	string S;
	while (getline(cin, S), S != "-") {
		vector<int> B(5);
		vector<char> C(5);
		double total_cal{}, fat_cal{};
		do {
			double cal_sum{};
			int pct_sum{};
			istringstream iss(S);
			for (int i = 0; i < 5; ++i) {
				iss >> B[i] >> C[i];
				if (C[i] == 'g') {
					B[i] *= A[i];
				}
				if (C[i] == '%') {
					pct_sum += B[i];
				} else {
					cal_sum += B[i];
				}
			}
			cal_sum = cal_sum * 100 / (100 - pct_sum);
			total_cal += cal_sum;
			if (C[0] == '%') {
				fat_cal += cal_sum * B[0] / 100;
			} else {
				fat_cal += B[0];
			}
		} while (getline(cin, S), S != "-");
		int ans = lround(fat_cal / total_cal * 100);
		cout << ans << "%\n";
	}
	return 0;
}
