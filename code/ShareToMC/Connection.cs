using System.Net.Sockets;
using System.Text;
using System;
using System.Threading.Tasks;
namespace MinecraftCSharp;

public class Connection : IDisposable
{
    private readonly TcpClient client;
    private readonly NetworkStream stream;
    
    public Connection(string host = "localhost", int port = 4711)
    {
        client = new TcpClient(host, port);
        stream = client.GetStream();
    }

    public void SendCommand(string command)
    {
        var msgBytes = Encoding.ASCII.GetBytes(command + "\n");
        stream.Write(msgBytes, 0, msgBytes.Length);
        stream.Flush();
    }

    public void Dispose()
    {
        stream?.Dispose();
        client?.Dispose();
    }
}