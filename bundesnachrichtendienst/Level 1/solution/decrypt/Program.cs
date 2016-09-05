using System;
using System.IO;

namespace Bundesnachrichtendienst
{
    class Program
    {
        static private byte[] invertGravity(byte[] chi)
        {
            if ((chi.Length % 2) != 0)
            {
                throw new Exception("Verschl\x00fcsselte Datei hat falsche L\x00e4nge oder so.");
            }
            byte[] buffer = new byte[chi.Length / 2];
            for (int i = 0; i < buffer.Length; i++)
            {
                buffer[i] = Math.Min(chi[i * 2], chi[(i * 2) + 1]);
            }
            return buffer;
        }
        static void Main(string[] args)
        {
            String filePath = "Urlaubsphoto.png.crypt";
            byte[] chi = File.ReadAllBytes(filePath);
            byte[] bytes = invertGravity(chi);
            File.WriteAllBytes(filePath.Substring(0, filePath.Length - 6), bytes);
        }
    }
}
