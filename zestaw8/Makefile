CXX = g++

LIBS = 

CXXFLAGS = -Wall -std=c++11 -O2

HFILES = myqueue.h 

TARGET = myqueue.out

OBJECTS = myqueue.o 

%.o : %.cpp $(HFILES) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET) 

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core