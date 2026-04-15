#include <fmt/core.h>
#include <filesystem>
#include <rapidxml.hpp>
#include <rapidxml_utils.hpp>

int main()
{
    fmt::print("Hello Sumit.\n");
    fmt::print("Current path is: {}\n", std::filesystem::current_path().c_str());

    fmt::print("\nFind the file: {}\n", std::filesystem::is_regular_file("f179486592.xml"));
    rapidxml::file<> xmlFile("f179486592.xml");
    std::vector<char> buffer(xmlFile.data(), xmlFile.data() + xmlFile.size());
    buffer.push_back('\0');

    rapidxml::xml_document<> doc;
    doc.parse<0>(&buffer[0]);

    fmt::print("Name of first node is: {}\n", doc.first_node()->name());

    rapidxml::xml_node<> *node = doc.first_node("channel");
    rapidxml::xml_attribute<> *attr = node->first_attribute();
    fmt::print("node {0} has value: {1} with attribute {2}\n", doc.first_node()->name(), node->value(), attr->value());

    return 0;
}
