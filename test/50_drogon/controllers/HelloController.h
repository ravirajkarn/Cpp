#pragma once

// 1. Notice we include HttpController.h, NOT HttpSimpleController.h
#include <drogon/HttpController.h>

using namespace drogon;

// 2. Inherit from HttpController, NOT HttpSimpleController
class HelloController : public drogon::HttpController<HelloController>
{
  public:
    METHOD_LIST_BEGIN
    // Map /hello to the sayHello function
    METHOD_ADD(HelloController::sayHello, "/hello", Get);
    METHOD_LIST_END

    // Function declaration
    void sayHello(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
};