#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N;
vector<int> A, B;

int solve1() {
	vector<int> C(100001);
	vector<int> D(100001);
	for (int i = 0; i < N; ++i) {
		++C[C.size() - A[i]];
		++D[B[i]];
	}
	partial_sum(C.begin(), C.end(), C.begin());
	partial_sum(D.begin(), D.end(), D.begin());
	int ret{};
	for (int i = 0; i < N; ++i) {
		ret = max(ret, N - C[C.size() - B[i]] - D[A[i]]);
	}
	return ret;
}

int solve2() {
	vector<ii> C(2 * N);
	for (int i = 0; i < N; ++i) {
		C[2 * i] = {A[i], 1};
		C[2 * i + 1] = {B[i], -1};
	}
	sort(C.begin(), C.end());
	int ret{}, cnt{};
	for (int i = 0; i < C.size(); ++i) {
		cnt += C[i].second;
		ret = max(ret, cnt);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	cout << solve1() << " " << solve2() << "\n";
	return 0;
}
