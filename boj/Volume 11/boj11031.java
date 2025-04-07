import java.math.BigInteger;
import java.util.Scanner;

public class boj11031 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[][][] dp = new BigInteger[3003][2][3];
		for (int i = 0; i < 3003; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i][j][k] = BigInteger.ZERO;
				}
			}
		}
		dp[0][0][0] = BigInteger.ONE;
		for (int i = 0; i < 3002; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 3; ++k) {
					dp[i + 1][j][0] = dp[i + 1][j][0].add(dp[i][j][k]);
					if (j == 0) {
						dp[i + 1][1][0] = dp[i + 1][1][0].add(dp[i][j][k]);
					}
					if (k < 2) {
						dp[i + 1][j][k + 1] = dp[i + 1][j][k + 1].add(dp[i][j][k]);
					}
				}
			}
		}
		while (sc.hasNextInt()) {
			int N = sc.nextInt();
			BigInteger ans = BigInteger.ZERO;
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					ans = ans.add(dp[N][i][j]);
				}
			}
			System.out.println(ans);
		}
		sc.close();
	}
}
