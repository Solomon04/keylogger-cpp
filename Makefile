# SRCS = src/main.cpp #Put here the relative path to your .cpp
# 	= src/resource.rc 

# OBJS = $(SRCS:.cpp=.o, .) # Here you get the .o of every .cpp

# TARGET = output # The executable name

# CC = g++

# all: $(TARGET)

# $(TARGET):	$(OBJS) # This line will compile to .o every .cpp which need to be (which have been modified)
# 	$(CC) -o $(TARGET) $(OBJS) 


all: chrome

chrome: main.o icon.o
	g++ main.o icon.o -o chrome

main.o: src/main.cpp
	g++ -c src/main.cpp

icon.o: src/icon.rc
	windres src/icon.rc -o icon.o

clean: 
	rm *.o *.exe *.txt