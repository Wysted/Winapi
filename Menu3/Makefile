SOURCESCPP := $(wildcard *.cpp)
SOURCESRC := $(wildcard *.rc)
OBJECTS.O := $(subst .cpp,.o,$(SOURCESCPP))
OBJECTS.RES := $(subst .rc,.res,$(SOURCESRC))
OBJECTS += $(OBJECTS.O) $(OBJECTS.RES) $(LIB)
LIB := ..\..\..\..\..\..\WindowsKits\8.1\lib\winv6.3\um\x86\Gdi32.lib


main: $(OBJECTS) 
	g++ -o $@ $^
%.o : %.cpp
	g++ -o $@ -c $^ -I.
%.res : %.rc
	windres.exe -J rc -O coff -i $^ -o $@

info:
	$(info $(OBJECTS))




#hola.o: hola.cpp
#	g++ -c hola.cpp -I.