#include <bits/stdc++.h>

using namespace std;

using id = pair<int, double>;

const double EPS = 1e-9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double C{}, X{}, M{};
	cin >> C >> X >> M;
	C /= 2;
	vector<id> A(6);
	for (int i = 0; i < 6; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	int ans = -1;
	for (int i = 5; i >= 0; --i) {
		if (M / A[i].second + M / A[i].first * X < C + EPS) {
			ans = i;
			break;
		}
	}
	if (ans == -1) {
		cout << "NO\n";
	} else {
		cout << "YES " << A[ans].first << "\n";
	}
	return 0;
}
