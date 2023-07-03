#include <bits/stdc++.h>

using namespace std;

using si = pair<string, int>;

string convert(int x) {
	static vector<string> A{
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
	if (x < 10) {
		return A[x];
	} else {
		return A[x / 10] + " " + A[x % 10];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int M{}, N{};
	cin >> M >> N;
	vector<si> A;
	for (int i = M; i <= N; ++i) {
		A.push_back({convert(i), i});
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < A.size(); ++i) {
		cout << (i % 10 || i == 0 ? "" : "\n") << A[i].second << (i % 10 == 9 ? "" : " ");
	}
	cout << "\n";
	return 0;
}
