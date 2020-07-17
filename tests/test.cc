#include <iostream>
#include "../spectre/log.h"

int main(int argc, char** argv)
{
    spectre::Logger::ptr logger(new spectre::Logger);
    logger -> addAppender(spectre::LogAppender::ptr(new spectre::StdoutLogAppender));

    spectre::LogEvent::ptr event(new spectre::LogEvent(__FILE__, __LINE__, 0, 1, 2, time(0)));
    event -> getSS() << "hello spectre!";
    logger -> log(spectre::LogLevel::DEBUG, event);

    std::cout << "hello spectre" << std::endl;
    return 0;
}
