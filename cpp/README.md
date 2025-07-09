# ibaHD-API C++ Sample Client

Before starting with the sample client, make sure the requirements for the server side are met, see main [README.md](../README.md) 

For questions about the general usage of the generated gRPC client code, please refer to the [official guide](https://grpc.io/docs/languages/cpp/) for C++.

The full API documentation can always be found in `C:\Program Files\iba\ibaHD-Server\ibaHD-API\ibaHD-API.proto` when ibaHD-Server is installed. It is readable with any text editor.

## Sample Client Requirements

- Visual Studio 2019 with C++ workload
- [CMake](https://cmake.org/download/) version >= 3.17.2
- [Vcpkg](https://docs.microsoft.com/de-de/cpp/build/vcpkg?view=vs-2019)

## Prepare and run the sample client

**Download and install CMake**

During the CMake installer wizard, chose to add CMake to the PATH variable

[cmake-3.18.4-win64-x64.msi](https://github.com/Kitware/CMake/releases/download/v3.18.4/cmake-3.18.4-win64-x64.msi)

**Install and configure Vcpkg**

For issues during setup, please refer to the [official guide](https://github.com/microsoft/vcpkg#quick-start-windows).

1. Create an empty folder, for example `C:\src\` and clone the Vcpkg repository into this folder

```
git clone https://github.com/microsoft/vcpkg
```

2. Execute the Vcpkg Bootstrap 

```
.\vcpkg\bootstrap-vcpkg.bat
.\vcpkg\vcpkg integrate install
```

3. Define a system environment variable for installing packages in 64 bit by default

```
set VCPKG_DEFAULT_TRIPLET=x64-windows
```

5. Install the gRPC package

```
.\vcpkg\vcpkg install grpc
```

**Generate the sample client Visual Studio Solution with CMake**

In the sample client directory run the following commands:

1. Update the path to `ibaHD-API.proto` file in `CMakeLists.txt` if necessary 

2. In `cpp\build` execute 

   ```
   cmake-gui ../
   ```


3. Click on `Configure`, then `Generate` and `Open Project` to start Visual Studio

4. Update the `cpp\ibahdapi_sampleclient.cpp` with the information of your server
   - Change the IP/Port to your own setup

   - Add the API Key

   - Add the path to the exported TLS server certificate

5. Compile & Run
