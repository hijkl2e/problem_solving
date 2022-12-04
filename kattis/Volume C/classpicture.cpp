#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	while (cin >> N) {
		vector<string> A(N);
		for (int i = 0; i < N; ++i) {
			cin >> A[i];
		}
		sort(A.begin(), A.end());
		map<string, int> n2i;
		for (int i = 0; i < N; ++i) {
			n2i.insert({A[i], i});
		}
		vector<deque<bool>> B(N, deque<bool>(N));
		int M{};
		cin >> M;
		while (M--) {
			string s1, s2;
			cin >> s1 >> s2;
			int x = n2i[s1];
			int y = n2i[s2];
			B[x][y] = B[y][x] = true;
		}
		vector<int> C(N);
		for (int i = 0; i < N; ++i) {
			C[i] = i;
		}
		bool yes{};
		do {
			if (C.front() > C.back()) {
				continue;
			}
			bool flag = true;
			for (int i = 1; i < N; ++i) {
				if (B[C[i - 1]][C[i]]) {
					flag = false;
					sort(C.rbegin(), C.rend() - i - 1);
					break;
				}
			}
			if (flag) {
				yes = true;
				break;
			}
		} while (next_permutation(C.begin(), C.end()));
		if (yes) {
			for (int i = 0; i < N; ++i) {
				cout << A[C[i]] << (i == N - 1 ? "\n" : " ");
			}
		} else {
			cout << "You all need therapy.\n";
		}
	}
	return 0;
}
