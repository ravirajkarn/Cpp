#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

class PortfolioCtrl : public drogon::HttpController<PortfolioCtrl> {
public:
    METHOD_LIST_BEGIN
        // Register the path "/" to the handleHome method
        ADD_METHOD_TO(PortfolioCtrl::handleHome, "/", Get);
    METHOD_LIST_END

    void handleHome(const HttpRequestPtr &req,
                    std::function<void(const HttpResponsePtr &)> &&callback);
};