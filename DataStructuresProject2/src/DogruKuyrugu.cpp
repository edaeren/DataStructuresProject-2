/** 
	
* @file G201210085
* @description Programim, dosyadan okudugu her satirdaki verileri once noktalar olarak ucer ucer alip daha sonra onlari kuyruga atiyor.
* Her bir kuyruk da agaca bir dugum olarak ekleniyor. Agac bir AVL agaci oldugundan bu kuyruktaki noktalarin olusturdugu dogrularin uzunluklarina gore 
* siralamasini yapiyor ve ona gore agaca ekleyip gerekirse dugumlerin yerlerini degistiriyor. En sonda da ciktiyi ekrana postorder olarak yazdiriyorum ancak 
* postorderda kuyruktaki verileri, orijine olan yakinligina gore siraliyorum ve noktalari degil de orijine olan uzakliklarini yazdiriyorum. 
* @course 2. ogretim A grubu (2A)
* @assignment 2. odev
* @date 25.12.2021'de bitti
* @author Eda Eren eda.eren@ogr.sakarya.edu.tr
*/

#include "DogruKuyrugu.hpp"

Node* DogruKuyrugu::previousMinCloseNode() const{
	Node *prev=NULL;
	Node *tmp=front;
	int min=front->data.orijineUzaklik;
	while(tmp->next!=NULL){
		if(tmp->next->data.orijineUzaklik<min){
			min=tmp->next->data.orijineUzaklik;
			prev=tmp;
		}
		tmp=tmp->next;
	}
	return prev;
}

DogruKuyrugu::DogruKuyrugu(){
	front=back=NULL;
	length=0;
	toplamUzunluk=0;
}

Node* DogruKuyrugu:: returnFront(){
	return front;
}

int DogruKuyrugu:: count() const{
	return length;
}

bool DogruKuyrugu::isEmpty() const{
	return length==0;
}
void DogruKuyrugu:: clear(){
	while(!isEmpty())
		dequeue();
}

void DogruKuyrugu:: enqueue(const Noktalar& item){
	Node *last=new Node(item,NULL);
	if(isEmpty()) front=back=last;
	else{
		back->next=last;
		back=back->next;
	}
	length++;
}

Noktalar& DogruKuyrugu::peek() const{
	if(isEmpty()) throw "Hata";
	return front->data;
}

Noktalar& DogruKuyrugu::peekMin() const{
	if(isEmpty()) throw "Hata";
	Node *prev=previousMinCloseNode();
	if(prev==NULL)return peek();
	return prev->next->data;
}

void DogruKuyrugu::dequeue(){
	if(isEmpty()) throw "Hata";
	Node *del=front;
	front=front->next;
	delete del;
	length--;
}
	
void DogruKuyrugu::dequeueMaxClose(){
	if(isEmpty()) throw "Hata";
	Node *prev=previousMinCloseNode();
	Node *tmp;
	if(prev==NULL)
		dequeue();
	else{
		if(prev->next==back) back==prev;
		tmp=prev->next;
		prev->next=tmp->next;
		delete tmp;
		length--;
	}
}
		
int DogruKuyrugu::DogruUzunlukHesapla(){
	int toplamUzunluk=0;
	Node *tmp=front;
	for(int i=1;i<length;i++){
		
		if(tmp->next!=NULL){
			int uzunluk=sqrt(pow(((tmp->next->data.x)-(tmp->data.x)),2)+pow(((tmp->next->data.y)-(tmp->data.y)),2) +pow(((tmp->next->data.z)-(tmp->data.z)),2));
			tmp=tmp->next;
			toplamUzunluk=toplamUzunluk+uzunluk;
		}
	}	
	return toplamUzunluk;
}
		
DogruKuyrugu::~DogruKuyrugu(){
	clear();
}