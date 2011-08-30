TARGET=log4ctest
OBJS=main.o other.o mylog.o
INC=
LIBPATH=

%.o:%.cpp
	g++ -Wall -c -g -I$(INC) -I. $< -o $@ 

$(TARGET):$(OBJS)
	g++  $(OBJS) -llog4c -o $(TARGET)

.PHONY:clean

clean:
	rm *.o $(TARGET)
	
	
