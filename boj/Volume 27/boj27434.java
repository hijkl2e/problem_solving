import java.math.BigInteger;
import java.util.PriorityQueue;
import java.util.Scanner;

public class boj27434 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		PriorityQueue<BigInteger> pq = new PriorityQueue<>();
		for (int i = 0; i <= N; ++i) {
			pq.add(BigInteger.valueOf(Math.max(i, 1)));
		}
		while (pq.size() > 1) {
			BigInteger x = pq.poll();
			BigInteger y = pq.poll();
			pq.add(x.multiply(y));
		}
		System.out.println(pq.peek());
		sc.close();
	}
}
