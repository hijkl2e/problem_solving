#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int S = 1, E = 1;
	for (int i = 1; i < N; ++i) {
		if (A[i] > A[i + 1]) {
			S = i;
			E = i + 1;
			break;
		}
	}
	while (S > 1 && A[S - 1] >= A[S]) {
		--S;
	}
	while (E < N && A[E] >= A[E + 1]) {
		++E;
	}
	reverse(A.begin() + S, A.begin() + E + 1);
	bool yes = true;
	for (int i = 1; i < N; ++i) {
		if (A[i] > A[i + 1]) {
			yes = false;
			break;
		}
	}
	if (yes) {
		cout << S << " " << E << "\n";
	} else {
		cout << "impossible\n";
	}
	return 0;
}
