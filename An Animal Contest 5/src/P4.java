import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class P4 {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e5+5, mod = 998244353;

    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt();
        ArrayList<Integer> adj [] = new ArrayList[n+1];
        for (int i = 0; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int u = readInt(), v = readInt();
            adj[u].add(v); adj[v].add(u);
        }
        int ans = (int)1e9;
        for (int i = 1; i <= n; i++) {
            int dis[] = new int[n+1];
            boolean vis[] = new boolean[n+1];
            int par [] = new int[n+1];
            Queue<Integer> q = new LinkedList<>();
            q.add(i); vis[i] = true;
            while (!q.isEmpty()) {
                int u = q.poll();
                for (int v : adj[u]) {
                    if (!vis[v]) {
                        dis[v] = dis[u] + 1;
                        vis[v] = true;
                        par[v] = u;
                        q.add(v);
                    }
                    else if (par[u] !=  v) {
                        int length = dis[u] + dis[v] + 1;
                        ans = Math.min(ans,length);
                    }
                }
            }
        }
        System.out.println(ans == (int)1e9? -1 : ans);
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



