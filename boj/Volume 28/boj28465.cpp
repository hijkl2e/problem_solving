#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a{}, b{}, x{}, y{};
	cin >> a >> b >> x >> y;
	if (a < b) {
		swap(a, b);
		swap(x, y);
	}
	vector<int> fibo(45);
	fibo[1] = fibo[2] = 1;
	for (int i = 3; i < fibo.size(); ++i) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int n = find(fibo.begin(), fibo.end(), a) - fibo.begin() - 1;
	int ans = 1;
	while (n > 1) {
		if (x >= fibo[n + 1] - fibo[n - 1]) {
			x -= fibo[n + 1] - fibo[n - 1];
		} else if (x >= fibo[n - 1]) {
			ans = n;
			break;
		}
		swap(x, y);
		--n;
	}
	cout << ans << "\n";
	return 0;
}
