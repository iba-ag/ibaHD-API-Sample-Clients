#include <iostream>

#include <grpcpp\grpcpp.h>
#include <ibaHD-API.grpc.pb.h>

#include <memory>
#include <string>
#include <sstream>
#include <fstream>
#include "ApiKeyAuthenticator.h"

using namespace grpc;
using namespace ibahdapi::v1;

void read_file(const std::string& filename, std::string& data)
{
	std::ifstream file(filename.c_str(), std::ios::in);
	if (file.is_open())
	{
		std::stringstream ss;
		ss << file.rdbuf();
		file.close();
		data = ss.str();
	}
	return;
}

int main(int argc, char* argv[]) {
	const std::string server = "127.0.0.1:9003";
	const std::string apiKey = "<< ADD API KEY >>";
	const std::string certPath = "<< ADD PATH TO EXPORTED SERVER CERTIFICATE >>";

	// Read exported (PEM formatted) server TLS certificate from disk
	std::string cert;
	read_file(certPath, cert);
	grpc::SslCredentialsOptions opts = { cert };
	auto tls_cert_credentials = grpc::SslCredentials(opts);

	// Apply the api key to every request that is made with the client
	auto api_key_credentials = grpc::MetadataCredentialsFromPlugin(
		std::unique_ptr<grpc::MetadataCredentialsPlugin>(new ApiKeyAuthenticator(apiKey)));

	auto combined_credentials = grpc::CompositeChannelCredentials(tls_cert_credentials, api_key_credentials);

    // Increasing the default message size (~4MB) is recommended
	ChannelArguments channel_args;
	channel_args.SetMaxReceiveMessageSize(INT_MAX);

    // gRPC channel setup to connect to ibaHD-API endpoint in ibaHD-Server
	auto channel = grpc::CreateCustomChannel(server, combined_credentials, channel_args);

	// Instantiate ibaHD-API client on the gRPC channel
	auto client = HdApiService::NewStub(channel);

	// Simple request to retrieve stores
	ClientContext context;

	auto response = GetHdStoresResponse();
	auto status = client->GetHdStores(&context, GetHdStoresRequest(), &response);

	if (!status.ok())
	{
		std::cout << status.error_message() << std::endl;
	}

	for (auto hdstore : response.hd_stores()) {

		std::cout << hdstore.hd_store_name() << std::endl;
	}

	printf("\n\tPress Enter to exit...\n");
	std::cin.get();
}