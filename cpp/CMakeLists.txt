cmake_minimum_required(VERSION 3.17.2)

add_definitions(-D _WIN32_WINNT=0x0A00)
set(CMAKE_TOOLCHAIN_FILE "C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(PROTOC_PATH "C:/src/vcpkg/packages/protobuf_x64-windows/tools/protobuf/protoc.exe")
set(PROTOC_CPP_PLUGIN  "C:/src/vcpkg/packages/grpc_x64-windows/tools/grpc/grpc_cpp_plugin.exe")
set(PROTOBUF_INCLUDES "C:/src/vcpkg/installed/x64-windows/include/")

project (ibahdapi_sampleclient)
find_package(gRPC CONFIG REQUIRED)

# Proto file
get_filename_component(hw_proto "C:/Program Files/iba/ibaHD/ibaHD-API/ibaHD-API.proto" ABSOLUTE)
get_filename_component(hw_proto_path "${hw_proto}" PATH)

# Generated sources
set(hw_proto_srcs "ibahdapi/ibaHD-API.pb.cc")
set(hw_proto_hdrs "ibahdapi/ibaHD-API.pb.h")
set(hw_grpc_srcs "ibahdapi/ibaHD-API.grpc.pb.cc")
set(hw_grpc_hdrs "ibahdapi/ibaHD-API.grpc.pb.h")
add_custom_command(
      OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
      COMMAND ${PROTOC_PATH}
      ARGS --grpc_out "ibahdapi"
        --cpp_out "ibahdapi"
        -I "${PROTOBUF_INCLUDES}"
        -I "${hw_proto_path}"
        --plugin=protoc-gen-grpc=${PROTOC_CPP_PLUGIN}
        "${hw_proto}"
      DEPENDS "${hw_proto}")

file(GLOB HDAPI ./ibahdapi/*.cc)
add_library(ibahdapi ${hw_proto_srcs} ${hw_proto_hdrs} ${hw_grpc_srcs} ${hw_grpc_hdrs}) 
target_compile_options(ibahdapi PRIVATE "/W0")
target_link_libraries(ibahdapi PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts)


set(ibaHdApiBuildPATH "${CMAKE_CURRENT_SOURCE_DIR}/build/ibahdapi")

file(GLOB SOURCES ./*.cpp ./*.h)
add_executable(${PROJECT_NAME} ${SOURCES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
set_target_properties(ibahdapi_sampleclient PROPERTIES VS_CA_EXCLUDE_PATH "./ibahdapi")
target_link_libraries(ibahdapi_sampleclient PRIVATE ibahdapi gRPC::grpc++)
target_include_directories(ibahdapi_sampleclient PUBLIC ${ibaHdApiBuildPATH})
