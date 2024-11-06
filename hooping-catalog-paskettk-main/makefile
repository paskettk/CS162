# TODO COMPLETE THIS MAKEFILE SO THAT IT BUILDS YOUR PROGRAM WHEN `make` IS
# EXECUTED FROM THE TERMINAL

# variables: 
CXX = g++ # C++ compiler 
CXX_FLAGS = -g # flags passed to the compiler 
EXE = catalog # name of the executable 
SRC = catalog.cpp run_catalog.cpp # source files 
OBJ = $(SRC:.cpp=.o) # object files from source files 
 
# targets: 
$(EXE): $(OBJ) # links the object files into the executable 
	$(CXX) $(CXX_FLAGS) $(OBJ) -o $(EXE) 
 
%.o: %.cpp catalog.h # compiles .cpp files into .o files 
	$(CXX) $(CXX_FLAGS) -c $< -o $@  
 
clean: 
	rm -f $(OBJ) $(EXE)


