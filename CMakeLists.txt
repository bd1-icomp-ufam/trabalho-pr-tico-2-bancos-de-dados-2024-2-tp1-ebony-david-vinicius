cmake_minimum_required(VERSION 3.10)

project(TP2_BD LANGUAGES CXX)

add_executable(upload)

target_compile_features(upload PRIVATE cxx_std_17)

target_sources(upload PRIVATE
    upload.cpp 
    src/artigo.cpp
    src/arquivo_hash.cpp
)

target_include_directories(upload PRIVATE include/)

add_executable(findrec)

target_compile_features(findrec PRIVATE cxx_std_17)

target_sources(findrec PRIVATE
    findrec.cpp 
    src/artigo.cpp
    src/arquivo_hash.cpp
)
target_include_directories(findrec PRIVATE include/)

add_executable(seek1)

target_compile_features(seek1 PRIVATE cxx_std_17)

target_sources(seek1 PRIVATE
    seek1.cpp 
    src/artigo.cpp
)
target_include_directories(seek1 PRIVATE include/)

add_executable(seek2)

target_compile_features(seek2 PRIVATE cxx_std_17)

target_sources(seek2 PRIVATE
    seek2.cpp
    src/artigo.cpp
)
target_include_directories(seek2 PRIVATE include/)

