#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <stdio.h>

// Log levels
#define LOG_LEVEL_DEBUG 0
#define LOG_LEVEL_INFO  1
#define LOG_LEVEL_ERROR 2

// Default log level if not specified
#ifndef MIN_LOG_LEVEL
    #ifdef MIN_LOG_LEVEL_DEBUG
        #define MIN_LOG_LEVEL LOG_LEVEL_DEBUG
    #elif defined(MIN_LOG_LEVEL_INFO)
        #define MIN_LOG_LEVEL LOG_LEVEL_INFO
    #elif defined(MIN_LOG_LEVEL_ERROR)
        #define MIN_LOG_LEVEL LOG_LEVEL_ERROR
    #else
        #define MIN_LOG_LEVEL LOG_LEVEL_INFO
    #endif
#endif

// Default tag if not specified
#ifndef LOGGER_TAG
    #define LOGGER_TAG "LOG"
#endif

// Logger macros
#if MIN_LOG_LEVEL <= LOG_LEVEL_DEBUG
    #define Logger_DEBUG(fmt, ...) printf("[D][%s] " fmt "\n", LOGGER_TAG, ##__VA_ARGS__)
#else
    #define Logger_DEBUG(fmt, ...) ((void)0)
#endif

#if MIN_LOG_LEVEL <= LOG_LEVEL_INFO
    #define Logger_INFO(fmt, ...) printf("[I][%s] " fmt "\n", LOGGER_TAG, ##__VA_ARGS__)
#else
    #define Logger_INFO(fmt, ...) ((void)0)
#endif

#if MIN_LOG_LEVEL <= LOG_LEVEL_ERROR
    #define Logger_ERROR(fmt, ...) printf("[E][%s] " fmt "\n", LOGGER_TAG, ##__VA_ARGS__)
#else
    #define Logger_ERROR(fmt, ...) ((void)0)
#endif

#endif /* __LOGGER_H__ */
