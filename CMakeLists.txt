cmake_minimum_required(VERSION 3.25)
project(operating_system_IPC_and_synchronisation C)

set(CMAKE_C_STANDARD 11)

add_executable(operating_system_IPC_and_synchronisation main.c supervisor/camera_supervisor.c supervisor/camera_supervisor.h supervisor/environment_supervisor.c supervisor/environment_supervisor.h util.h IPC/ipc.c IPC/ipc.h process/handling.c process/handling.h)
