from __future__ import print_function
import logging
import grpc
import ibaHD_API_pb2
import ibaHD_API_pb2_grpc

# Helper class to apply the api key to each call
# DO NOT MODIFY
class ApiKeyCallCredentials(grpc.AuthMetadataPlugin):
    def __init__(self, apikey):
        self._apikey = apikey
        
    def __call__(self, context, callback):
        metadata = (('ibahdapi-apikey', self._apikey),)
        callback(metadata, None)

def run():
    # FILL IN BELOW VALUES
    certificate_path = '\\path\\to\\certificate'
    api_key = 'api_key_from_hd_server'
    hd_server = '127.0.0.1:9003'
    
    # Read exported (PEM formatted) server TLS certificate from disk
    certificate = open(certificate_path, 'rb').read()
    tls_credentials = grpc.ssl_channel_credentials(certificate)

    # Apply the api key to every request that is made with the client
    apikey_credentials  = grpc.metadata_call_credentials(ApiKeyCallCredentials(api_key))

    combined_credentials = grpc.composite_channel_credentials(tls_credentials, apikey_credentials)

    # gRPC channel setup to connect to ibaHD-API endpoint in ibaHD-Server
    # Increasing the default message size (~4MB) is recommended (c int32 max = 2147483647)
    with grpc.secure_channel(hd_server, combined_credentials, options=[('grpc.max_receive_message_length', 2147483647)]) as channel:

        # Instantiate ibaHD-API client on the gRPC channel
        client = ibaHD_API_pb2_grpc.HdApiServiceStub(channel)

        # Simple request to retrieve stores
        response = client.GetHdStores(request=ibaHD_API_pb2.GetHdStoresRequest())

        print(response)

if __name__ == '__main__':
    logging.basicConfig()
    run()
