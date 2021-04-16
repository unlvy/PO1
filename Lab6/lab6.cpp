#include <iostream>

#include "rna.h"
#include "virus.h"
#include "animalvirus.h"

using namespace std;

template<class T> T my_copy(T a) {
	return a; }

//----------------------------------------------------
int main() {
	
	RNA rna1( vector<Nukleotyp>({A,C,A,T,A,G,A,C,T,A,G,T,C,A,T}) );
	RNA rna2( vector<Nukleotyp>({C,A,T,C,C,A,G,A,G,T,A,C,T,C,A}) );
	cout << "RNA1: " << rna1 << "RNA2: " <<rna2;
	
	cout << "MUTATED RNA2: " << rna2.mutate();
	
	
	Virus vir1("RSV");
	cout << "Wirus: " << vir1.get_name() << " " << vir1.get_RNA() << endl;
	
	vir1.set_RNA(vector<Nukleotyp>({A,C,U,A,G,G,U,A,U,G,A}));	
	cout << "RNA: " << *vir1.get_RNA() << endl;

	
	Virus vir2 = Virus(my_copy(vir1));  
	Virus vir3(vir1);  					
	Virus vir4(my_copy(vir3));  		
	cout << "Pokolenia: " << endl;	
	cout << "Vir1 - Wiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir2 - Wiek: " << vir2.get_age() << "  RNA: " << *vir2.get_RNA();
	cout << "Vir3 - Wiek: " << vir3.get_age() << "  RNA: " << *vir3.get_RNA();
	cout << "Vir4 - Wiek: " << vir4.get_age() << "  RNA: " << *vir4.get_RNA() << endl;;

	Virus vir5 = Virus(vir1);		
	cout << "Pokolenia:" << endl;	
	cout << "Vir1 - Wiek: " << vir1.get_age() << "  RNA: " << *vir1.get_RNA();
	cout << "Vir5 - Wiek: " << vir5.get_age() << "  RNA: " << *vir5.get_RNA() << endl;

	AnimalVirus avir("Koronawirus","nietoperz", rna1.get_RNA());
	cout << "Wirus: " <<avir.get_name() << endl;
	cout << "Nosiciel: " << avir.get_animal_host() << endl;
	cout << "RNA: " << *avir.get_RNA()<<endl;

	AnimalVirus avir1("Chikungunya","komar",vector<Nukleotyp>({U,C,A,A,U,C,C,U,C,A,U,C,A}));
	cout << "Wirus: " << avir1.get_name() << endl;
	cout << "Nosiciel: " << avir1.get_animal_host() << endl;
	
	AnimalVirus avir2 =  AnimalVirus() = (my_copy(avir1));   
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	AnimalVirus avir3 (avir1);							
	cout << "Wirus: " << avir2.get_name() << " Pokolenia: " << endl;
	cout << "AVir1 - Wiek: " << avir1.get_age() << "  RNA: " << *avir1.get_RNA();
	cout << "AVir2 - Wiek: " << avir2.get_age() << "  RNA: " << *avir2.get_RNA();
	cout << "AVir3 - Wiek: " << avir3.get_age() << "  RNA: " << *avir3.get_RNA();
return 0;
}
// =======================================================================

/* 
RNA1: A C A T A G A C T A G T C A T
RNA2: C A T C C A G A G T A C T C A
MUTATED RNA2: A T C C A G A G T A C T C A C
Wirus: RSV 0
RNA: A C U A G G U A U G A

Pokolenia:
Vir1 - Wiek: 2  RNA: A C U A G G U A U G A
Vir2 - Wiek: 0  RNA: C U A G G U A U G A A
Vir3 - Wiek: 1  RNA: A C U A G G U A U G A
Vir4 - Wiek: 0  RNA: C U A G G U A U G A A

Pokolenia:
Vir1 - Wiek: 3  RNA: A C U A G G U A U G A
Vir5 - Wiek: 0  RNA: A C U A G G U A U G A

Wirus: Koronawirus
Nosiciel: nietoperz
RNA: A C A T A G A C T A G T C A T

Wirus: Chikungunya
Nosiciel: komar
AVir1 - Wiek: 1  RNA: U C A A U C C U C A U C A
Wirus: Chikungunya  Pokolenia:
AVir1 - Wiek: 2  RNA: U C A A U C C U C A U C A
AVir2 - Wiek: 0  RNA: C A A U C C U C A U C A U 
AVir3 - Wiek: 0  RNA: U C A A U C C U C A U C A
*/
