#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, K{}, S{};
	cin >> L >> K >> S;
	map<int, ii> A;
	while (L--) {
		int x{}, m{}, s{};
		char c{};
		cin >> x >> m >> c >> s;
		++A[x].first;
		A[x].second += 60 * m + s;
	}
	vector<ii> B;
	for (auto &p : A) {
		if (p.second.first == K) {
			B.push_back({p.second.second, p.first});
		}
	}
	sort(B.begin(), B.end());
	for (auto &p : B) {
		cout << p.second << "\n";
	}
	return 0;
}
