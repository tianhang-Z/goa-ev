#pragma once

#include <string.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <syncstream>
#include <format>
#include <cstdio>
#include <vector>
// #include <cassert>

// #include <functional>
// #include <tuple>

namespace goa {

namespace ev {

inline std::string logFileName;
inline std::ofstream ofs;

namespace {

std::vector<std::string_view> logLevelStr{
    "[ TRACE]",
    "[ DEBUG]",
    "[  INFO]",
    "[  WARN]",
    "[ ERROR]",
    "[ FATAL]"
};


inline std::string timestamp(){
    auto now = std::chrono::system_clock::now(); // 返回一个时间戳  单位ns
    // 时间戳是 std::chrono::time_point<std::chrono::system_clock, duration> 类型

    std::time_t time = std::chrono::system_clock::to_time_t(now); // 转c里面的time_t 单位s

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) %1000;

    std::stringstream ss;
    ss << std::put_time(std::gmtime(&time), "%Y%m%d %H:%M:%S") << "."
       << std::setfill('0') << std::setw(3) << ms.count();
    return ss.str();
}

} // namespace anonymous


enum class LOG_LEVEL :unsigned{
    LOG_LEVEL_TRACE=0,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
};

#ifndef NDEBUG
static LOG_LEVEL logLevel = LOG_LEVEL::LOG_LEVEL_DEBUG;
#else
static LOG_LEVEL logLevel = LOG_LEVEL::LOG_LEVEL_INFO;
#endif

namespace internal{

template<typename... Args>
inline void logSys(const std::string&file,
                   int line,
                   int to_abort,
                   const std::string& fmt,
                   Args... args){
    std::stringstream ss;
    ss << timestamp();

    ss << " [";
    ss << std::setfill(' ') << std::setw(5) << getpid();
    ss << "] ";

    auto sysfa = "[ SYSFA] ";
    auto syserr = "[SYSERR] ";
    (void)sysfa;
    (void)syserr; // erase [-Werror=unused-value]
    ss << (to_abort ? sysfa : syserr);
    ss << std::vformat(fmt, std::make_format_args(args...));

    //std::osyncstream 通过在多个线程之间提供同步机制，
    //确保输出流的写操作是互斥的。确保日志或调试信息等输出不会被其他线程的输出干扰。
    if(logFileName.empty()|| logFileName =="stdout"){
        std::osyncstream osync(std::cout);
        osync << std::format("{}: {} - {}:{}\n", ss.str().c_str(), strerror(errno), strchr(file.c_str(), '/') + 1, line) << std::flush;
    }
    else{
        std::osyncstream osync(ofs);       //同步写入流
        osync << std::format("{}: {} - {}:{}\n", ss.str().c_str(), strerror(errno), strchr(file.c_str(), '/') + 1, line) << std::flush;
    }

    if(to_abort){
        abort();
    }
}

template<typename... Args>
inline void logBase(const std::string& file,
                    int line,
                    LOG_LEVEL level,
                    int to_abort,
                    const std::string& fmt,
                    Args... args){
    std::ostringstream ss;
    ss << timestamp();
    ss << " [";
    ss << std::setfill(' ') << std::setw(5) << getpid();
    ss << "]";
    ss << " " << logLevelStr[static_cast<unsigned>(level)] << " ";
    ss << std::vformat(fmt, std::make_format_args(args...));

    if(logFileName.empty()|| logFileName =="stdout"){
        std::osyncstream osync(std::cout);
        osync << std::format("{} - {}:{}\n", ss.str().c_str(), strchr(file.c_str(), '/') + 1, line) << std::flush;
    }
    else{
        std::osyncstream osync(ofs);       //同步写入流
        osync << std::format("{} - {}:{}\n", ss.str().c_str(), strchr(file.c_str(), '/') + 1, line) << std::flush;
    }
    
    if(to_abort){
        abort();
    }
}

} // namespace internal 内部接口，不对外使用，但又因为需要在别的文件中被调用，因此没有写入上面的anonymous namespace

// 对外日志接口

#define TRACE(fmt, ...)  if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_TRACE)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_TRACE, 0, fmt, ##__VA_ARGS__);

#define DEBUG(fmt, ...)  if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_DEBUG)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_DEBUG, 0, fmt, ##__VA_ARGS__);

#define INFO(fmt, ...)   if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_INFO)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_INFO, 0, fmt, ##__VA_ARGS__);

#define WARN(fmt, ...)   if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_WARN)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_WARN, 0, fmt, ##__VA_ARGS__);

#define ERROR(fmt, ...)  if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_ERROR)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_ERROR, 0, fmt, ##__VA_ARGS__);

#define FATAL(fmt, ...)  if (static_cast<unsigned>(goa::ev::logLevel) <= static_cast<unsigned>(goa::ev::LOG_LEVEL::LOG_LEVEL_FATAL)) \
goa::ev::internal::logBase(__FILE__, __LINE__, goa::ev::LOG_LEVEL::LOG_LEVEL_FATAL, 1, fmt, ##__VA_ARGS__);

#define SYSERR(fmt, ...) goa::ev::internal::logSys(__FILE__, __LINE__, 0, fmt, ##__VA_ARGS__);

#define SYSFATAL(fmt, ...) goa::ev::internal::logSys(__FILE__, __LINE__, 1, fmt, ##__VA_ARGS__);

inline void setLogLevel(LOG_LEVEL rhs) { logLevel = rhs; }

inline void setLogFile(const std::string& fileName){
    // 关闭logFileName
    if (logFileName.size() > 0 && logFileName != "stdout"){
        ofs.close();
    }
    if (fileName != "stdout"){
        ofs.open(fileName, std::ios_base::out | std::ios_base::app);
    }
    logFileName = std::move(fileName);
}

}//namespace ev

} // namespace goa