CXX = g++

LIBS = 

CXXFLAGS = -Wall -std=c++11 -O2

HFILES = bst.h 

TARGET = bst.out

OBJECTS = bst.o 

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET) 

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core