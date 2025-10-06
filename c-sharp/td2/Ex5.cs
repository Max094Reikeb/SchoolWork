using System;

public static class Ex5
{
    public static void Run()
    {
        Console.Write("Taille du plateau: ");
        if (!int.TryParse(Console.ReadLine(), out int n) || n <= 0)
        {
            Console.WriteLine("Taille invalide.");
            return;
        }
        Dawson(n);
    }

    public static int[] newBoard(int n)
    {
        return new int[n];
    }

    public static void display(int[] board, int n)
    {
        for (int i = 0; i < n; i++)
        {
            char c = board[i] switch
            {
                0 => '.',
                1 => 'x',
                -1 => 'o',
                _ => '?'
            };
            Console.Write(c);
        }
        Console.WriteLine();
        for (int i = 0; i < n; i++)
            Console.Write(i % 10);
        Console.WriteLine();
    }

    public static bool possible(int[] board, int n, int i)
    {
        if (i < 0 || i >= n) return false;
        return board[i] == 0;
    }

    public static int select(int[] board, int n)
    {
        while (true)
        {
            Console.Write("Sélectionnez une position i (0..n-1) pour placer un pion: ");
            if (int.TryParse(Console.ReadLine(), out int i) && possible(board, n, i))
                return i;

            Console.WriteLine("Coup invalide. Case non vide ou hors de portée.");
        }
    }

    public static void put(int[] board, int n, int i)
    {
        board[i] = 1;
        if (i - 1 >= 0 && board[i - 1] == 0) board[i - 1] = -1;
        if (i + 1 < n && board[i + 1] == 0) board[i + 1] = -1;
    }

    public static bool again(int[] board, int n)
    {
        for (int i = 0; i < n; i++)
            if (possible(board, n, i))
                return true;
        return false;
    }

    public static void Dawson(int n)
    {
        var board = newBoard(n);
        int current = 1;

        Console.WriteLine("Start !");
        display(board, n);

        while (true)
        {
            Console.WriteLine($"C'est le tour du Joueur {current}:");
            if (!again(board, n))
            {
                Console.WriteLine($"Aucun coup possible. Le Joueur {current} perds. Le Joueur {(current == 1 ? 2 : 1)} gagne !");
                break;
            }

            int i = select(board, n);
            put(board, n, i);
            display(board, n);

            current = (current == 1) ? 2 : 1;
        }
    }
}
