#pragma once

#ifndef LINUX

#ifdef EXPORT
#define CMAKE_STUDY_API __declspec(dllexport)
#else
#define CMAKE_STUDY_API __declspec(dllimport)
#endif

#else
#define CMAKE_STUDY_API
#endif
// 这几行宏定义是为了不同平台的dll库导出的跨平台实现
// 通过这几行宏，我们在cmake中通过add_definitions(-DLINUX)来指定宏
// 来进入不同的#ifdef分支，实现不同平台的库导出