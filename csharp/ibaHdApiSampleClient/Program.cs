using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
using Grpc.Core;
using ibaHdApi.V1;

namespace ibaHdApiSampleClient
{
    class Program
    {
        static void Main(string[] args)
        {
            // Read exported (PEM formatted) server TLS certificate from disk
            var serverCert = File.ReadAllText("<< ADD PATH TO EXPORTED SERVER CERTIFICATE >>");
            var tlsCertCredentials = new SslCredentials(serverCert);
            
            // Apply the api key to every request that is made with the client
            var apiKeyCredentials = CallCredentials.FromInterceptor((context, metadata) =>
            {
                metadata.Add("ibahdapi-apikey", "<< ADD API KEY >>");
                return Task.CompletedTask;
            });
            
            var combinedCredentials = ChannelCredentials.Create(tlsCertCredentials, apiKeyCredentials);
        
            // gRPC channel setup to connect to ibaHD-API endpoint in ibaHD-Server
            // Increasing the default message size (~4MB) is recommended
            var channel = new Channel("127.0.0.1:9003", combinedCredentials,
                new List<ChannelOption> { new ChannelOption(ChannelOptions.MaxReceiveMessageLength, Int32.MaxValue) });

            // Instantiate ibaHD-API client on the gRPC channel
            var client = new HdApiService.HdApiServiceClient(channel);

            // Simple request to retrieve stores
            var response = client.GetHdStores(new GetHdStoresRequest());
            
            // Clean channel shutdown (Check ShutdownAsync() documentation for details)
            channel.ShutdownAsync().Wait();
            
            Console.WriteLine(response);
            Console.ReadLine();
        }
    }
}
