using System;

namespace MinecraftCSharp;

public class World 
{
    private readonly Connection connection;

    public World(Connection connection)
    {
        this.connection = connection;
    }

    public void SetBlock(int x, int y, int z, Block block)
    {
        connection.SendCommand($"world.setBlock({x},{y},{z},{block})");
    }

    // Overload cho backward compatibility
    public void SetBlock(int x, int y, int z, string blockType)
    {
        Block block = blockType.ToUpper() switch
        {
            "STONE" => Block.STONE,
            "GRASS" => Block.GRASS,
            "DIRT" => Block.DIRT,
            "COBBLESTONE" => Block.COBBLESTONE,
            "WOOD" => Block.WOOD,
            "DIAMOND_BLOCK" => Block.DIAMOND_BLOCK,
            "GOLD_BLOCK" => Block.GOLD_BLOCK,
            "IRON_BLOCK" => Block.IRON_BLOCK,
            "GLASS" => Block.GLASS,
            "TNT" => Block.TNT,
            _ => Block.STONE // default to stone
        };
        SetBlock(x, y, z, block);
    }
}