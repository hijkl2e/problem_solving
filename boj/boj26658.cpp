#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

struct event {
	int x{}, l{}, y{}, t{}, z{};
	bool operator<(event &e) {
		return x < e.x || (x == e.x && z < e.z);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<event> A(2 * N);
	for (int i = 0; i < 2 * N; i += 2) {
		int xl{}, xr{}, y{};
		char c{};
		cin >> xl >> xr >> y >> c;
		A[i] = {xl, xr - xl + 1, y, c == 'S' ? 1 : -1, 1};
		A[i + 1] = {xr + 1, xr - xl + 1, y, c == 'S' ? 1 : -1, -1};
	}
	sort(A.begin(), A.end());
	set<ii> S;
	S.insert({0, 0});
	S.insert({2e9, 0});
	ll ans{}, sum{}, cnt{};
	for (int i = 0; i < 2 * N;) {
		int X = A[i].x;
		while (i < 2 * N && A[i].x == X) {
			auto it = S.insert({A[i].y, A[i].t}).first;
			sum += 1LL * A[i].z * A[i].l;
			int t1 = next(it)->second;
			int t2 = prev(it)->second;
			if (t1 && t2) {
				cnt += (A[i].t == t1 || A[i].t == t2 ? 1 : -1) * A[i].z;
			} else {
				cnt += ((t1 + t2) == A[i].t) * A[i].z;
			}
			if (A[i++].z == -1) {
				S.erase(it);
			}
		}
		if (cnt == 0) {
			ans = max(ans, sum);
		}
	}
	cout << ans << "\n";
	return 0;
}
