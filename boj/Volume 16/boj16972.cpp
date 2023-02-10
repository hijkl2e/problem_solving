#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> X, Y;
	for (int i = 0; i < 31; ++i) {
		for (int j = i % 2; j < 53; j += 2) {
			X.push_back(542 * i - 8130);
			Y.push_back(313 * j - 8138);
		}
	}
	X[813] = 8140;
	Y[813] = 3148;
	for (int i = 0; i < 814; ++i) {
		cout << X[i] << " " << Y[i] << "\n";
	}
	return 0;
}
