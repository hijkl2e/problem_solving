#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;

vector<ii> A(3);
vector<ii> B;

void solve(int x, int y) {
	A[x].first -= A[y].first;
	B.push_back({A[x].second, A[y].second});
	A[y].first *= 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 3; ++i) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}
	while (A[0].first) {
		ll q = A[1].first / A[0].first;
		if (A[1].first % A[0].first <= A[0].first / 2) {
			while (q) {
				solve(2 - q % 2, 0);
				q /= 2;
			}
		} else {
			++q;
			while (q > 1) {
				solve(2 - q % 2, 0);
				q /= 2;
			}
			solve(0, 1);
		}
		sort(A.begin(), A.end());
	}
	cout << B.size() << "\n";
	for (auto &p : B) {
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}
