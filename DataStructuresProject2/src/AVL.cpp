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

#include "AVL.hpp"

AVLNode* AVL:: AraVeEkle(AVLNode* alt_dugum, DogruKuyrugu& yeni){
	if(alt_dugum == NULL) alt_dugum = new AVLNode(yeni,NULL,NULL);
	else if(yeni.DogruUzunlukHesapla() <= alt_dugum->data.DogruUzunlukHesapla()){
		alt_dugum->sol = AraVeEkle(alt_dugum->sol,yeni);
				
		if(Yukseklik(alt_dugum->sol)- Yukseklik(alt_dugum->sag)==2){
			if(yeni.DogruUzunlukHesapla() < alt_dugum->sol->data.DogruUzunlukHesapla())
				alt_dugum = SolCocukIleDegistir(alt_dugum);
			else{
				alt_dugum->sol = SagCocukIleDegistir(alt_dugum->sol);
				alt_dugum = SolCocukIleDegistir(alt_dugum);
			}
		}
	}
	else if(yeni.DogruUzunlukHesapla() > alt_dugum->data.DogruUzunlukHesapla()){
		alt_dugum->sag = AraVeEkle(alt_dugum->sag,yeni);
				
		if(Yukseklik(alt_dugum->sag) == Yukseklik(alt_dugum->sol)+2){
			//eklenen yeni deger sagdan buyukse sagin sagina gider duz bir cizgi olusur direkt sag cocuk
			//ile degistirilir
			if(yeni.DogruUzunlukHesapla() > alt_dugum->sag->data.DogruUzunlukHesapla())
				alt_dugum = SagCocukIleDegistir(alt_dugum);
			//sagin soluna eklenmistir zikzak olur. once duz bir cizgi haline getiririz sonra da sag
			//cocuk ile degistirip demgeyi saglariz
			else{
				alt_dugum->sag = SolCocukIleDegistir(alt_dugum->sag);
				alt_dugum = SagCocukIleDegistir(alt_dugum);
			}
		}
	}
	else;
	
	alt_dugum->yukseklik = Yukseklik(alt_dugum);
	return alt_dugum;
}

AVLNode* AVL::SolCocukIleDegistir(AVLNode* alt_dugum){
	//tmp yukari cikiyor
	AVLNode *tmp = alt_dugum->sol;
	alt_dugum->sol = tmp->sag;
	tmp->sag = alt_dugum;

	alt_dugum->yukseklik = Yukseklik(alt_dugum);
	tmp->yukseklik = 1+max(Yukseklik(tmp->sol),alt_dugum->yukseklik);
	
	return tmp;
}

AVLNode* AVL::SagCocukIleDegistir(AVLNode* alt_dugum){
	AVLNode *tmp = alt_dugum->sag;
	alt_dugum->sag = tmp->sol; //solu kaybetmemek adina tmp'nin solunu atiyoruz
	tmp->sol = alt_dugum;
			
	alt_dugum->yukseklik = Yukseklik(alt_dugum);
	tmp->yukseklik = 1+max(Yukseklik(tmp->sag),alt_dugum->yukseklik);
			
	return tmp;
}

bool AVL::DeleteAVLNode(AVLNode*& alt_dugum){
	AVLNode *delAVLNode = alt_dugum;
			
	if(alt_dugum->sag == NULL) alt_dugum = alt_dugum->sol;
	else if(alt_dugum->sol == NULL) alt_dugum = alt_dugum->sag;
	else{
		delAVLNode = alt_dugum->sol;
		AVLNode *parentAVLNode = alt_dugum;
		while(delAVLNode->sag != NULL){
			parentAVLNode = delAVLNode;
			delAVLNode = delAVLNode->sag;
		}
		alt_dugum->data = delAVLNode->data;
		if(parentAVLNode == alt_dugum) alt_dugum->sol = delAVLNode->sol;
		else parentAVLNode->sag = delAVLNode->sol;
	}
	delete delAVLNode;
	return true;
}

void AVL::postorder(AVLNode* alt_dugum){
	if(alt_dugum != NULL){
		postorder(alt_dugum->sol);
		postorder(alt_dugum->sag);
		
		for(int i=1;i<alt_dugum->data.count();i++){
			Noktalar tmp=alt_dugum->data.peekMin();
			ilkYazilacak=tmp.orijineUzaklik;
			cout<<ilkYazilacak<<" ";
			alt_dugum->data.dequeueMaxClose();	
			i--;
		}
	
		Node *tmp2=alt_dugum->data.returnFront();
		cout<<tmp2->data.orijineUzaklik<<endl;
		
		delete tmp2;	
	}
}

int AVL::Yukseklik(AVLNode* alt_dugum){
	if(alt_dugum == NULL) return -1;
	return 1+max(Yukseklik(alt_dugum->sol),Yukseklik(alt_dugum->sag));
}

AVL::AVL(){
	kok = NULL;
}

bool AVL::isEmpty()const{
	return kok == NULL;
}

void AVL::Add( DogruKuyrugu& yeni){
	kok = AraVeEkle(kok,yeni);
}

void AVL::postorder(){
	postorder(kok);
}

int AVL::Yukseklik(){
	return Yukseklik(kok);
}

void AVL::Clear(){
	while(!isEmpty()) DeleteAVLNode(kok);
}

AVL::~AVL(){
	Clear();
}