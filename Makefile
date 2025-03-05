CXX=g++
CXXFLAGS=-g -Wall -std=c++11
# Uncomment for parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o mydatastore.o user.o db_parser.o product.o product_parser.o util.o book.o clothing.o movie.o

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

main.o: main.cpp mydatastore.h db_parser.h product_parser.h util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c main.cpp -o main.o

mydatastore.o: mydatastore.cpp mydatastore.h datastore.h product.h user.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c mydatastore.cpp -o mydatastore.o

book.o: book.cpp book.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c book.cpp -o book.o

clothing.o: clothing.cpp clothing.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c clothing.cpp -o clothing.o

movie.o: movie.cpp movie.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c movie.cpp -o movie.o

user.o: user.cpp user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c user.cpp -o user.o

db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c db_parser.cpp -o db_parser.o

product.o: product.cpp product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c product.cpp -o product.o

product_parser.o: product_parser.cpp product_parser.h product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -c product_parser.cpp -o product_parser.o

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -c util.cpp -o util.o

clean:
	rm -f *.o amazon
