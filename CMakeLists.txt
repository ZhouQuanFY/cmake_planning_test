cmake_minimum_required(VERSION 3.29.0) #cmake最低版本

project(planning)

set(CMAKE_CXX_STANDARD 11) #C++版本17以上

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #设置可执行文件生成目录

# 把动态库dll和.exe都生成到指定的bin目录下
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

### 动态库 ######################################################################
#打包指定路径下所有.cpp路径到SRC_LISTS这个变量里
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LISTS) 

#把src下的所有cpp，生成一个动态链接库dll
add_library(common SHARED ${SRC_LISTS})
#动态链接库，包含需要的头文件路径
target_include_directories(common
 PUBLIC 
 ${PROJECT_SOURCE_DIR}/include
 )


### 可执行文件.exe ######################################################################
#添加可执行文件。指定生成的可执行文件.exe的文件名称，对应的.cpp文件路径
add_executable(planning_main planning_main.cpp)
# 可执行文件，也需要添加头文件目录
target_include_directories(planning_main 
PUBLIC 
${PROJECT_SOURCE_DIR}/include
)

# 可执行文件链接到dll
target_link_libraries(planning_main PUBLIC common)
# target_link_libraries(planning_main  ${PROJECT_SOURCE_DIR}/bin/Debug/common.dll)


