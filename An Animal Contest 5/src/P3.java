import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class P3 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e5+5, mod = 998244353;
    static int l [] = new int[MM], r[] = new int[MM], s[] = new int[MM];
    static ArrayList<pair> adj [] = new ArrayList[MM];

    static class pair implements Comparable<pair>{
        int v, w;
        pair (int a, int b) {
            v = a; w = b;
        }

        @Override
        public int compareTo(pair o) {
            return Integer.compare(w,o.w);
        }
    }
    static void dfs (int u) {
        int lft = l[u], rit = r[u];
        if (adj[u].size() == 0) return;
        for (int i = 0; i < adj[u].size()-1; i++) {
            int v = adj[u].get(i).v;
            if (lft > rit) break;
            int mid = (adj[u].get(i).w + adj[u].get(i+1).w)/2;
            int pt = Arrays.binarySearch(s,lft,rit+1,mid);
            if (pt < 0 ) pt = -pt - 1;

            l[v] = lft; r[v] = pt;
            lft = pt+1;
            dfs(v);
        }
        if (lft > rit) return;
        int v = adj[u].get(adj[u].size()-1).v;
        l[v] = lft; r[v] = rit;
        dfs(v);
    }
    public static void main(String[] args) throws IOException {
        int n = readInt(), k = readInt();
        for (int i = 0; i <= n ; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n-1; i++) {
            int u = readInt(), v = readInt(), w = readInt();
            adj[u].add(new pair(v,w));
        }
        for (int i = 0; i < k; i++) {
            s[i] = readInt();
        }
        Arrays.fill(l,-1);
        Arrays.sort(s,0,k);
        for (int i = 1; i <= n; i++) Collections.sort(adj[i]);
        l[1] = 0; r[1] = k-1; dfs(1);
        for (int i = 1; i <= n; i++) {
            System.out.print((l[i] == -1 ? 0 : r[i] - l[i] + 1));
            if (i != n) System.out.print(" ");
        }
        System.out.println();
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}