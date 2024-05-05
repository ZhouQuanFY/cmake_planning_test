cmake_minimum_required(VERSION 3.29.0) #cmake最低版本
project(planning)

set(CMAKE_CXX_STANDARD 17) #C++版本17以上

#设置可执行文件生成目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#打包所有.cpp路径到SRC_LISTS这个变量里
aux_source_directory(. SRC_LISTS) # 点.表示当前路径

#添加可执行文件。指定生成的可执行文件.exe的文件名称，对应的.cpp文件路径
add_executable(planning_main ${SRC_LISTS})
