# convert.ps1
$tools_path = "../packages/vcpkg-export-20210627-101959.1.0.0/installed/x64-windows/tools/"
$protoc_path = $tools_path + "/protobuf/protoc.exe"
$grpc_plugin_path = $tools_path + "/grpc/grpc_cpp_plugin.exe"

# protobufクラス(*.pb.h, *.pb.cc)を生成する
Invoke-Expression ($protoc_path + " --proto_path=./ --cpp_out=./ ./foo.proto")
# grpcクラス(*.grpc.pb.h, *.grpc.pb.cc)を生成する
Invoke-Expression ($protoc_path + " --proto_path=./ --grpc_out=./ --plugin=protoc-gen-grpc=$grpc_plugin_path ./foo.proto")
