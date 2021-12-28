cmake_minimum_required(VERSION 3.20)
project(clion_ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(clion_ft_printf
        ft_printf.c
        ft_printf.h
        format_csp5.c
        format_du.c
        format_x0.c
        main.c)
