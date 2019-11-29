#版本  
cmake_minimum_required(VERSION 3.15.5)   

#项目名称                                        
project( charImg ) 

#指定c++版本 必须写在前面
set(CMAKE_CXX_STANDARD 11)

#设置OpenCV所在目录，为后面的find_package提供位置                                                      
#OpenCV_DIR为OpenCV源码编译后得到的文件夹                  
set( OpenCV_DIR /usr/local/Cellar/opencv/4.1.2)  

#会在OpenCV所在目录查找配置文件OpenCVConfig.cmake  
find_package( OpenCV REQUIRED )    

#向工程添加源文件                                         
add_executable( charImg charImg.cpp )    

#添加链接库                                   
target_link_libraries(charImg ${OpenCV_LIBS} )

