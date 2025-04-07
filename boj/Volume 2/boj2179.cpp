#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

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
	vector<si> B(N);
	for (int i = 0; i < N; ++i) {
		B[i] = {A[i], i};
	}
	sort(B.begin(), B.end());
	vector<int> C(N - 1);
	for (int i = 0; i < N - 1; ++i) {
		auto &s1 = B[i].first;
		auto &s2 = B[i + 1].first;
		while (C[i] < s1.size() && C[i] < s2.size() && s1[C[i]] == s2[C[i]]) {
			++C[i];
		}
	}
	int maxv = *max_element(C.begin(), C.end());
	int x{}, y{};
	x = y = N;
	for (int i = 0, j = 1; i < N - 1; i = j++) {
		if (C[i] < maxv) {
			continue;
		}
		int a = B[i].second, b = N;
		while (j < N && C[j - 1] == maxv) {
			b = min(b, B[j++].second);
			if (a > b) {
				swap(a, b);
			}
		}
		if (x > a) {
			x = a, y = b;
		}
	}
	cout << A[x] << "\n" << A[y] << "\n";
	return 0;
}
