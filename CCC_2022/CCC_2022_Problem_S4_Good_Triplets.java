import java.util.*;
public class CCC_2022_Problem_S4_Good_Triplets {
	static int MN = (int) 1e6+6;
	static long N, C;
	static int[] freq = new int [MN];
	static int[] psa = new int[2*MN];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextLong(); C = sc.nextLong();
		long ans = NC3(N);
		for(int i=0, x; i<N; i++) {
	        x = sc.nextInt(); freq[x]++;
	    }
		sc.close();
		for(int i=1; i<=2*C; i++){
	        psa[i] = psa[i-1] + freq[(int) ((i-1)%C)];
	    }
		if(C%2==0){
	        for(int i=0; i<C/2; i++){
	            ans += NC3(freq[i]+freq[(int) (i+C/2)])-NC3(freq[i])-NC3(freq[(int) (i+C/2)]);
	        }
	    }
		for(int i=1; i<=C; i++) {
	        ans -= NC3(psa[(int) (i+C/2)]-psa[i-1])-NC3(psa[(int) (i+C/2)]-psa[i]);
	    }
		System.out.println(ans);
	}
	static long NC3(long x) {return x*(x-1)*(x-2)/6;}
}