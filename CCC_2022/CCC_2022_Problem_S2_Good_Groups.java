import java.util.*;
public class CCC_2022_Problem_J4_Good_Groups {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] group = new int[5000005];
		int x = sc.nextInt(), cnt = 0;
		List<pair> same = new ArrayList<>();
		HashMap<String, Integer> name = new HashMap<String, Integer>();
		for(int i=0; i<x; i++){
	        String a = sc.next(), b = sc.next();
	        if(!name.containsKey(a)){
	            name.put(a, cnt); cnt++;
	        }
	        if(!name.containsKey(b)){
	            name.put(b, cnt); cnt++;
	        }
	        same.add(new pair(name.get(a), name.get(b)));
	    }
		int y = sc.nextInt();
		List<pair> dif = new ArrayList<>();
		for(int i=0; i<y; i++){
	        String a = sc.next(), b = sc.next();
	        if(!name.containsKey(a)){
	            name.put(a, cnt); cnt++;
	        }
	        if(!name.containsKey(b)){
	            name.put(b, cnt); cnt++;
	        }
	        dif.add(new pair(name.get(a), name.get(b)));
	    }
		int n = sc.nextInt(), ans = 0;
		for(int i=0; i<n; i++){
	        String a = sc.next(), b = sc.next(), c = sc.next();
	        if(!name.containsKey(a)){
	            name.put(a, cnt); cnt++;
	        }
	        if(!name.containsKey(b)){
	            name.put(b, cnt); cnt++;
	        }
	        if(!name.containsKey(c)){
	            name.put(c, cnt); cnt++;
	        }
	        group[name.get(a)] = group[name.get(b)] = group[name.get(c)] = i;
	    }
		for(pair pi: same){
	        if(group[pi.f] != group[pi.s]) ans++;
	    }
	    for(pair pi: dif){
	        if(group[pi.f] == group[pi.s]) ans++;
	    }
	    System.out.println(ans);
		sc.close();
	}
	static class pair {
        public int f, s;
        public pair(int f, int s) {this.f = f; this.s = s;}
    }
}