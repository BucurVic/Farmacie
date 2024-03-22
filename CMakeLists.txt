cmake_minimum_required(VERSION 3.27)
project(Lab2_4 C)

set(CMAKE_C_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Lab2_4 main.c
        Medicament.h
        Medicament.c
        repo.c
        repo.h
        service.c
        service.h
        ui.c
        ui.h
        testeRepo.c
        testeRepo.h
        testeService.c
        testeService.h
        testMedicament.c
        testMedicament.h)
