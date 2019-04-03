# Protocol Buffers 

Protocol Buffers (C++版）のサンプル

- 公式ページ
    - https://developers.google.com/protocol-buffers/
- GitHub
    - https://github.com/protocolbuffers/protobuf

# overview

- ProtobufSample
    - 基本的な使い方サンプル

# Note

```cpp
// serialize
std::string&& bytes = foo.SerializeAsString();
```

```cpp
// deserialize
foo.ParseFromString( bytes );
```

```cpp
#include "google/protobuf/util/json_util.h"
// serialize to JSON
google::protobuf::util::MessageToJsonString( foo, &json );
```

```cpp
#include "google/protobuf/util/json_util.h"
// deserialize JSON
google::protobuf::util::JsonStringToMessage( json, &foo );
```
