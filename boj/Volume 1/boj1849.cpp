#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ost = tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	ost tree;
	for (int i = 0; i < N; ++i) {
		tree.insert(i);
	}
	vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		auto it = tree.find_by_order(A[i]);
		B[*it] = i + 1;
		tree.erase(it);
	}
	for (int i = 0; i < N; ++i) {
		cout << B[i] << "\n";
	}
	return 0;
}
