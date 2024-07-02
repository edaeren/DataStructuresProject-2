#ifndef AVLNODE_HPP
#define AVLNODE_HPP 
#include "DogruKuyrugu.hpp"
#include <iostream>

class AVLNode{
	public:
		DogruKuyrugu data;
		AVLNode *sol;
		AVLNode *sag;
		int yukseklik;
	
		AVLNode(const DogruKuyrugu&,AVLNode*,AVLNode*);
};

#endif