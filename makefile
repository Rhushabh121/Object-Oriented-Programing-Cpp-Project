CC=clang++
CFLAGS=--std=c++11

objects = Event.o Simulation.o  OrderedItem.o ListItem.o PartArrival.o StartAssembly.o EndAssembly.o ProductArrival.o Queue.o PriorityQueue.o Node.o 

# this rule will build A2 as the executable from the object files
all: A2main.o $(objects)
	$(CC) $(CFLAGS) -o A2 $< $(objects)

# this rule will build a .o file from a .cpp file. 
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
