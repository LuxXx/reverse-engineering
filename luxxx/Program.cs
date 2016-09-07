using System;
using System.Text;
using System.Security.Cryptography;

namespace BruteforceAndKeygenMe
{
    class Program
    {
        static string acceptingHash = "7450746596";

        static void Main(string[] args)
        {
            Console.WriteLine("KeyGen by LuxXx - https://github.com/LuxXx/reverse-engineering");
            Console.Write("Enter username: ");
            string name = Console.ReadLine();
            Console.Write("Enter serial key: ");
            string key = Console.ReadLine();

            if (isKeyValid(name,key))
            {
                Console.WriteLine("Done, write a keygen!");
            } else
            {
                Console.WriteLine("Try harder!");
            }
            Console.ReadKey();
        }


        // hex string to long
        private static long hStrToLong(string hexString)
        {
            try
            {
                return long.Parse(hexString, System.Globalization.NumberStyles.HexNumber);
            }
            catch (Exception e)
            {
                Console.WriteLine("no hex string as input");
                return 0;
            }
        }

        private static bool isKeyValid(string name, string key)
        {
            long someValue = hStrToLong(key) - hStrToLong(hash(name));
            return hash(someValue.ToString()).Equals(acceptingHash);
        }

        // this is a simple hash function
        // I already saw that it may collide but that should not be a problem
        static string hash(string s)
        {
            byte[] sArr = Encoding.UTF8.GetBytes(s);
            SHA256Managed sm = new SHA256Managed();
            byte[] hArray = sm.ComputeHash(sArr);

            StringBuilder sb = new StringBuilder();

            sb.Append(hArray[28]);
            sb.Append((13 * hArray[3]).ToString("X"));
            sb.Append((7 * hArray[0xC]).ToString("X"));
            sb.Append((0x0D * hArray[0xE]).ToString("X"));
            return sb.ToString();
        }
    }
}
