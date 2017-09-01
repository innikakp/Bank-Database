run: mainmenu.o llist.o uifunction.o
	g++ -o project2 mainmenu.o llist.o uifunction.o

mainmenu.o: mainmenu.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c mainmenu.cpp

llist.o: llist.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp

uifunction.o: uifunction.cpp
	g++ -ansi -pedantic-errors -Wall -c uifunction.cpp

clean:
	rm mainmenu.o llist.o uifunction.o

