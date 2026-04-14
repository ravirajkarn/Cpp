#include "HelloController.h"

void HelloController::sayHello(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    // Create a response object
    auto resp = HttpResponse::newHttpResponse();
    
    // Set the body of the response
    resp->setBody("Hello from Drogon!");
    
    // Set the status code (200 OK)
    resp->setStatusCode(k200OK);
    
    // Send the response back to the user
    callback(resp);
}