#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s{}, k{}, h{};
	cin >> s >> k >> h;
	int minv = min({s, k, h});
	string ans = s + k + h >= 100 ? "OK" : s == minv ? "Soongsil" : k == minv ? "Korea" : "Hanyang";
	cout << ans << "\n";
	return 0;
}
