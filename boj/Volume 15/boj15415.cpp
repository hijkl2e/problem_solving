#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int W{}, N{};
	cin >> W >> N;
	int sum{};
	while (N--) {
		int w{}, l{};
		cin >> w >> l;
		sum += w * l;
	}
	int L = sum / W;
	cout << L << "\n";
	return 0;
}
