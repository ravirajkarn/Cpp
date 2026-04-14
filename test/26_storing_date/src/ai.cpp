/**
 * @file storedate.cpp
 * @author Sumit Kumar (ravirajkarn+storedata@outlook.com)
 * @brief store date in the date storage type.
 * @version 0.1
 * @date 2025-02-03
 *
 * @copyright Copyright (c) 2025
 *
 */

 #include <iostream>
 #include <chrono>
 #include <iomanip>
 #include <sstream>
 #include <stdexcept> // For exception handling
 
 // Function to parse a date string into a time_point
 std::chrono::time_point<std::chrono::system_clock> parse_date(const std::string &date_str, const std::string &format = "%Y-%m-%d")
 {
     std::istringstream ss(date_str);
     std::tm t{}; // Initialize to zero to avoid undefined behavior
     if (ss >> std::get_time(&t, format.c_str()))
     {
         std::time_t tt = mktime(&t); // Convert std::tm to time_t
         if (tt == -1)
         {
             throw std::runtime_error("Invalid date (mktime failed).");
         }
         return std::chrono::system_clock::from_time_t(tt);
     }
     else
     {
         throw std::runtime_error("Invalid date format.");
     }
 }
 
 // Function to format a time_point into a date string
 std::string format_date(const std::chrono::time_point<std::chrono::system_clock> &tp, const std::string &format = "%Y-%m-%d")
 {
     std::time_t tt = std::chrono::system_clock::to_time_t(tp);
     std::tm *localTime = std::localtime(&tt); // Or std::gmtime for UTC, handle timezone yourself
     std::stringstream ss;
     ss << std::put_time(localTime, format.c_str());
     return ss.str();
 }
 
 int main()
 {
     try
     {
         // 1. Storing the DOB:
         std::string dob_str;
         std::cout << "Enter date of birth (YYYY-MM-DD): ";
         std::cin >> dob_str;
 
         auto dob = parse_date(dob_str); // Parse the input string
 
         // 2. Displaying the DOB:
         std::cout << "Date of birth: " << format_date(dob) << std::endl;
 
         // 3. Calculating age (example):
         auto now = std::chrono::system_clock::now();
         auto age_seconds = std::chrono::duration_cast<std::chrono::seconds>(now - dob).count();
         double age_years = age_seconds / (60.0 * 60.0 * 24.0 * 365.25); // Approximate
         std::cout << "Age (approx.): " << age_years << std::endl;
     }
     catch (const std::runtime_error &e)
     {
         std::cerr << "Error: " << e.what() << std::endl;
         return 1; // Indicate an error
     }
 
     return 0;
 }