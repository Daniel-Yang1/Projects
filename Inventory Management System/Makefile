objects = main.o View.o Control.o Store.o Queue.o List.o Product.o Location.o StoreLocation.o WHLocation.o

a3: $(objects)
	g++ -o a3 $(objects)

main.o: main.cc Control.h
	g++ -c main.cc 

View.o: View.h View.cc
	g++ -c View.cc

Control.o: Control.h Control.cc
	g++ -c Control.cc

Store.o: Store.h Store.cc
	g++ -c Store.cc

Queue.o: Queue.h Queue.cc Product.h
	g++ -c Queue.cc

List.o: List.h List.cc Product.h
	g++ -c List.cc

WHLocation.o: WHLocation.h WHLocation.cc Location.h
	g++ -c WHLocation.cc

StoreLocation.o: StoreLocation.h StoreLocation.cc Location.h
	g++ -c StoreLocation.cc
	
Location.o: Location.cc Location.h Product.h
	g++ -c Location.cc

Product.o: Product.cc Product.h 
	g++ -c Product.cc

clean:
	rm -f a3 *.o	

