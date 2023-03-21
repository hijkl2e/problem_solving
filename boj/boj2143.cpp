#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> solve(vector<int> &A) {
	vector<int> ret;
	for (int i = 0; i < A.size(); ++i) {
		int sum{};
		for (int j = i; j < A.size(); ++j) {
			sum += A[j];
			ret.push_back(sum);
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T{};
	cin >> T;
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int M{};
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	vector<int> C = solve(A);
	vector<int> D = solve(B);
	sort(D.begin(), D.end());
	ll ans{};
	for (int x : C) {
		auto [it1, it2] = equal_range(D.begin(), D.end(), T - x);
		ans += it2 - it1;
	}
	cout << ans << "\n";
	return 0;
}
