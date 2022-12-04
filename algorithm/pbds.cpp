#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ost = tree<int, null_type, less<int>, rb_tree_tag,
			tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> A{2, 4, 7, 10, 15, 23, 50, 65, 71};
	ost tree;
	for (int x : A) {
		tree.insert(x);
	}
	cout << *tree.find_by_order(0) << "\n";
	cout << *tree.find_by_order(tree.size() - 1) << "\n";
	cout << *tree.find_by_order(4) << "\n";
	cout << tree.order_of_key(2) << "\n";
	cout << tree.order_of_key(71) << "\n";
	cout << tree.order_of_key(15) << "\n";
	return 0;
}
