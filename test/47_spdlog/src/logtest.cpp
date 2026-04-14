#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"


int file() {
    // 1. Create a console sink (for colored output to stdout)
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::info); // Set minimum level for console output
    console_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] %v"); // Custom pattern for console

    // 2. Create a file sink (for logging to a file)
    // The file "mylog.log" will be created if it doesn't exist.
    // Ensure the directory for the file exists if you use a relative path like "logs/mylog.log".
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("mylog.log", true); // true for append mode
    file_sink->set_level(spdlog::level::trace); // Set minimum level for file output
    file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] %v"); // Custom pattern for file

    // 3. Combine the sinks into a vector
    std::vector<spdlog::sink_ptr> sinks{console_sink, file_sink};

    // 4. Create a logger with the combined sinks
    auto logger = std::make_shared<spdlog::logger>("my_app_logger", sinks.begin(), sinks.end());
    logger->set_level(spdlog::level::trace); // Set overall logger level
    spdlog::register_logger(logger); // Register the logger globally

    // 5. Use the logger to output messages
    logger->trace("This is a trace message.");
    logger->debug("This is a debug message.");
    logger->info("This is an info message.");
    logger->warn("This is a warning message.");
    logger->error("This is an error message.");
    logger->critical("This is a critical message.");

    // Optional: Flush the logger to ensure all messages are written to the file
    logger->flush();

    // Optional: Drop the logger when no longer needed (releases resources)
    spdlog::drop("my_app_logger");

    return 0;
}


void basic_logfile_example()
{
    try 
    {
        auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
        logger->critical("hello sumit is printed");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }
    
}

void stdout_example()
{
    // create a color multi-threaded logger
    auto console = spdlog::stdout_color_mt("console");    
    auto err_logger = spdlog::stderr_color_mt("stderr");    
    spdlog::get("console")->info("loggers can be retrieved from a global registry using the spdlog::get(logger_name)\n\n\n");
}

int main() 
{
    basic_logfile_example();
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");
    
    spdlog::set_level(spdlog::level::debug); // Set *global* log level to debug
    spdlog::debug("This message should be displayed..\n\n");    
    
    // change log pattern
    // spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // Note that this does not change the current log level, it will only
    // remove (depending on SPDLOG_ACTIVE_LEVEL) the call on the release code.
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug messag");

    stdout_example();
    file();
}
