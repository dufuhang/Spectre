#ifndef __SPECTRE_LOG_H__
#define __SPECTRE_LOG_H__

#include <iostream>
#include <string>
#include <stdint.h> //int32
#include <memory>   //智能指针
#include <list>
#include <sstream>  //stringstream
#include <fstream>
#include <vector>
#include <utility>  //make_pair
#include <stdarg.h> //va_list等
#include <map>
#include "singleton.h"

#define SPECTRE_LOG_LEVEL(logger, level) \
    if (logger->getLevel() <= level) \
    spectre::LogEventWrap(spectre::LogEvent::ptr(new spectre::LogEvent(logger, level, \
                    __FILE__, __LINE__, 0, spectre::GetThreadId(), \
            spectre::GetFiberId(), time(0)))).getSS()

#define SPECTRE_LOG_DEBUG(logger) SPECTRE_LOG_LEVEL(logger, spectre::LogLevel::DEBUG)
#define SPECTRE_LOG_INFO(logger) SPECTRE_LOG_LEVEL(logger, spectre::LogLevel::INFO)
#define SPECTRE_LOG_WARN(logger) SPECTRE_LOG_LEVEL(logger, spectre::LogLevel::WARN)
#define SPECTRE_LOG_ERROR(logger) SPECTRE_LOG_LEVEL(logger, spectre::LogLevel::ERROR)
#define SPECTRE_LOG_FATAL(logger) SPECTRE_LOG_LEVEL(logger, spectre::LogLevel::FATAL)

#define SPECTRE_LOG_FMT_LEVEL(logger, level, fmt, ...) \
    if (logger->getLevel() <= level) \
    spectre::LogEventWrap(spectre::LogEvent::ptr(new spectre::LogEvent(logger, level, \
                    __FILE__, __LINE__, 0, spectre::GetThreadId(), \
                    spectre::GetThreadId(), time(0)))).getEvent()->format(fmt, __VA_ARGS__)

#define SPECTRE_LOG_FMT_DEBUG(logger, fmt, ...) SPECTRE_LOG_FMT_LEVEL(logger, spectre::LogLevel::DEBUG, fmt, __VA_ARGS__)
#define SPECTRE_LOG_FMT_INFO(logger, fmt, ...) SPECTRE_LOG_FMT_LEVEL(logger, spectre::LogLevel::INFO, fmt, __VA_ARGS__)
#define SPECTRE_LOG_FMT_WARN(logger, fmt, ...) SPECTRE_LOG_FMT_LEVEL(logger, spectre::LogLevel::WARN, fmt, __VA_ARGS__)
#define SPECTRE_LOG_FMT_ERROR(logger, fmt, ...) SPECTRE_LOG_FMT_LEVEL(logger, spectre::LogLevel::ERROR, fmt, __VA_ARGS__)
#define SPECTRE_LOG_FMT_FATAL(logger, fmt, ...) SPECTRE_LOG_FMT_LEVEL(logger, spectre::LogLevel::FATAL, fmt, __VA_ARGS__)

namespace spectre
{
    class Logger;

    //日志级别
    class LogLevel
    {
        public:
            enum Level
            {
                UNKNOW = 0,
                DEBUG = 1,
                INFO  = 2,
                WARN  = 3, 
                ERROR = 4,
                FATAL = 5
            };
            static const char* ToString(Level level);
    };

    //日志事件。每个生成的日志都定义为LogEvent，日志所需要的字段和属性都定义在这里
    class LogEvent
    {
        public:
            typedef std::shared_ptr<LogEvent> ptr;
            LogEvent(std::shared_ptr<Logger> logger, LogLevel::Level level, 
                    const char* file, int32_t line,
                    uint32_t elapse,
                    uint32_t thread_id,
                    uint32_t fiber_id,
                    uint64_t time);

            const char* getFile() const { return m_file; }
            int32_t getLine() const { return m_len; }
            uint32_t getElapse() const { return m_elapse; }
            int32_t getThreadId() const { return m_threadId; }
            uint32_t getFiberId() const { return m_fiberId; }
            uint64_t getTime() const { return m_time; }
            const std::string getContent() const { return m_ss.str(); }
            std::shared_ptr<Logger> getLogger() const { return m_logger; }
            LogLevel::Level getLevel() const { return m_level; }

            std::stringstream& getSS() { return m_ss; }
            void format(const char* fmt, ...);
            void format(const char* fmt, va_list al);
        private:
            const char* m_file = nullptr;   //文件名
            int32_t m_len = 0;              //行号
            uint32_t m_elapse = 0;          //程序开始到现在的毫秒数
            int32_t m_threadId = 0;         //线程ID
            uint32_t m_fiberId = 0;         //协程ID
            uint64_t m_time;                //时间戳
            std::stringstream m_ss;          //内容

            std::shared_ptr<Logger> m_logger;

            LogLevel::Level m_level;
    };

    //封装LogEvent类
    class LogEventWrap
    {
        public:
            LogEventWrap(LogEvent::ptr e);
            ~LogEventWrap();
            std::stringstream& getSS();
            LogEvent::ptr getEvent() const { return m_event; }
        private:
            LogEvent::ptr m_event;
    };


    //日志格式器
    class LogFormatter
    {
        public:
            typedef std::shared_ptr<LogFormatter> ptr;
            LogFormatter(const std::string& pattern);
            //
            std::string format(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event);
        public:
            class FormatItem
            {
                public:
                    typedef std::shared_ptr<FormatItem> ptr;
                    virtual ~FormatItem() {}
                    //直接输入到流中，性能更好点
                    virtual void format(std::ostream& os, std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
            };
            //日志格式解析,Log4J
            void init();
        private:
            std::string m_pattern;
            std::vector<FormatItem::ptr> m_items;
    };

    //日志输出地
    class LogAppender
    {
        public:
            typedef std::shared_ptr<LogAppender> ptr;
            //日志输出地可以有多个，定义为虚析构
            virtual ~LogAppender() {}
            //定义为纯虚函数，此类变为抽象基类
            virtual void log(std::shared_ptr<Logger> logger, LogLevel::Level level, LogEvent::ptr event) = 0;
            //设置格式
            void setFormatter(LogFormatter::ptr val) { m_formatter = val; }
            //获取格式
            LogFormatter::ptr getFormatter() const { return m_formatter; }

            LogLevel::Level getLevel() const { return m_level; }
            void setLevel(LogLevel::Level val) { m_level = val; }
        protected:  //protected,可以是子类也能访问成员变量
            //这里要初始化，否则可能会赋予一个随机值，导致后续输出时判断失误，无法输出
            LogLevel::Level m_level = LogLevel::DEBUG;
            LogFormatter::ptr m_formatter;  //输出格式
    };

    //日志器
    //std::enable_shared_from_this<type>，才能在自己的成员函数获取自己的指针
    //auto self = shared_from_this()
    class Logger : public std::enable_shared_from_this<Logger>
    {
        public:
            typedef std::shared_ptr<Logger> ptr;
            Logger(const std::string& name = "root");
            void log(LogLevel::Level  level, LogEvent::ptr event);

            void debug(LogEvent::ptr event);
            void info(LogEvent::ptr event);
            void warn(LogEvent::ptr event);
            void error(LogEvent::ptr event);
            void fatal(LogEvent::ptr event);

            void addAppender(LogAppender::ptr appender);        //添加
            void delAppender(LogAppender::ptr appender);        //删除
            LogLevel::Level getLevel() const { return m_level; }//获取level
            void setLevel(LogLevel::Level val) { m_level = val; }//设置level
        
            const std::string& getName() const { return m_name; } //获取日志名称
        private:
            std::string m_name;                              //日志名称
            LogLevel::Level m_level;                         //日志级别
            std::list<LogAppender::ptr> m_appenders;         //Appender集合，输出到目的地列表
            LogFormatter::ptr m_formatter;
    };

    //输出到控制台的Appender
    class StdoutLogAppender : public LogAppender
    {
        public:
            typedef std::shared_ptr<StdoutLogAppender> ptr;
            void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;
    };

    //输出到文件的Appender
    class FileLogAppender : public LogAppender
    {
        public:
            typedef std::shared_ptr<FileLogAppender> ptr;
            FileLogAppender(const std::string& filename);
            void log(Logger::ptr logger, LogLevel::Level level, LogEvent::ptr event) override;

            //重新打开文件，文件打开成功则返回true
            bool reopen();
        private:
            std::string m_filename;
            std::ofstream m_filestream;
    };
    class LoggerManager
    {
        public:
            LoggerManager();
            Logger::ptr getLogger(const std::string& name);
            //初始化
            void init();
        private:
            std::map<std::string, Logger::ptr> m_logger;
            Logger::ptr m_root;
    };

typedef spectre::Singleton<LoggerManager> Loggermgr;
}

#endif  //__SPECTRE_LOG_H__
