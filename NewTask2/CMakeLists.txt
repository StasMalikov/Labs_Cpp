cmake_minimum_required(VERSION 3.16)
project(NewTask2)

set(CMAKE_CXX_STANDARD 17)

#set(GCC_COVERAGE_COMPILE_FLAGS "-Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
#
#set(GCC_COVERAGE_COMPILE_FLAGSS "-g")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGSS}" )

add_executable(NewTask2 main.cpp services/IOService.cpp services/IOService.h models/User.cpp models/User.h services/Utils.h models/TradeOrganization.cpp models/TradeOrganization.h services/models_services/IOUserService.cpp services/models_services/IOUserService.h models/lists/UserList.cpp models/lists/UserList.h models/abstract/UniqueObj.h models/abstract/UniqueObj.h models/abstract/Seller.h models/Product.cpp models/Product.h models/lists/ProductList.cpp models/lists/ProductList.h models/Supplier.cpp models/Supplier.h models/Order.cpp models/Order.h models/abstract/Buyer.h models/lists/OrderList.cpp models/lists/OrderList.h models/abstract/List.h models/Shop.cpp models/Shop.h services/models_services/IOSupplierService.cpp services/models_services/IOSupplierService.h models/lists/ShopList.cpp models/lists/ShopList.h models/DeliveryOrganization.cpp models/DeliveryOrganization.h)