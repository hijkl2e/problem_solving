import java.math.BigInteger;
import java.util.Scanner;

public class boj8437 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		BigInteger N = sc.nextBigInteger();
		BigInteger M = sc.nextBigInteger();
		BigInteger x = N.subtract(M).divide(BigInteger.TWO);
		BigInteger y = x.add(M);
		System.out.println(y);
		System.out.println(x);
		sc.close();
	}
}
