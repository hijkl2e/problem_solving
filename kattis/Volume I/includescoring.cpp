#include <bits/stdc++.h>

using namespace std;

using rec = tuple<int, int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A{
		100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16,
		15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
	};
	A.resize(N);
	vector<rec> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		auto &[s, p, f, idx] = B[i];
		cin >> s >> p >> f >> C[i];
		s = -s;
		idx = i;
	}
	sort(B.begin(), B.end());
	for (int i = 0; i < N;) {
		auto &[s, p, f, idx] = B[i];
		int j = upper_bound(B.begin(), B.end(), make_tuple(s, p, f, N)) - B.begin();
		int sum = accumulate(A.begin() + i, A.begin() + j, 0);
		int point = sum ? (sum - 1) / (j - i) + 1 : 0;
		while (i < j) {
			C[get<3>(B[i++])] += point;
		}
	}
	for (int x : C) {
		cout << x << "\n";
	}
	return 0;
}
