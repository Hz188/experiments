add_library(calculator_object OBJECT calculator.cpp)
target_link_libraries(calculator_object PRIVATE add sub)
add_library(calculator STATIC $<TARGET_OBJECTS:calculator_object> 
                            $<TARGET_OBJECTS:add_object> 
                            $<TARGET_OBJECTS:sub_object> 
                            $<TARGET_OBJECTS:common_object>) # 通过这个写法：calculator.lib会通过calculator.cpp和已经生成的common_object.o add_object.o sub_object.o共同打包lib了
target_include_directories(calculator PUBLIC ./) 