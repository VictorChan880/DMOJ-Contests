import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = readInt(), W = readInt();
        int w [] = new int[N+1], v[] = new int[N+1];
        for (int i = 1; i <= N; i++) {
            w[i] =readInt(); v[i] = readInt();
        }
        long dp [] [] = new long[N+1][W+1];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                dp[i][j] = dp[i-1][j];
                if (w[i] <= j) {
                    dp[i][j] = Math.max(dp[i-1][j-w[i]] + v[i], dp[i][j]);
                }
            }
        }
        System.out.println(dp[N][W]);

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