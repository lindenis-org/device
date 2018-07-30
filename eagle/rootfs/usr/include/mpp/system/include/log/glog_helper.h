#pragma once

#include <glog/logging.h>
#include <glog/raw_logging.h>

//配置输出日志的目录：
#define GLOG_FILE_PATH "/tmp/log"

class GLogHelper
{
public:
    //GLOG配置：
    GLogHelper(const char* program);

    //GLOG内存清理：
    ~GLogHelper();
};
