import java.math.BigInteger;
import java.util.Scanner;

public class boj22193 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		BigInteger x = sc.nextBigInteger();
		BigInteger y = sc.nextBigInteger();
		System.out.println(x.multiply(y));
		sc.close();
	}
}
