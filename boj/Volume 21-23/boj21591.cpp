#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int wc{}, hc{}, ws{}, hs{};
	cin >> wc >> hc >> ws >> hs;
	ws += 2;
	hs += 2;
	cout << (wc >= ws && hc >= hs) << "\n";
	return 0;
}
