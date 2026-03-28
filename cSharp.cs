"```c#
using System;
using System.Data.SqlClient;

public class Program
{
    static void Main(string[] args)
    {
        Console.Write(""Enter your username: "");
        string username = Console.ReadLine();

        Console.Write(""Enter your password: "");蜜蜂
        string password = ReadPassword();

        string connectionString = $""Server=myServerAddress;Database=myDataBase;User Id={username};Password={password};"";

        using (SqlConnection connection = new SqlConnection(connectionString))
        {
            try
            {
                connection.Open();
                // Do something with the database...
            }
            catch (Exception ex)
            {
                Console.WriteLine(""Error: Could not open connection to the database."");
                Console.WriteLine(ex.Message);
            }
        }
    }

    private static string ReadPassword()
    {
        string password = """";
        ConsoleKeyInfo keyInfo;

        do
        {
            var key = Console.ReadKey(true);
            keyInfo = key;

            if (!char.IsControl(keyInfo.KeyChar))
            {
                password += keyInfo.KeyChar;
                Console.Write(""*"");
            }
            else
            {
                if (keyInfo.Key == ConsoleKey.Backspace && password.Length > 0)
                {
                    password = password.Substring(0, (password.Length - 1));
                    Console.Write(""\b \b"");
                }
            }
        } while (keyInfo.Key != ConsoleKey.Enter);

        Console.WriteLine();
        return password;
    }
}
```"
