#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	string M, T;
	cin >> N >> M >> T;
	vector<int> B(2 * N);
	for (int i = 1; i < 2 * N; ++i) {
		B[i] = B[i - 1] ^ (T[i % N] == 'B');
	}
	if (B[N]) {
		cout << "here" << endl;
		set<int> S;
		for (int i = 0; i < N; ++i) {
			S.insert(i);
		}
		for (int i = 0; i < N; ++i) {
			if (i % 2 == (M == "here")) {
				int c{}, k{};
				cin >> c >> k;
				S.erase(S.find(k));
			} else {
				cout << "1 " << *S.begin() << endl;
				S.erase(S.begin());
			}
		}
	} else {
		cout << (M == "here" ? "everyone" : "here") << endl;
		for (int i = 0; i < N / 2; ++i) {
			int c{}, k{};
			cin >> c >> k;
			c ^= ((M == "here" ? k : (N / 4 + 1)) % 2) ^ B[k + N / 2] ^ B[k];
			k = (k + N / 2) % N;
			cout << c << " " << k << endl;
		}
	}
	return 0;
}
