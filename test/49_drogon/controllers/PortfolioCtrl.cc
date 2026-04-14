#include "PortfolioCtrl.h"

void PortfolioCtrl::handleHome(const HttpRequestPtr &req,
                               std::function<void(const HttpResponsePtr &)> &&callback) {
    
    // Create data to pass to the view
    HttpViewData data;
    data.insert("title", "My C++ Portfolio");
    data.insert("developer_name", "Alex Coder");
    data.insert("intro_text", "I build high-performance backend systems using C++ and Drogon.");

    // Simple project list (In a real app, this might come from a database)
    std::vector<std::string> projects = {
        "High-Frequency Trading Engine",
        "Drogon Web Server Implementation",
        "Custom Game Engine"
    };
    data.insert("projects", projects);

    // Render the 'index.csp' view
    auto resp = HttpResponse::newHttpViewResponse("Home.csp", data);
    callback(resp);
}