# Librería para todo el código C++
add_library(src_lib STATIC
    utils/jsonparsing.h
    utils/jsonparsing.cpp
    utils/networklayer.cpp
    utils/networklayer.h
    storagemanager.h
    storagemanager.cpp
    configcenter.h
    configcenter.cpp
    abstractlistmodels/blogcardmodel.h
    abstractlistmodels/blogcardmodel.cpp
    abstractlistmodels/techskillsprojects.h
    abstractlistmodels/techskillsprojects.cpp
)

target_link_libraries(src_lib
    PRIVATE Qt6::Quick Qt6::Core
)
