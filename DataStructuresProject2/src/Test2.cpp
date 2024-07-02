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
#include "Avl.hpp"
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

int main(){
	string girilenVeri;
	Noktalar *nokta1;
	int x,y,z;
	AVL *avl=new AVL();
	
	ifstream dosyaOku(".\\doc\\veri.txt",ios::in);	
	 //dosya acilamadiysa "dosya acilamadi" cumlesini ekrana yazdirttim ki sorun oldugu anlasilsin
	if(!dosyaOku.is_open()){
		cout<<"File failed to open"<<endl;
		return 0;
	}
	
	while(getline(dosyaOku,girilenVeri)){
		DogruKuyrugu *kuyruk=new DogruKuyrugu();
		 int lenght=girilenVeri.size();
			
		string bosluk=" ";
		string MaxGecici;
		size_t found;
		size_t found2;
		size_t found3;
		size_t found4;
		found=girilenVeri.find(bosluk);
	
		for(int j=0;j<lenght;j++){
			
			MaxGecici=girilenVeri.substr(j,found);
			x=stoi(MaxGecici);
			found2=girilenVeri.find(bosluk,found+1);
			MaxGecici=girilenVeri.substr(found+1,found2);
			y=stoi(MaxGecici);
			found3=girilenVeri.find(bosluk,found2+1);
			MaxGecici=girilenVeri.substr(found2+1,found3);
			z=stoi(MaxGecici);
			nokta1=new Noktalar(x,y,z);
			found4=girilenVeri.find(bosluk,found3+1);
			found=found4;
			j=found3;
			kuyruk->enqueue(*nokta1);
			
		}	
		avl->Add(*kuyruk);
	}
	
	avl->postorder();
	delete nokta1;
	delete avl;
		
	return 0;
}