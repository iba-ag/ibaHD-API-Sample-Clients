#pragma once
#include <grpcpp\security\credentials.h>

class ApiKeyAuthenticator : public grpc::MetadataCredentialsPlugin {
public:
	ApiKeyAuthenticator(const grpc::string& apiKey) : _apiKey(apiKey) {}

	grpc::Status GetMetadata(grpc::string_ref service_url, grpc::string_ref method_name, const grpc::AuthContext& channel_auth_context,
		std::multimap<grpc::string, grpc::string>* metadata) override {

		metadata->insert(std::make_pair("ibahdapi-apikey", _apiKey));
		return grpc::Status::OK;
	}

private:
	grpc::string _apiKey;
};
