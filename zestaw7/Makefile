CXX = g++

LIBS = 

CXXFLAGS = -Wall -std=c++11 -O2

TARGET = onp.out

OBJECTS = onp.o 

%.o : %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET) 

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core
