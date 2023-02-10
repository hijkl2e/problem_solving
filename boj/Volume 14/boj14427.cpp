#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	multiset<ii> S;
	for (int i = 1; i <= N; ++i) {
		S.insert({A[i], i});
	}
	int M{};
	cin >> M;
	while (M--) {
		int q{}, a{}, b{};
		cin >> q;
		if (q == 1) {
			cin >> a >> b;
			S.erase(S.find({A[a], a}));
			S.insert({A[a] = b, a});
		} else {
			cout << S.begin()->second << "\n";
		}
	}
	return 0;
}
