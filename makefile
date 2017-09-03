SRC=src/obj_type.cpp
OBJ=obj_type.o
PNAME=obj
SAMPLE=samples/main.cpp
CFLAGS=-Iinclude
SCFLAGS=-Iinclude


library: $(SRC)
	g++ -std=c++14 $(CFLAGS) -c $(SRC)
	@mkdir -p lib
	ar rcs lib/lib$(PNAME).a $(OBJ)
	@rm $(OBJ)
	
sample: library $(SAMPLE)
	g++ -std=c++14 $(SCFLAGS) -static $(SAMPLE) -Llib -l$(PNAME) -o $(PNAME)-sample
	
clean:
	rm -Rf lib/ $(PNAME)-sample $(OBJ) || true
