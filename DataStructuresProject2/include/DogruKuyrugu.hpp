#ifndef DOGRUKUYRUGU_HPP
#define DOGRUKUYRUGU_HPP
#include <iostream>
#include "Node.hpp"
#include "Noktalar.hpp"
using namespace std;
 class DogruKuyrugu{
	 private:
		Node *front;
		Node *back;
		int length;
		int toplamUzunluk;
			
		Node* previousMinCloseNode() const;

	 public:
	
		DogruKuyrugu();
		Node* returnFront();
		int count() const;
		bool isEmpty() const;
		void clear();
		void enqueue(const Noktalar&);
	
	    Noktalar& peek() const;
		
		Noktalar& peekMin() const;
			
		void dequeue();
			
		void dequeueMaxClose();
		
		int DogruUzunlukHesapla();
		
		~DogruKuyrugu();
 };

#endif