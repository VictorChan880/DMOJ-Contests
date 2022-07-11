
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e3+5, mod = 998244353;

    public static void main(String[] args) throws IOException {
        int n = readInt(), m = readInt();
        ArrayList<Integer> adj [] = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = readInt(), v = readInt();
            adj[u].add(v); adj[v].add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        boolean vis [] = new boolean[n+1];
        int dis [] = new int[n+1];
        int pre [] = new int[n+1];
        q.add(1); vis[1] = true; dis[1] = 1;
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int v : adj[cur]) {
                if (!vis[v]) {
                    q.add(v);
                    dis[v] = dis[cur] + 1;
                    pre[v] = cur;
                    vis[v] = true;
                }
            }
        }
        int cur = n;
        if(!vis[n]) {
            System.out.println("IMPOSSIBLE"); return;
        }
        ArrayList<Integer> path = new ArrayList<>();
        while (cur != 0 ) {
            path.add(cur);
            cur = pre[cur];
        }
        System.out.println(dis[n]);
        for (int i = path.size()-1; i>= 0; i--) {
            System.out.print(path.get(i) + " ");
        }
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