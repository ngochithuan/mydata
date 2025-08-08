namespace MinecraftCSharp;

public class Player
{
    private readonly Connection connection;

    public Player(Connection connection)
    {
        this.connection = connection;
    }

    public (int x, int y, int z) GetPosition()
    {
        // TODO: Implement get position logic
        return (0, 0, 0);
    }
}