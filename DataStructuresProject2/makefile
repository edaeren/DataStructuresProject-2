hepsi: derle calistir
derle:
	
	g++ -I ./include/ -o ./lib/Node.o  -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Noktalar.o  -c ./src/Noktalar.cpp
	g++ -I ./include/ -o ./lib/AvlNode.o  -c ./src/AvlNode.cpp
	g++ -I ./include/ -o ./lib/DogruKuyrugu.o  -c ./src/DogruKuyrugu.cpp
	g++ -I ./include/ -o ./lib/AVL.o  -c ./src/AVL.cpp
	
	g++ -I ./include/ -o ./bin/Test2   ./lib/Node.o ./lib/Noktalar.o ./lib/AvlNode.o ./lib/DogruKuyrugu.o ./lib/AVL.o ./src/Test2.cpp
	
calistir:
	./bin/Test2