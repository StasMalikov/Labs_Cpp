cmake_minimum_required(VERSION 3.16)
project(NewTask2)

set(CMAKE_CXX_STANDARD 17)

add_executable(NewTask2 main.cpp services/IOService.cpp services/IOService.h models/User.cpp models/User.h services/Utils.h models/TradeOrganization.cpp models/TradeOrganization.h services/models_services/IOUserService.cpp services/models_services/IOUserService.h models/UserList.cpp models/UserList.h)