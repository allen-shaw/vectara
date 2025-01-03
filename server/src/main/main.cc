#include <gflags/gflags.h>
#include <butil/logging.h>
#include "server/src/server/rpc_server.h"

DEFINE_int32(port, 50051, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");
DEFINE_bool(gzip, false, "compress body using gzip");

int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    GFLAGS_NS::ParseCommandLineFlags(&argc, &argv, true);

    RpcServer server(FLAGS_port);
    if (server.start() != 0) {
        LOG(ERROR) << "Fail to start RpcServer";
        return -1;
    }
    LOG(INFO) << "RpcServer started on port " << FLAGS_port;
    return 0;
}