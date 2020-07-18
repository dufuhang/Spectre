#include <iostream>
#include "../spectre/log.h"
#include "../spectre/util.h"

int main(int argc, char** argv)
{
    spectre::Logger::ptr logger(new spectre::Logger);
    logger -> addAppender(spectre::LogAppender::ptr(new spectre::StdoutLogAppender));

    //这里写不进去
    spectre::FileLogAppender::ptr file_appender(new spectre::FileLogAppender("./log.txt"));
    spectre::LogFormatter::ptr fmt(new spectre::LogFormatter("%d%T%m%n"));
    file_appender -> setFormatter(fmt);
    file_appender -> setLevel(spectre::LogLevel::ERROR);

    logger -> addAppender(file_appender);
    //spectre::LogEvent::ptr event(new spectre::LogEvent(__FILE__, __LINE__, 0, spectre::GetThreadId(), spectre::GetFiberId(), time(0)));
    //event -> getSS() << "hello spectre!";
    //logger -> log(spectre::LogLevel::DEBUG, event);

    std::cout << "hello spectre" << std::endl;

    SPECTRE_LOG_INFO(logger) << "test marco!";
    SPECTRE_LOG_ERROR(logger) << "test marco error";

    SPECTRE_LOG_FMT_ERROR(logger, "test marco fmt error %s", "aa");
    auto l = spectre::Loggermgr::GetInstance() -> getLogger("xx");
    SPECTRE_LOG_INFO(l) << "xx";
    return 0;
}
