using System;
using System.Threading.Tasks;

namespace MinecraftCSharp;

class Program
{
    public static async Task Main(string[] args)
    {
        try
        {
            var minecraft = new Minecraft();

            //minecraft.PostToChat("Connected to Minecraft server!");

            // Đặt block đá tại vị trí (0,0,0)
            Block block = new Block(1, 0);
            block = block.WithData(0);
            minecraft.World.SetBlock(0, 0, 0, block);

            var watch = System.Diagnostics.Stopwatch.StartNew();

            for (int z = 0; z <= 180; z++)
            {
                for (int x = 0; x <= 320; x++)
                {
                    minecraft.World.SetBlock(x, 1, z, Block.STONE);
                }
            }
            watch.Stop();
            var elapsedMs = watch.ElapsedMilliseconds;

            Console.WriteLine($"Time taken: {elapsedMs} ms");
        }
        catch (Exception ex)
        {
            Console.WriteLine("Error: " + ex.Message);
        }
    }
}