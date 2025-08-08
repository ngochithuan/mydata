namespace MinecraftCSharp;

public class Minecraft
{
    private readonly Connection connection;
    public Player Player { get; }
    public World World { get; }

    public Minecraft(string host = "localhost", int port = 4711)
    {
        connection = new Connection(host, port);
        Player = new Player(connection);
        World = new World(connection);
    }

    public void PostToChat(string message)
    {
        connection.SendCommand($"chat.post({message})");
    }
}