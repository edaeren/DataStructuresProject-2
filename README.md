# DataStructuresProject-2
This project is written in MinGW C++ and processes the Noktalar.txt file to manage data points in a priority queue and store them in an AVL tree. Each line in Noktalar.txt represents the x, y, and z coordinates of points forming line segments. A class named DogruKuyrugu is designed to handle these points, storing them as a priority queue based on their distance from the origin (0,0,0).

Commands
E(index#name): Adds data to the specified index. If the index does not exist, the data is appended to the end of the list.
S(index): Removes data from the specified index. If the index does not exist, the last element of the list is removed.
Output Format
After all commands in the file are executed, the resulting list is printed in the following format:
Ali Sarı <---> Ayşe Koru <---> Su Beyaz

Class and Data Structures
DogruKuyrugu: This class manages the points in a priority queue based on their proximity to the origin. Each line in Noktalar.txt is represented by an instance of this class.
AVL Tree: Once DogruKuyrugu objects are created, they are stored in an AVL tree. The insertion into the AVL tree is based on the total length of the line segments formed by the points in each DogruKuyrugu.
