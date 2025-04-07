#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{
		0x7b6f, 0x1249, 0x73e7, 0x73cf, 0x5bc9,
		0x79cf, 0x79ef, 0x7249, 0x7bef, 0x7bcf
	};
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> B(5);
	for (int i = 0; i < 5; ++i) {
		getline(cin, B[i]);
	}
	vector<vector<int>> C(N);
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 10; ++j) {
			bool yes = true;
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (B[k][4 * i + l] == '#' && ((A[j] >> (14 - 3 * k - l)) & 1) == 0) {
						yes = false;
					}
				}
			}
			if (yes) {
				C[i].push_back(j);
			}
		}
		cnt *= C[i].size();
	}
	if (cnt == 0) {
		cout << "-1\n";
		return 0;
	}
	ll sum{};
	for (int i = N - 1, k = 1; i >= 0; --i, k *= 10) {
		sum += cnt / C[i].size() * k * accumulate(C[i].begin(), C[i].end(), 0);
	}
	double ans = sum * 1.0 / cnt;
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
