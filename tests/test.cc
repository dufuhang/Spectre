#include <iostream>
#include "../spectre/log.h"
#include "../spectre/util.h"

int main(int argc, char** argv)
{
    spectre::Logger::ptr logger(new spectre::Logger);
    logger -> addAppender(spectre::LogAppender::ptr(new spectre::StdoutLogAppender));

    //spectre::LogEvent::ptr event(new spectre::LogEvent(__FILE__, __LINE__, 0, spectre::GetThreadId(), spectre::GetFiberId(), time(0)));
    //event -> getSS() << "hello spectre!";
    //logger -> log(spectre::LogLevel::DEBUG, event);

    std::cout << "hello spectre" << std::endl;

    SPECTRE_LOG_INFO(logger) << "test marco!";
    SPECTRE_LOG_ERROR(logger) << "test marco error";
    return 0;
}
