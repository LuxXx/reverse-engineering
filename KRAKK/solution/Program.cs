using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;

namespace KRAKK
{
    class Program
    {
        private static string Hash(string input)
        {
            using (SHA1Managed managed = new SHA1Managed())
            {
                byte[] buffer1 = managed.ComputeHash(Encoding.UTF8.GetBytes(input));
                StringBuilder builder = new StringBuilder(buffer1.Length * 2);
                foreach (byte num2 in buffer1)
                {
                    builder.Append(num2.ToString("X2"));
                }
                return builder.ToString();
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine(Hash("LuxXx"));
            Console.ReadKey();
        }
    }
}
