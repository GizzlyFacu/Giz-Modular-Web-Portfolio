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
    abstractlistmodels/techskillsprojects3dart.h
    abstractlistmodels/techskillsprojects3dart.cpp
    abstractlistmodels/techskillsprojects3dgraphics.h
    abstractlistmodels/techskillsprojects3dgraphics.cpp
    abstractlistmodels/techskillsprojectsUE.h
    abstractlistmodels/techskillsprojectsUE.cpp
)

target_link_libraries(src_lib
    PRIVATE Qt6::Quick Qt6::Core
)
