#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int X{}, Y{};
	cin >> X >> Y;
	vector<int> dx{X, Y, Y, X, -X, -Y, -Y, -X};
	vector<int> dy{Y, X, -X, -Y, -Y, -X, X, Y};
	if (X > Y) {
		swap(X, Y);
	}
	vector<int> A;
	if (X == Y || X == 0) {
		A = {0, 2, 2, 4, 4, 6, 0};
	} else {
		A = {0, 3, 1, 4, 2, 5, 3, 6, 4, 7, 5, 0, 6, 1, 2};
	}
	cout << A.size() << "\n";
	int x{}, y{};
	for (int i = 0; i < A.size(); ++i) {
		x += dx[A[i]];
		y += dy[A[i]];
		cout << x << " " << y << "\n";
	}
	return 0;
}
