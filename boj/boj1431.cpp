#include <bits/stdc++.h>

using namespace std;

using iis = tuple<int, int, string>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cin.ignore();
	vector<string> A(N);
	for (int i = 0; i < N; ++i) {
		getline(cin, A[i]);
	}
	vector<iis> B(N);
	for (int i = 0; i < N; ++i) {
		int cnt{};
		for (char c : A[i]) {
			if (isdigit(c)) {
				cnt += c - '0';
			}
		}
		B[i] = {A[i].size(), cnt, A[i]};
	}
	sort(B.begin(), B.end());
	for (auto &[a, b, s] : B) {
		cout << s << "\n";
	}
	return 0;
}
