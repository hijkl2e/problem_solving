#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int w{}, h{};
	cin >> w >> h;
	double ans = w + h - sqrt(w * w + h * h);
	cout << fixed << setprecision(10);
	cout << ans << "\n";
	return 0;
}
