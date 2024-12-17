CXX = g++

LIBS = 

CXXFLAGS = -Wall -std=c++11 -O2

HFILES = binarytree.h 

TARGET = binarytree.out

OBJECTS = binarytree.o 

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET) 

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core