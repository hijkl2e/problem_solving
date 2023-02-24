import java.math.BigInteger;
import java.util.Scanner;

public class boj2407 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		BigInteger ans = BigInteger.ONE;
		for (int i = 0; i < M; ++i) {
			ans = ans.multiply(BigInteger.valueOf(N - i)).divide(BigInteger.valueOf(i + 1));
		}
		System.out.println(ans);
		sc.close();
	}
}
