CXXFLAGS = -std=c++11 -O2 -g -Wall -fmessage-length=0

SRC_DIR=src
HDR_DIR=hdr
OBJ_DIR=obj

LIBS=-lpq

TARGET=postgres_test

INCLUDE=-Ihdr/ \
		-I/usr/local/include/
		
SOURCES=$(wildcard $(SRC_DIR)/*.cpp)
OBJECTS=$(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

#the $< is the first item in the dependencies list
#the special macro $@, which are the left sides of the :
#the special macro $^, which are the right sides of the :
#$(shell pwd)
	
$(TARGET): $(OBJECTS)
	$(CXX) -o $(OBJ_DIR)/$@ $^ $(LIBS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp 
	@echo "Start build " $<
	$(CXX) $(CXXFLAGS) -c $< $(INCLUDE) -o $@
	@echo "End build " $<
	@echo

all:	$(TARGET)

clean:
	rm -f $(OBJECTS) $(OBJ_DIR)/$(TARGET)
