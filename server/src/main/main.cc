#include <gflags/gflags.h>
#include <butil/logging.h>
#include <brpc/server.h>
#include <brpc/restful.h>

DEFINE_int32(port, 50051, "TCP Port of this server");
DEFINE_int32(idle_timeout_s, -1, "Connection will be closed if there is no "
             "read/write operations during the last `idle_timeout_s'");
DEFINE_bool(gzip, false, "compress body using gzip");

int main(int argc, char* argv[]) {
    // Parse gflags. We recommend you to use gflags as well.
    GFLAGS_NS::ParseCommandLineFlags(&argc, &argv, true);

    // Generally you only need one Server.
    brpc::Server server;

    // GreeterImpl http_svc;

    // // Add services into server. Notice the second parameter, because the
    // // service is put on stack, we don't want server to delete it, otherwise
    // // use brpc::SERVER_OWNS_SERVICE.
    // if (server.AddService(&http_svc,
    //                       brpc::SERVER_DOESNT_OWN_SERVICE) != 0) {
    //     LOG(ERROR) << "Fail to add http_svc";
    //     return -1;
    // }

    // // Start the server.
    // brpc::ServerOptions options;
    // options.idle_timeout_sec = FLAGS_idle_timeout_s;
    // if (server.Start(FLAGS_port, &options) != 0) {
    //     LOG(ERROR) << "Fail to start HttpServer";
    //     return -1;
    // }

    // // Wait until Ctrl-C is pressed, then Stop() and Join() the server.
    // server.RunUntilAskedToQuit();
    return 0;
}