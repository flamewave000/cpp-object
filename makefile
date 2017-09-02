library: src/obj_type.cpp
	g++ -std=c++14 -c src/obj_type.cpp
	@mkdir -p lib
	ar rcs lib/libobject.a obj_type.o
	@rm obj_type.o
	
sample: library samples/main.cpp
	g++ -std=c++14 -static samples/main.cpp -Llib -lobject -o sample
	
clean:
	rm -Rf lib/ sample obj_type.o || true
