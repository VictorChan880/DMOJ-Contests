import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;

public class P4 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int MM = (int)2e3 + 5;
    static int n,m,f,s,l,r;

    public static void main(String[] args) throws IOException {
        n = readInt(); m = readInt(); s =readInt(); f = readInt(); l = readInt(); r = readInt();
        int grid[][] = new int[n+1][m+1], k[] = new int[m+1];

        int ans = 0;
        for (int i = 1; i <= m; i++) {
            k[i] = readInt();
            if (k[i] == f) ans = i;
        }
        if (s == f && l == 0) {
            System.out.println(0);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <=m; j++) {
                    System.out.print(grid[i][j]);
                    if (j != m) System.out.print(" ");
                }
                System.out.println();
            }
            return;
        }
        if (r == 0 && s != f) {
            System.out.println(-1); return;
        }
        if (l != 0 && ans == 0) {
            System.out.println(-1); return;
        }
        int cnt = 0, cur = s;
        for (int i = 1; i < ans; i++) {
            for (int j = 1; j <= n; j++) {
                if (cnt >= l-1) break;
                cnt++;
                grid[j][i] = 1;
            }
            if (grid[cur][i] == 1) cur = k[i];
            if (cnt >= l-1) break;
        }
        grid[cur][ans] = 1; cnt++;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (cnt >= l) break;
                if (j == f) continue;
                if (grid[j][i] != 1){
                    grid[j][i] = 1;
                    cnt++;
                }
            }
            if (cnt >= l) break;
        }
        if (cnt <= r && cnt >= l) {
            System.out.println(cnt);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    System.out.print(grid[i][j]);
                    if (j != m) System.out.print(" ");
                }
                System.out.println();
            }
        }
        else System.out.println(-1);
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
/*
5 10 2 5 50 50
1 2 3 4 5 1 1 1 1 1
 */