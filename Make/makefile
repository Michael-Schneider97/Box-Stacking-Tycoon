# A makefile for box stacking tycoon (linux)

# name variables
programName := Box-Stacking-Tycoon
program 	:= ./$(programName)

# compilers and compiler flags
cppCompiler 		:= g++
linker 			:= g++
cppCompilerFlags 	:= -Wall -c -m64 -gdwarf-2 -std=c++17
linkerFlags 		:= -Wall -m64 -gdwarf-2 -std=c++17 
sdl2Stuff		:= -lSDL2

# phony targets
.phony: run
.phony: build
.phony: clean


run: build
	$(program)

build: $(program)

$(program): main.o 
	$(linker) $(linkerFlags) *.o -o "$@" $(sdl2Stuff)

main.o: ../SourceCode/main.cpp
	$(cppCompiler) $(cppCompilerFlags) "$<" -o "$@"
	
clean: rm *.o 
