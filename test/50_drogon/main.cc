#include <drogon/drogon.h>
using namespace drogon;

int main() {
    // No manual handlers here! 
    // We rely on HelloController.cc to handle /hello
    LOG_INFO << "Server running on 0.0.0.0:5555";
    app().addListener("0.0.0.0", 5555).run();
    return 0;
}