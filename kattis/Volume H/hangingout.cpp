#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int L{}, N{};
	cin >> L >> N;
	int now{}, ans{};
	while (N--) {
		string E;
		int x{};
		cin >> E >> x;
		if (E == "enter") {
			if (now + x <= L) {
				now += x;
			} else {
				++ans;
			}
		} else {
			now -= x;
		}
	}
	cout << ans << "\n";
	return 0;
}
