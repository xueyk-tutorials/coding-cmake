## -1) CMake最低版本号要求
cmake_minimum_required(VERSION 3.5)

## -2) 项目信息
project(my_math)

# 设置版本号，提前在.h.in配置文件中进行了宏定义
set(my_math_VERSION_MAJOR 1)
set(my_math_VERSION_MINOR 0)

# 自动将当前源目录(CMAKE_CURRENT_SOURCE_DIR)和构建目录(CMAKE_CURRENT_BINARY_DIR)添加到include路径。
set(CMAKE_INCLUDE_CURRENT_DIR ON)

## -3) 自定义编译选项
# 加入一个配置头文件，用于处理 CMake 对源码的设置。
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"         # 传入.h.in文件
    "${PROJECT_BINARY_DIR}/config.h"            # 生成.h文件，这里生成的路径为build/
)
# 通过.h.in文件中定义的宏，来决定是否使用自己的 MathFunctions 库
option(USE_MYMATH
        "Use provided math function" ON)
if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    # 添加子目录
    add_subdirectory(math)
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif(USE_MYMATH)


## 编译
# 查找当前目录下的所有源文件, 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


# 生成目标
add_executable(${PROJECT_NAME} main.cpp)
# 添加链接库，这里添加子目录生成的链接库
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})


## 安装
#



## 测试



## 构建安装包

