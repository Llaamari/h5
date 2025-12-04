#include <iostream>
#include <string>
#include "ClassA1.h"
#include "ClassA2.h"
#include "ClassB.h"

using namespace std;

int main() {
    // Vaihdetaan Windowsin konsolin merkistö UTF-8:ksi, jotta ääkköset näkyvät oikein
    system("chcp 65001 > nul");
    // Osoitin
    int a = 5;
    cout << "a:n arvo on: " << a << " ja osoite on: " << &a << endl;

    int *pointerA = &a;
    cout << "Pointterin osoittama osoite on: " << pointerA << endl;
    cout << "Pointterin osoittaman muistipaikan arvo on: " << *pointerA << endl;

    // Referenssi
    int &refA = a;
    cout << "refA osoittaa osoitteeseen on: " << &refA << endl;
    cout << "refA:n osoittaman muistipaikan arvo on: " << refA << endl;

    // b muuttuja
    int b = 6;
    cout << "\nKokeillaan muuttaa osoittamaan b...\n";

    // refA = &b;  <-- EI MAHDOLLINEN, koska referenssiä ei voi uudelleensitouttaa!
    // refA = b;   <-- Tämä muuttaa a:n arvoa, EI osoitetta!

    pointerA = &b;
    cout << "pointerA osoittaa nyt osoitteeseen: " << pointerA << endl;
    cout << "sen muistipaikan arvo on: " << *pointerA << endl;

    cout << "\nLopputulos -> a:n arvo on nyt: " << a << " (muuttui, koska refA = b muuttaa a:ta, ei osoitetta!)\n\n";

    // ===== Olio argumenttina (kopio) =====
    ClassB objB;
    objB.setInfo("Olion B asettama info");

    ClassA1 objA1(objB);
    objA1.setBinfo("Olion objA1 asettama info");

    cout << "objB: " << objB.getInfo() << endl;
    cout << "objA1 (kopion B info): " << objA1.getBinfo() << endl;

    // ===== Referenssi argumenttina =====
    ClassB &refB = objB;
    ClassA2 objA2(refB);
    objA2.setBinfo("Olion A2 asettama info");

    cout << "\nMuutoksen jälkeen:\n";
    cout << "objB: " << objB.getInfo() << endl;
    cout << "objA2 (referenssin kautta): " << objA2.getBinfo() << endl;

    // ===== Erot havainnollistettuna =====
    cout << "\nTermien erot:\n";
    cout << "pointerA      on itse osoitin, eli muistiosoite\n";
    cout << "*pointerA     on tuon osoitteen sisältö (dereferointi)\n";
    cout << "refA          on alias muuttujaan a, eli sen arvo\n";
    cout << "&refA         on refA:n muistiosoite (sama kuin a:n osoite)\n";

    return 0;
}