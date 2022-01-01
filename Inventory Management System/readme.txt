Daniel Yang
101194970

Files included:

	Makefile
	Control.h
		Controls the interaction between the inventory system (store) and the user
	Control.cc
	defs.h
	List.h
		A list of Products
	List.cc
	Location.h
		A virtual base class for StoreLocation and WHLocation
	Location.cc
	main.cc
		For testing
	Product.h
		Contains information about the product, including StoreLocation and WHLocations
	Product.cc
	Queue.h
		Queue for WHLocation
	Queue.cc
	Store.h
		Provides an interface for interacting with the inventory system
	Store.cc
	StoreLocation.h
		Concrete implementation for in-store product locations
	StoreLocation.cc
	View.h
		Collects user input for test purposes
	View.cc
	WHLocation.h
		Implementation for warehouse product locations
	WHLocation.cc
	

Assignment can be compiled using "make a3" and then run using ./a3
