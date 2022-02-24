/**
@file main.cpp
@brief test d'uso della classe set<int>
*/

#include <iostream>
#include "set.h"
#include <cassert>

//typedef della classe set per interi
typedef set<int> setint;
/**
  @brief Test dei 4 metodi fondamentali
*/
void test_fondamenti_set_int(){

  std::cout << "********* TEST DEI 4 METODI FONDAMENTALI *********\n" << std::endl;

  std::cout << "* Test constructor default *" << std::endl;
  set<int> def;
  assert(def.size() == 0); //verifichiamo che la size sia 0

  std::cout << "* Test copy constructor *" << std::endl;
  set<int> s1;
  s1.add(10);
  s1.add(5);
  s1.add(7);
  s1.add(13);
  s1.add(20);
  set<int> s2(s1);
  std::cout << "s1: " << s1 << std::endl;
  std::cout << "s2: " << s2 << std::endl;
  set<int> s20;
  set<int> s40(s20);
  std::cout << "s40 se s20 e' vuoto: " << s40 << std::endl;

  std::cout << "*Test operator assegnamento = *" << std::endl;
  set<int> s3;
  s3 = s1;
  std::cout << "s3: " << s3 << std::endl;
}
/**
  @brief Test d'uso su sest<int>
*/
void test_set_int(){
  std::cout << "\n********* TEST METODI set<int> *********\n" << std::endl;

  std::cout << "* Test add *" << std::endl;
  set<int> s1;
  std::cout << "s1 prima dell'add: " << s1 << std::endl;
  s1.add(10);
  s1.add(5);
  s1.add(10); //questo non verrà inserito in quanto elemento già presente
  s1.add(7);
  s1.add(13);
  s1.add(20);
  std::cout << "s1 dopo l'add: " << s1 << std::endl;

  std::cout << "\n* Test remove *" << std::endl;
  std::cout << "s1 prima della remove: " << s1 << std::endl;
  std::cout << "size: " << s1.size() << std::endl;
  s1.remove(7);
  std::cout << "s1 dopo la remove dell'elemento 7: " << s1 << std::endl;
  std::cout << "size: " << s1.size() << std::endl;
  s1.remove(20);
  std::cout << "s1 dopo la remove dell'elemento 20: " << s1 << std::endl;
  std::cout << "size: " << s1.size() << std::endl;

  std::cout << "\n* Test size *" << std::endl;
  std::cout << "size s1: " << s1.size() << std::endl;

  std::cout << "\n* Test metodo print() *" << std::endl;
  std::cout << "s1: ";
  s1.print();

  set<int> s2;
  s2.add(1);
  s2.add(2);
  s2.add(3);
  s2.add(4);
  s2.add(5);
  std::cout << "\n* Test costruttore tramite Iterator *" << std::endl;
  set<int> s3(s2.begin(), s2.end());
  std::cout << "s3: " << s3 << std::endl;
  int dati[6] = {1, 2, 3, 4, 5, 6};
  set<int> s4(dati, dati+6);
  std::cout << "s4: " << s4 << std::endl;

  std::cout << "\n* Test operator<< *" << std::endl;
  std::cout << "s2: " << s2 << std::endl;

  bool uguali = s3==s2;
  std::cout << "\n* Test operator== *" << std::endl;
  if(uguali == 1)
    std::cout << "true" << std::endl;
  else if(uguali == 0)
    std::cout << "false" << std::endl;

  uguali = s3==s4;
  std::cout << "\n* Test operator== *" << std::endl;
  if(uguali == 1)
    std::cout << "true" << std::endl;
  else if(uguali == 0)
    std::cout << "false" << std::endl;

  std::cout << "\n* Test operator[] *" << std::endl;
  std::cout << "i-esimo elemento di s3\n";
  s3[0];
  s3[4];
  std::cout << "richiesta elemento che supera la size: ";
  s3[5];
}

/**
  @brief Test dei metodi globali su set<int>
*/
void test_set_int_filter(){
    std::cout << "\n********* TEST METODI GLOBALI set<int> *********" << std::endl;

  equalTo eT;
  notEqualTo diverso;
  lessThan lT;
  greaterThan gT;
  lessThanOrEqualTo minoreUguale;
  greaterThanOrEqualTo maggioreUguale;

  set<int> s1;
  s1.add(1);
  s1.add(10);
  s1.add(20);
  s1.add(50);
  s1.add(100);

  std::cout << "\n* Test filter_out equalTo *" << std::endl;
  set<int> s2 = filter_out(s1, eT, 3);
  if(s2.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s2 filtrato e': " << s2 << std::endl;

  std::cout << "\n* Test filter_out notEqualTo *" << std::endl;
  set<int> s3 = filter_out(s1, diverso, 3);
  if(s3.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s3 filtrato e': " << s3 << std::endl;

  std::cout << "\n* Test filter_out lessThan *" << std::endl;
  s3 = filter_out(s1, lT, 50);
  if(s3.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s3 filtrato e': " << s3 << std::endl;

  std::cout << "\n* Test filter_out greaterThan *" << std::endl;
  s3 = filter_out(s1, gT, 50);
  if(s3.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s3 filtrato e': " << s3 << std::endl;

  std::cout << "\n* Test filter_out lessThanOrEqualTo *" << std::endl;
  s3 = filter_out(s1, minoreUguale, 50);
  if(s3.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s3 filtrato e': " << s3 << std::endl;

  std::cout << "\n* Test filter_out greaterThanOrEqualTo *" << std::endl;
  s3 = filter_out(s1, maggioreUguale, 50);
  if(s3.size() == 0)
    std::cout <<"nessun criterio corrisponde alla richiesta effettuata "<< std::endl;
  else
    std::cout << "s3 filtrato e': " << s3 << std::endl;
}

/**
  @brief Test degli operator+ e operator-
*/
void test_set_int_operatori(){
  std::cout << "\n* Test ridefinizione degli operatori + e - *\n" << std::endl;
  set<int> s1;
  s1.add(1);
  s1.add(2);
  s1.add(3);
  s1.add(4);

  set<int> s2;
  s2.add(3);
  s2.add(4);
  s2.add(10);
  s2.add(20);

  std::cout << "* Test operator+ *" << std::endl;
  set<int> concatenato = s1+s2;
  std::cout << "la concatenazione e': " << concatenato << std::endl;

  std::cout << "\n* Test operator- *" << std::endl;
  set<int> disgiunto = s1-s2;
  std::cout << "la disgiunzione e': " << disgiunto << std::endl;
}

//---------------------------------------------------------------//
/**
  @brief Funtore comparazione stringhe
*/
struct compare_string{
  bool operator()(const std::string &a, const std::string &b)const{
    return a.size() < b.size();
  }
};

/**
  @brief Funtore uguaglianza stringhe
*/
struct equal_string{
  bool operator()(const std::string &a, const std::string &b) const{
    return a==b;
  }
};
/**
  @brief Test della set istanziata su stringhe
*/
void test_set_string(){
  std::cout << "******** TEST SU SET DI STRINGHE ********"<<std::endl;

  set<std::string> s1;
  s1.add("pippo");
  s1.add("pluto");
  s1.add("cip");
  std::cout<<"s1: "<< s1 <<std::endl;
  std::cout<<"size: "<< s1.size() <<std::endl;

  set<std::string> s2(s1);
  s2.add("clara");
  s2.add("daim");
  std::cout<<"s2: "<< s2 <<std::endl;
  std::cout<<"size: "<< s2.size() <<std::endl;

  set<std::string> s3 = s1 + s2;
  std::cout<<"s3: "<< s3 <<std::endl;
  std::cout<<"size: "<< s3.size() <<std::endl;

  set<std::string> s4 = s1 - s2;
  std::cout<<"s4: "<< s4 <<std::endl;
  std::cout<<"size: "<< s4.size() <<std::endl;
}

//---------------------------------------------------------------//
/**
  @brief Struct point 2D
*/
struct point{
  int x;
  int y;

  point(int xx, int yy) : x(xx), y(yy) {}

};

/**
  @brief Ridefinizione dell'operatore di stream << per un point.
*/
std::ostream &operator<<(std::ostream &os, const point &p) {
  std::cout<<"("<<p.x<<","<<p.y<<")";
  return os;
}

/**
@brief Funtore per il confronto di due punti.
*/
struct compare_point {
  bool operator()(const point &p1, const point &p2) const {
    return (p1.x<p2.x);
  }
};

/**
  @brief Funtore per il confronto di due punti.

  PURTROPPO NON MI FUNZIONA LA ADD CON OGGETTI PERSONALI
*/
struct equal_point {
  bool operator()(const point &p1, const point &p2) const {
    return (p1.x==p2.x) && (p1.y==p2.y);
  }
};

/**
  @brief Test della set istanziata su un oggetto
*/
void test_set_point(){
  std::cout << "******** TEST SU SET DI STRINGHE ********"<<std::endl;

  set<point> p1;
  //p1.add(point(1, 2));
  //p1.add(point(2, 2));
  //p1.add(point(2, 3));
  std::cout << "p1: " << p1 << std::endl;

}

int main(){

  test_fondamenti_set_int();
  test_set_int();
  test_set_int_filter();
  test_set_int_operatori();
  test_set_string();
  test_set_point();

  return 0;
}
