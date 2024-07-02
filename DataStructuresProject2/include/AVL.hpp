#ifndef AVL_HPP
#define AVL_HPP
#include "DogruKuyrugu.hpp"
#include <iostream>
#include <cmath>
#include "AvlNode.hpp"
#include "DogruKuyrugu.hpp"
#include "Node.hpp"
using namespace std;

class AVL{
	private:	
		AVLNode *kok;
		int ilkYazilacak;

		AVLNode* AraVeEkle(AVLNode*, DogruKuyrugu&);
		
		AVLNode* SolCocukIleDegistir(AVLNode*);
		
		AVLNode* SagCocukIleDegistir(AVLNode*);
		
		bool DeleteAVLNode(AVLNode*&);
		
	
		void postorder(AVLNode*);
		
		int Yukseklik(AVLNode*);
		
	public:
		AVL();
		
		bool isEmpty()const;
		
		void Add( DogruKuyrugu&);
	
		void postorder();
	
		int Yukseklik();

		void Clear();
		~AVL();
};

#endif