using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Globalization;
using System.Security.Cryptography;

// @author LuxXx
// https://github.com/LuxXx/reverse-engineering
namespace draww
{
    class Program
    {
        // SayiyaCevir
        private static ulong HexToUlong(string text)
        {
            try
            {
                return ulong.Parse(text, NumberStyles.HexNumber);
            }
            catch
            {
                return 0L;
            }
        }
        // Karistir
        private static string hash(string input)
        {
            byte[] inputAsArray = Encoding.UTF8.GetBytes(input);
            char[] chArray = BitConverter.ToString(new SHA512Managed().ComputeHash(inputAsArray)).Replace("-", "").ToCharArray();
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < 128; i++)
            {
                if ((i % 8) == 0)
                {
                    builder.Append(chArray[i].ToString());
                }
            }
            return builder.ToString();
        }
        private static ulong magic = bruteforce(); //0xDADADADADA; // do not use bruteforce(), use the value if you want to generate the key asap
        public static string generateKey(string name)
        {
            ulong hashedulongName = HexToUlong(hash(name));
            ulong key = magic + hashedulongName;
            string gKey = key.ToString("X16");
            return gKey.Substring(0, 4) + "-" + gKey.Substring(4, 4) + "-" + gKey.Substring(8, 4) + "-" + gKey.Substring(12, 4);

        }
        static void Main(string[] args)
        {
            // LuxXx C96D-0AEE-9F18-2DDD
            Console.WriteLine(generateKey("LuxXx"));
            Console.WriteLine(generateKey("David"));
            Console.WriteLine(generateKey("luxdav"));
            Console.ReadKey();
        }
        private static ulong bruteforce()
        {
            // this in theory bruteforces the value for hash(value) == DC53C973E73CDED6 is true
            // i know that this does not brute forces it in reality, i do not have enough knowledge and computing power to write and run an efficient algorithm to do this
            // the initial value is slightly below the real value, i looked it up from redoC's solution. Thank you for that.
            // my computer needs for 0xDADACAAAAA - real value less than a minute, in reality an adequate server would need some hours to days i think
			// if you want really want to test this, start with 0, and let it run some weeks or months or years ^^
            for (ulong i = 0xDADACAAAAA; i < ulong.MaxValue; i++)
            {
                if (hash(i.ToString()).Equals("DC53C973E73CDED6"))
                {
                    Console.WriteLine("Found the magic: " + i.ToString("X"));
                    return i;
                }
            }
            return 0;
        }
    }
}
