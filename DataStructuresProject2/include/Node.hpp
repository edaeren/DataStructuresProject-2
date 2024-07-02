#ifndef NODE_HPP
#define NODE_HPP
#include "Noktalar.hpp"
#include<iostream>
# include <stdio.h>
# include <math.h>
using namespace std;
class Node{		
	public:
		Noktalar data;
		Node *next;
		Node(const Noktalar,Node*);
};
#endif