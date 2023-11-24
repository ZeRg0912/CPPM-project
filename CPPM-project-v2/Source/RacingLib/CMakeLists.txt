cmake_minimum_required(VERSION 3.10)
project(race_lib)

set(source_lib GameManager.cpp RaceTypes.h Transports.h)

add_library(race_lib SHARED ${source_lib})