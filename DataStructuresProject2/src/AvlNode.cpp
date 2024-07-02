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

#include "AvlNode.hpp"

AVLNode::AVLNode(const DogruKuyrugu& vr,AVLNode* sl=NULL,AVLNode* sg=NULL){
		data = vr;
		sol = sl;
		sag = sg;
		yukseklik=0;
}