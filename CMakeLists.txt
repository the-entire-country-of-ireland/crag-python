cmake_minimum_required(VERSION 3.8)

project(crag)

# bonus points (not really) for any team that turns this
# into a proper python package

# I couldn't get find_package (Python3) to work properly

# crag is weird so we statically compile and link but with -fPIC.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Ofast -std=c++14 -pthread")

set(Boost_USE_STATIC_LIBS OFF)
add_definitions(-DBOOST_ALL_DYN_LINK)
set(BOOST_LIBRARYDIR "/opt/python/cp38-cp38/lib")

include_directories("/opt/python/cp38-cp38/include/python3.8")

set(PYTHON3_ROOT_DIR "/opt/python/cp38-cp38/")
set(Python3_EXECUTABLE "/opt/python/cp38-cp38/bin/python")
set(Python3_INCLUDE_DIRS "/opt/python/cp38-cp38/include/python3.8")
# set(Python_FIND_VIRTUALENV FIRST)

### Find dependencies ###
# find_package (Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(Boost REQUIRED program_options COMPONENTS python38)

set_property(GLOBAL PROPERTY USE_FOLDERS ON) #turn on folders for VS

# Add subdirectories (All new directories should go here)

# add_subdirectory(3rdParty/gmp)
add_subdirectory(Alphabet)
add_subdirectory(BraidGroup)
# add_subdirectory(CryptoAAG)
# add_subdirectory(CryptoAE)
# add_subdirectory(CryptoKL)
# add_subdirectory(CryptoShftConj)
# add_subdirectory(CryptoTripleDecomposition)
add_subdirectory(Elt)
add_subdirectory(Equation)
add_subdirectory(Examples)
add_subdirectory(FiniteField)
add_subdirectory(FreeGroup)
add_subdirectory(general)
add_subdirectory(Graph)
add_subdirectory(Graphics)
add_subdirectory(Group)
# add_subdirectory(HigmanGroup)
add_subdirectory(Maps)
add_subdirectory(ranlib)
add_subdirectory(StringSimilarity)
add_subdirectory(SbgpFG)
# add_subdirectory(TheGrigorchukGroup)
add_subdirectory(Polynomial)
add_subdirectory(Matrix)
add_subdirectory(Random)
# add_subdirectory(Kayawood)
# add_subdirectory(Walnut)

