import java.util.*;
public class CCC_2022_Problem_S3_Good_Sample {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong(), M = sc.nextLong(), cur = 1, K = sc.nextLong();
		sc.close();
		if(K<N || K>(N-M)*M+(1+M)*M/2) {
			System.out.println(-1);
			return;
		}
		long[] a = new long[(int) N]; a[0] = 1; K--;
		for(int i=1; i<N; i++) {
			if(K-cur>N-i-1 && a[i-1]+1<=M){
	            a[i] = a[i-1]+1;
	            if(cur<M) cur++;
	            K -= cur;
	        }
	        else{
	            while(K-cur<N-i-1) cur--;
	            a[i] = a[(int) (i-cur)];
	            K -= cur;
	        }
		}
		for(int i=0; i<N; i++){
	        System.out.print(a[i]+((long) i==N?"\n":" "));
	    }
	}
}