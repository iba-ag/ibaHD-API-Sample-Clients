# ibaHD-API C# Sample Client

Before starting with the sample client, make sure the requirements for the server side are met, see main [README.md](../README.md) 

For questions about the general usage of the generated gRPC client code, please refer to the [official guide](https://grpc.io/docs/languages/csharp/) for C#.

The full ibaHD-API documentation can always be found in `C:\Program Files\iba\ibaHD-Server\ibaHD-API\ibaHD-API.proto` when ibaHD-Server is installed. It is readable with any text editor.

## Sample Client Requirements

- Visual Studio 2019 or Visual Studio Code
- .NET Core 3.1 SDK

## Prepare and run the sample client

1. Copy the `C:\Program Files\iba\ibaHD-Server\ibaHD-API\ibaHD-API.proto` file to `csharp\ibaHdApi\`

   The code will be automatically be generated when compiling the `ibaHdApi`library project

2. Open the `ibaHdApiSampleClient.sln` solution and restore NuGet packages
   
3. Update the `ibaHdApiSampleClient\Program.cs` with the information of your server

   - Change the IP/Port to your own setup
   - Add the API Key
   - Add the path to the exported TLS server certificate

  4. Compile & Run
