#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<iii> A(2 * N);
	for (int i = 0; i < N; ++i) {
		int l{}, h{}, r{};
		cin >> l >> h >> r;
		A[2 * i] = {l, 1, h};
		A[2 * i + 1] = {r, -1, h};
	}
	sort(A.begin(), A.end());
	int p{};
	multiset<int> S{0};
	vector<int> B;
	for (int i = 0, j = 1; i < A.size(); i = j++) {
		auto &[a, b, c] = A[i];
		while (j < A.size()) {
			auto &[d, e, f] = A[j];
			if (a == d) {
				++j;
			} else {
				break;
			}
		}
		for (int k = i; k < j; ++k) {
			auto &[d, e, f] = A[k];
			if (e == 1) {
				S.insert(f);
			} else {
				S.erase(S.find(f));
			}
		}
		if (p != *--S.end()) {
			p = *--S.end();
			B.push_back(a);
			B.push_back(p);
		}
	}
	for (int i = 0; i < B.size(); ++i) {
		cout << B[i] << (i == B.size() - 1 ? "\n" : " ");
	}
	return 0;
}
