cmake_minimum_required(VERSION 3.31)
project(SimulazioneFinale_2 C)

set(CMAKE_C_STANDARD 11)

add_executable(SimulazioneFinale_2 main.c
        TStack.c
        TQueue.c
        tinfo.c
        TArray.c
        list.c
        hashtable.c
        binary_tree.c)
