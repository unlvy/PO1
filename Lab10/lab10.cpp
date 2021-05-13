#include "Person.h"
#include "Persons.h"
#include "VectorQ.h"

int main() {
  VectorQ poczekalnia;
  poczekalnia.add (std::make_unique<Woman> ("Aga") );
  poczekalnia.add (std::make_unique<Man> ("Rysiek"));
  poczekalnia.add (std::make_unique<Woman> ("Ewa"));
  poczekalnia.add (std::make_unique<Woman> ("Anna"));
  poczekalnia.add (std::make_unique<Man> ("Tomasz"));
  poczekalnia.add (std::make_unique<Woman> ("Ewa"));

  poczekalnia.print("*** W poczekalni jest: ***");

  std::cout << "*** Malujemy wszystkie kobiety ***\n";
  std::vector<Woman*> women = poczekalnia.getWomen();
  for (const auto &ptr: women){
    ptr->makeup();      // malujemy wszystkie panie
  	std::cout << ptr->name() << " zostala umalowana" << std::endl;
  }
  // strzyzenie = false - nie potrzebuje, golenie = true - potrzebuje
  poczekalnia.add (std::make_unique<Man> ("Tomasz", true, false)); // potrzebuje strzyzenia, nie potrzebuje golenia
  poczekalnia.add (std::make_unique<Man> ("Piotr", false, true)); // nie potrzebuje strzyzenia, potrzebuje golenia
  poczekalnia.add (std::make_unique<Woman> ("Aga", false, true));  //nie potrzebuje strzyzenia, potrzebuje makijażu
  std::cout << "\n*** Zliczamy alfabetycznie imiona ***\n";
  poczekalnia.countNames();
  std::cout << "\n*** Malowanie i golenie ***\n";
  poczekalnia.haircut("Aga"); // obcinamy Agę, juz jest umalowana, więc opuszcza poczekalnię
  poczekalnia.haircut("Anna"); // jw, ma chody, weszła wcześniej
  poczekalnia.haircut("Ewa"); // jw opuszcza poczekalnię
  poczekalnia.shave("Piotr"); // golimy Piotra i opuszcza kolejkę
  poczekalnia.shave("Rysiek"); // błąd
  poczekalnia.haircut("Rysiek"); // obcinamy Ryśka, idzie na piwo
  poczekalnia.print("\n*** W poczekalni: ***");
  poczekalnia.shave(); // golimy pierwszego z kolejki Tomasza, został mu fryzjer, zostaje strzyżenie
  poczekalnia.haircut(); // obcinamy pierwszego w kolejce Tomasz
  poczekalnia.haircut(); // obcinamy pierwsza w kolejce Ew
  poczekalnia.print("\n*** A teraz w poczekalni jest: ***");
  std::cout << "*** Zaklad zamkniety, pora sie zbierac. ***\n";
}


/* output
*** W poczekalni jest: ***
Aga nieobcieta i nieumalowana
Rysiek nieobciety i nieogolony
Ewa nieobcieta i nieumalowana
Anna nieobcieta i nieumalowana
Tomasz nieobciety i nieogolony
Ewa nieobcieta i nieumalowana

*** Malujemy wszystkie kobiety ***
Aga zostala umalowana
Ewa zostala umalowana
Anna zostala umalowana
Ewa zostala umalowana

*** Zliczamy alfabetycznie imiona ***
Aga : 2
Anna : 1
Ewa : 2
Piotr : 1
Rysiek : 1
Tomasz : 2

*** Malowanie i golenie ***
Aga obcieta i umalowana idzie na zakupy
Anna obcieta i umalowana idzie na zakupy
Ewa obcieta i umalowana idzie na zakupy
Piotr obciety i ogolony idzie na piwko
Rysiek obciety i ogolony idzie na piwko

*** W poczekalni: ***
Tomasz nieobciety i nieogolony
Ewa nieobcieta i umalowana
Tomasz nieobciety i ogolony
Aga obcieta i nieumalowana

Tomasz obciety i ogolony idzie na piwko
Ewa obcieta i umalowana idzie na zakupy

*** A teraz w poczekalni jest: ***
Tomasz nieobciety i ogolony
Aga obcieta i nieumalowana

*** Zaklad zamkniety, pora sie zbierac. ***
Tomasz nieobciety i ogolony idzie na piwko
Aga obcieta i nieumalowana idzie na zakupy

*/
