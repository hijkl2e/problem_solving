#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

vector<int> A, B;

bool solve(int x) {
	return A[x] == B[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	vector<ii> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = {A[i], i};
	}
	sort(C.begin(), C.end());
	int cnt{};
	for (int i = 0; i < N; ++i) {
		if (A[i] != B[i]) {
			++cnt;
		}
	}
	bool yes = cnt == 0;
	for (int i = N - 1; i > 0; --i) {
		int j = C[i].second;
		if (i == j) {
			continue;
		}
		auto it = lower_bound(C.begin(), C.end(), make_pair(A[i], -1));
		it->second = j;
		cnt += solve(i) + solve(j);
		swap(A[i], A[j]);
		cnt -= solve(i) + solve(j);
		if (cnt == 0) {
			yes = true;
			break;
		}
	}
	cout << yes << "\n";
	return 0;
}
