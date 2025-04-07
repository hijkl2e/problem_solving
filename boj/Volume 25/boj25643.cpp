#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	bool yes = true;
	for (int i = 1; i < N; ++i) {
		yes = false;
		for (int j = 1; j <= M; ++j) {
			if (A[i - 1].substr(0, j) == A[i].substr(M - j)
					|| A[i].substr(0, j) == A[i - 1].substr(M - j)) {
				yes = true;
				break;
			}
		}
		if (!yes) {
			break;
		}
	}
	cout << yes << "\n";
	return 0;
}
