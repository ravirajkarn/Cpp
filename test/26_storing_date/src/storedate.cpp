#include <chrono>
#include <iostream>
#include <fmt/chrono.h>
#include <fmt/core.h>
 
int main()
{
    //reporting month
    std::chrono::month m = std::chrono::month{2};
    std::cout << "February is " << ++m << '\n';
    std::cout << "February is " << m+std::chrono::months{2} << '\n';
    std::cout << "February is " << unsigned(m) << '\n';

    //reporting year month day
    std::chrono::year_month_day ymd = std::chrono::year_month_day{std::chrono::year{2019}, std::chrono::month{2}, std::chrono::day{21}}; 
    std::cout << "year_month_day is " << ymd << '\n';
    std::cout << "year_month_day is " << ymd.year() << '\n';
    std::cout << "year_month_day is " << unsigned(ymd.month()) << '\n';
    fmt::print("fmt year_month_day is {:%Y-%B-%d--%A}\n", ymd);

    //reporting now and storing date
    auto noww = std::chrono::system_clock::now();
    std::chrono::year_month_day today = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(noww)};
    fmt::print("fmt today is {:%Y-%B-%d--%A}\n", today);
    fmt::print("fmt today is {:%c}\n", noww);
    return 0;
}