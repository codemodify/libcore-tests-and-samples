#
# https://gist.github.com/mbinna/c61dbb39bca0e4fb7d1f73b0d66a4fd1
#

# define the project + target
cmake_minimum_required(VERSION 3.10)
project(concurrency-zebra)

add_executable(${PROJECT_NAME}
	main.c
)



#
# libCore
#
set(libCore ~/Projects/codemodify/libcore) 								# point to `libCore` root include
target_compile_definitions(${PROJECT_NAME} PRIVATE -DlibCoreLinux) 		# define desired platform
target_include_directories(${PROJECT_NAME} PRIVATE ${libCore}) 			# use `libCore` headers
target_sources(${PROJECT_NAME}											# use `libCore` features & implementation we need
	PRIVATE ${libCore}/libcore-concurrency-thread-impl-zebra/thread_linux.c
)

#
# libCore OS deps IF chosen to use
#
target_link_libraries( ${PROJECT_NAME}
	pthread
)