# ibaHD-API Python Sample Client

Before starting with the sample client, make sure the requirements for the server side are met, see main [README.md](../README.md) 

For questions about the general usage of the generated gRPC client code, please refer to the [official guide](https://grpc.io/docs/languages/python/) for Python. 

The full ibaHD-API documentation can always be found in `C:\Program Files\iba\ibaHD-Server\ibaHD-API\ibaHD-API.proto` when ibaHD-Server is installed. It is readable with any text editor.

## Sample Client Requirements

- Python 3.8.x
- pip version 9.0.1 or higher

## Prepare and run the sample client

**Install gRPC packages**

1. Upgrade pip
   ```
   python -m pip install --upgrade pip
   ```
2. Install gRPC for Python
   ```
   python -m pip install grpcio
   python -m pip install grpcio-tools
   ```

**Generate the client code**

1. In the `python` folder of the sample clients run:
    ```
    python -m grpc_tools.protoc -I="C:\Program Files\iba\ibaHD-Server\ibaHD-API" --python_out=. --grpc_python_out=. ibaHD-API.proto
    ```

**Prepare and run the sample client**

1. Update the `ibahdapi_sampleclient.py` with the information of your server
   - Change the IP/Port to your own setup
   - Add the API Key
   - Add the path to the exported TLS server certificate

2. Run the sample client

   ```
   python ibahdapi_sampleclient.py
   ```
