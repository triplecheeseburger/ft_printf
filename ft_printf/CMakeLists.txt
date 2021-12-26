cmake_minimum_required(VERSION 3.21)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ft_printf
        format_cs5.c
        format_du.c
        format_x0.c
        ft_printf.c
        ft_printf.h
        initializers.c
        main.c
        utils.c proc_sign.c format_p.c)
