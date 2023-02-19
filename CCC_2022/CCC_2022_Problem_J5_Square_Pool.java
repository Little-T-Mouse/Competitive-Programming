import java.util.*;
public class CCC_2022_Problem_J5_Square_Pool {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt(), t = sc.nextInt(), ans = 0;
		if(t == 0) {
			System.out.println(n);
			sc.close();
			return;
		}
		List<pair> tree = new ArrayList<>();
		tree.add(new pair(0, 0));
		for(int i=0; i<t; i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			tree.add(new pair(a, b));
		}
		for(pair pi: tree){
	        int top = pi.first;
	        for(pair pj: tree){
	            int left = pj.second;
	            int sz = Math.min(n-top, n-left);
	            for(pair pk: tree){
	                if(pk.first > top && pk.second > left){
	                    sz = Math.min(sz, Math.max(pk.first-top-1, pk.second-left-1));
	                }
	            }
	            ans = Math.max(ans, sz);
	        }
	    }
		System.out.println(ans);
		sc.close();
	}
	static class pair {
        public int first, second;
        public pair(int first, int second) {this.first = first; this.second = second;}
    }
}