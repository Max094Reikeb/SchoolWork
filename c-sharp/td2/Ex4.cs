using System;

public static class Ex4
{
    public static void Run()
    {
        int[][] square = new int[][]
        {
            new[] { 4, 9, 2 },
            new[] { 3, 5, 7 },
            new[] { 8, 1, 6 }
        };

        int n = square.Length;

        Console.WriteLine($"sumTotal: {sumTotal(square, n)}");
        Console.WriteLine($"checkRow(i=1, x=15): {checkRow(square, n, 1, 15)}");
        Console.WriteLine($"checkColumn(j=2, x=15): {checkColumn(square, n, 2, 15)}");
        Console.WriteLine($"checkDiagonal(d=1, x=15): {checkDiagonal(square, n, 1, 15)}");
        Console.WriteLine($"checkDiagonal(d=2, x=15): {checkDiagonal(square, n, 2, 15)}");
        Console.WriteLine($"magic?: {magic(square)}");
    }

    public static int sumTotal(int[][] square, int n)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                s += square[i][j];
        return s;
    }

    public static bool checkRow(int[][] square, int n, int i, int x)
    {
        if (i < 1 || i > n) return false;
        int row = i - 1;
        int s = 0;
        for (int j = 0; j < n; j++) s += square[row][j];
        return s == x;
    }

    public static bool checkColumn(int[][] square, int n, int j, int x)
    {
        if (j < 1 || j > n) return false;
        int col = j - 1;
        int s = 0;
        for (int i = 0; i < n; i++) s += square[i][col];
        return s == x;
    }

    public static bool checkDiagonal(int[][] square, int n, int d, int x)
    {
        int s = 0;
        if (d == 1)
        {
            for (int i = 0; i < n; i++) s += square[i][i];
        }
        else if (d == 2)
        {
            for (int i = 0; i < n; i++) s += square[i][n - 1 - i];
        }
        else return false;

        return s == x;
    }

    public static bool magic(int[][] square)
    {
        int n = square.Length;
        if (n == 0) return false;

        int target = 0;
        for (int j = 0; j < n; j++) target += square[0][j];

        for (int i = 1; i <= n; i++)
            if (!checkRow(square, n, i, target)) return false;

        for (int j = 1; j <= n; j++)
            if (!checkColumn(square, n, j, target)) return false;

        return checkDiagonal(square, n, 1, target) && checkDiagonal(square, n, 2, target);
    }
}
