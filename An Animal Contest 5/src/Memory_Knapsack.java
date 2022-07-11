import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.StringTokenizer;

public class Memory_Knapsack {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        int N = readInt(), W = readInt();
        int w [] = new int[N+1], v[] = new int[N+1];
        for (int i = 1; i <= N; i++) {
            w[i] =readInt(); v[i] = readInt();
        }
        long dp [][] = new long[2][W+1];
        int row = 0, preRow;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= W; j++) {
                row = i % 2;
                preRow = (i%2== 0? 1 : -1);
                dp[row][j] = dp[row+preRow][j];
                if (j >= w[i])dp[row][j] = Math.max(dp[row+preRow][j - w[i]] + v[i], dp[row][j]);
            }
        }
        System.out.println(dp[row][W]);

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