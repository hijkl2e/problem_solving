import java.math.BigInteger;
import java.util.Scanner;

public class boj3644 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger[] dp = new BigInteger[10001];
		dp[0] = dp[1] = BigInteger.ONE;
		for (int i = 2; i < dp.length; ++i) {
			dp[i] = dp[i - 1].add(dp[i - 2]);
		}
		while (sc.hasNextInt()) {
			int N = sc.nextInt();
			System.out.println(dp[N - 2].multiply(BigInteger.TWO).add(dp[N - 1]));
		}
		sc.close();
	}
}
