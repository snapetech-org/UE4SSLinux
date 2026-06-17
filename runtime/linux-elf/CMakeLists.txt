cmake_minimum_required(VERSION 3.16)

project(ue4ssl_linux_elf_loaders LANGUAGES C)

add_library(ue4ssl_linux_client_loader SHARED ue4ssl_linux_client_loader.c)
target_compile_options(ue4ssl_linux_client_loader PRIVATE -std=c11 -Wall -Wextra -Wpedantic)
target_link_libraries(ue4ssl_linux_client_loader PRIVATE dl)
set_target_properties(
  ue4ssl_linux_client_loader
  PROPERTIES
    OUTPUT_NAME ue4ssl_linux_client_loader
    POSITION_INDEPENDENT_CODE ON
)

add_library(ue4ssl_linux_server_loader SHARED ue4ssl_linux_server_loader.c)
target_compile_options(ue4ssl_linux_server_loader PRIVATE -std=c11 -Wall -Wextra -Wpedantic)
target_link_libraries(ue4ssl_linux_server_loader PRIVATE dl)
set_target_properties(
  ue4ssl_linux_server_loader
  PROPERTIES
    OUTPUT_NAME ue4ssl_linux_server_loader
    POSITION_INDEPENDENT_CODE ON
)
