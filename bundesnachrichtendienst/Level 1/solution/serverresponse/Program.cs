using System;
using System.IO;

namespace Bundesnachrichtendienst
{
    class Program
    {
        private static string installLinux()
        {
            string str = "The iron bank will have its due";
            return (str.Substring(0, 1).Replace('q', 'm').Replace('T', 'A').Replace('e', 'd').Replace('v', 's').Replace('r', 'L').Replace('i', 'a') + str.Substring(3, 1) + str.Substring(13, 1).Replace('i', 'k').Replace('A', 'k').Replace('n', 'q').Replace(' ', 'L').Replace('y', 'd').Replace('v', 'f').Replace('m', 'a').Replace('m', 'e') + str.Substring(10, 1) + str.Substring(7, 1) + str.Substring(7, 1) + str.Substring(4, 1) + str.Substring(0x1a, 1) + str.Substring(0x19, 1) + str.Substring(2, 1) + str.Substring(5, 1) + str.Substring(3, 1) + str.Substring(10, 1) + str.Substring(0x10, 1) + str.Substring(14, 1) + str.Substring(10, 1) + str.Substring(5, 1).Replace('c', 'l').Replace('m', 'v').Replace('d', 'o').Replace('k', 'd').Replace('r', 'y').Replace('u', 'A').Replace('g', 'm') + str.Substring(0x1a, 1) + str.Substring(3, 1) + str.Substring(13, 1).Replace('u', 's').Replace('q', 'A').Replace('k', 'a').Replace('f', 'g').Replace(' ', 'p').Replace('A', 'o').Replace('A', 'r').Replace('m', 'b') + str.Substring(10, 1) + str.Substring(4, 1).Replace('g', 'k').Replace('h', 'p').Replace('i', 'y').Replace('f', 'x').Replace('t', 'g').Replace('j', ' ').Replace(' ', 'b') + str.Substring(0x1a, 1) + str.Substring(3, 1) + str.Substring(1, 1) + str.Substring(4, 1) + str.Substring(0x1a, 1) + str.Substring(3, 1) + str.Substring(0x1c, 1) + str.Substring(2, 1) + str.Substring(9, 1) + str.Substring(0x19, 1) + str.Substring(0x1a, 1));
        }
        static void Main(string[] args)
        {
            Console.WriteLine(installLinux());
            Console.ReadKey();
        }
    }
}
