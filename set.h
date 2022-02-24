#ifndef SET_H
#define SET_H

#include <ostream> //std::ostream (per ridefinirlo)
#include <cstddef>
/**
  @file set.h
  @brief Dichiarazione della classe set

  La classe implementa una generica set di oggetti T.
  la set è dinamica e cambia dimensione nel corso del programma

  Una set è definito da
  1. elementi, che a loro volta sono degli oggetti, che rappresentano il valore da memorizzare
  2. puntatore al primo elemento della set
  3. puntatore all'ultimo elemento della set
  4. dimensione corrente della set
*/

template<typename T>
class set{

private:
  /**
    @brief Dichiarazione dell'oggetto contenuto nella set

    Un oggetto element é definito da
    1. un valore di tipo T
    2. un puntatore al prossimo elemento all'interno della set
  */
  struct element{
    T value; //valore da memorizzare
    element *next; //puntatore al prossimo elemento nella set

    /**
      @brief Costruttore di default

      Costruttore di default per istanziare l'elemento vuoto.

      @post next == nullptr
    */
    element() : next(nullptr){}

    /**
      @brief Costruttore secondario 2.1

      Costruttore secondario per istanziare un elemento prendendo come parametri un valore e un puntatore ad un altro elemento.

      @param v valore da copiare
      @param e puntatore a next da copiare

      @post value == vector
      @post next == e
    */
    element(const T &v, element *e) : value(v), next(e) {}

    /**
      @brief Costruttore secondario 2.2

      Costruttore secondario per istanziare un elemento prendendo come parametro un valore.

      @param v valore da colpiare

      @post value == v
      @post next == nullptr
    */
    explicit element(const T &v) : value(v), next(nullptr) {}

    /**
      @brief Costruttore secondario 2.3

      Costruttore secondario per istanziare un elemento prendendo come parametro un puntatore ad un altro elemento.

      @param e puntatore da copiare

      @post next == e
    */
    explicit element(const element *e) : next(e) {}

    /**
      @brief Copy constructor

      Copiamo i dati membro a membro.
      essendo questa una struttura interna di supporto alla set, va bene la condivisione dei dati.

      @param other nodo da copiare

      @post value = other.value
      @post next = other.next
    */
    element(const element &other) : value(other.value), next(other.next) {}

    /**
      @brief Operatore di assegnamento

      Crea un elemento uguale a quello passato come paramentro

      @param other elemento da copiare

      @post value = other.value
      @post next = other.next
    */
    const element& operator=(const element &other){
      value = other.value;
      next = other.next;
      return *this;
    }

    /**
      @brief Distruttore
    */
    ~element() {}
  };

  element *m_head; ///< puntatore al primo elemento della set
  element *m_tail; ///< puntatore all'ultimo elemento della set
  unsigned int m_size; ///< numero di elementi presenti nella lista

public:

  /**
  @brief Costruttore di default

  @post m_head == nullptr
  @post m_tail == nullptr
  @post m_size == 0
  */
  set() : m_head(nullptr), m_tail(nullptr), m_size(0) {}

  /**
  @brief Copy construtor

  Istanzia una set uguale a quella passata come parametro

  @param other la set dalla quale prendere gli elementi

  @post m_head == other.m_head
  @post m_tail == other.m_tail
  @post m_size == other.m_size
  */
  set(const set &other) : m_head(nullptr), m_tail(nullptr), m_size(0){

    element *curr = other.m_head;

    try{
      while(curr != nullptr){
        add(curr->value);
        curr = curr->next;
      }
    }
    catch(...){
      clear();
      throw;
    }
  }

  /**
  @brief Operatore di assegnamento

  @param other la set dalla quale prendere gli elementi

  @post m_head == other.m_head
  @post m_tail == other.m_tail
  @post m_size == other.m_size

  @return reference alla set this
  */
  set& operator=(const set &other){
    if(this != &other){
      set tmp(other);
      std::swap(this->m_head, tmp.m_head);
      std::swap(this->m_tail, tmp.m_tail);
      std::swap(this->m_size, tmp.m_size);
    }
    return *this;
  }

  /**
    @brief Distruttore

    @post m_head == nullptr
    @post m_tail == nullptr
    @post m_size == 0
  */
  ~set(){
    clear();
  }

  /**
    @brief Svuota la set

    @post m_head == nullptr
    @post m_tail == nullptr
    @post m_size == 0
  */
  void clear(){
    element *curr = m_head;

    while(curr != nullptr){
      element *mnext = curr->next;
      delete curr;
      curr = mnext;
    }
    m_size = 0;
    m_tail = nullptr;
    m_head = nullptr;
  }

  /**
    @brief add

    Aggiunge un elemento in testa alla set
    (ricordiamo che una set è uguale se contiene gli stessi elementi, non dipende dalla posizione)

    @param value valore da inserire all'interno della set

    @post m_size++
  */
  void add(const T &value){
    //caso di Set vuoto
    if(m_size == 0){
      element *tmp = new element(value);
      m_head = tmp;
      m_tail = tmp;
      m_size++;
      return;
    }
    else{
      element *curr = m_head;

      //controllo che l'elemento non sia già inserito
      while(curr != nullptr){
        if(curr->value == value)
          return;
        curr = curr->next;
      }

      curr = m_head;

      if(curr == m_head) {
        element *tmp = new element(value);
        m_head = tmp;
        tmp->next = curr;
        m_size++;
      }
    }
  }

  /**
    @brief remove

    Rimuove dalla set l'elemento passato come parametro

    @param value valore da togliere dalla set

    @post m_size--
  */
  void remove(const T &value){
    element *temp = m_head;
    element *prev = nullptr;

    if(temp != nullptr && temp->value == value){
      m_head = temp->next;
      delete temp;
      m_size--;
      return;
    }else{
      while (temp != nullptr && temp->value != value){
         prev = temp;
         temp = temp->next;
     }
     if (temp == nullptr)
         return;

     prev->next = temp->next;
     delete temp;
     m_size--;
    }
  }

  /**
    @brief size

    ritorna la dimensione corrente della set

    @return m_size
  */
  const unsigned int size() const {
    return m_size;
  }

  /**
    @brief print
    Stampa tutto il set

  */
   void print() const{
    element *curr = m_head;

    while(curr != nullptr){
      std::cout << curr->value << " ";
      curr = curr->next;
    }
    std::cout << std::endl;
  }

  /**
    @brief Costruttore tramite coppia di iteratori

    Crea una set riempita con dati presi da una sequenza trovata da iteratori di inizio e uno di fine. Gli iteratori sono templati

    @param b iteratore di begin
    @param e iteratore di end
  */
  template<typename Iteratore>
  set(Iteratore b, Iteratore e) : m_head(nullptr), m_tail(nullptr), m_size(0){
    try {
      for( ; b != e; ++b)
        add(static_cast<T>(*b));
    }
    catch(...) {
      // in caso di errore di memoria si svuota il set
      clear();
      throw;
    }
  }

  /**
    @brief Ridefinizione operator<<

    Permette la stampa di una set semplicemente facendo:
    std::cout << set_da_stampare << std::endl;

    @param os stream di output
    @param s set da spedire sullo stream

    @return lo stream di output
  */
  friend std::ostream &operator<<(std::ostream &os, const set &s) {
    element *curr = s.m_head;
    while(curr != nullptr){
      os << curr->value << " ";
      curr = curr ->next;
    }
    return os;
  }

  /**
    @brief Ridefinizione operator==

    ritorna 1 se il confronto tra 2 set risulta true
    0 altrimenti

    @param s2 set da confrontare

    @return "1" se due set uguali
    @return "0" se due set diversi
  */
  bool operator==(const set<T> &s2) const {
    if(m_size != s2.m_size)
      return false;

    element *first = this->m_head;
    element *second = s2.m_head;
    bool trovato = false;

    while(first != nullptr){
      for(; second != nullptr && trovato!=true; second = second->next){
        if(second->value == first->value){
          trovato=true;
        }
      }
      if(first->next == nullptr)
        return trovato;
      trovato = false;
      first = first->next;
      second = s2.m_head;
    }
    return true;
  }

  /**
    @brief Ridefinizione operator[]

    Permette la stampa dell'i-esimo elemento nella set

    @param indice indica la posizione dell'elemento da stampare
  */
  void operator[](const unsigned int &indice) const{
    unsigned int counter = 0;
    element *curr = m_head;

    if(indice == 0){
      std::cout << "elemento " << (indice+1) <<"-esimo: " << curr->value << std::endl;
    }
    else if(indice < size()){
      for(; counter < indice && curr != nullptr; counter++){
        curr = curr->next;
      }

      std::cout << "elemento " << (indice+1) <<"-esimo: " << curr->value << std::endl;
    }
    else
      std::cout << "ERROR - l'elemento richiesto supera la size" << std::endl;
  }

  /**
    @brief Istanziazione classe const_iterator

    Gli iteratori devono iterare sui dati inseriti nella set. L'iteratore itera sui dati di tipo T
  */
  class const_iterator {

  public:
    typedef std::forward_iterator_tag iterator_category;
    typedef T                         value_type;
    typedef ptrdiff_t                 difference_type;
    typedef const T*                  pointer;
    typedef const T&                  reference;

    const_iterator() : ptr(nullptr) {
    }

    const_iterator(const const_iterator &other) : ptr(other.ptr) {
    }

    const_iterator& operator=(const const_iterator &other) {
      ptr = other.ptr;
      return *this;
    }

    ~const_iterator() { }

    reference operator*() const {
      return ptr->value;
    }

    pointer operator->() const {
      return &(ptr->value);
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      ptr = ptr->next;
      return tmp;
    }

    const_iterator& operator++() {
      ptr = ptr->next;
      return *this;
    }

    bool operator==(const const_iterator &other) const {
      return (ptr == other.ptr);
    }

    bool operator!=(const const_iterator &other) const {
      return !(other == *this);
    }

  private:
    friend class set;

    const_iterator(const element *p) : ptr(p) { }

    const element *ptr;

  }; // fine classe const_iterator

  /**
  @brief Punta al primo elemento
  */
  const_iterator begin() const {
    return const_iterator(m_head);
  }

  /**
  @brief Punta all'ultimo elemento
  */
  const_iterator end() const {
    return const_iterator(nullptr);
  }

}; // fine classe set

//qua i metodi globali

/**
  @brief Funzione GLOBALE filter_out

  Ritorna una nuova set che contiene gli elementi della set passata come parametro che soddisfano il filtro applicato tramite il predicato P

  @param s set da filtrare
  @param pred predicato da soddisfare
  @param filtro valore che fa da filtro

  @return s_filtered una nuova set che contiene elementi filtrati
*/
template<typename T, typename P>
set<T> filter_out(const set<T> &s,const P pred, const T& filtro){
  typename set<T>::const_iterator b, e;
  set<T> s_filtered;

  for(b = s.begin(), e = s.end(); b != e; ++b){
    if(pred(*b, filtro))
      s_filtered.add(static_cast<T>(*b));
  }

  return s_filtered;
}

/**
  @brief Funzione GLOBALE operator+

  Ritorna una nuova set che contiene gli elementi delle due set passate come paramentro. In pratica fa una concatenazione delle due set

  @param s1 prima set
  @param s2 seconda set

  @return result una nuova set che contiene gli elementi di entrambe le set
*/
template<typename T>
set<T> operator+(const set<T>& s1, const set<T>& s2){
  typename set<T>::const_iterator b, e;
  set<T> result;

  for(b = s1.begin(), e = s1.end(); b != e; ++b)
    result.add(static_cast<T>(*b));

  for(b = s2.begin(), e = s2.end(); b != e; ++b)
    result.add(static_cast<T>(*b));

  return result;
}

/**
  @brief Funzione GLOBALE operator-

  Ritorna una nuova set che costituita dagli elementi che sono in comune ad entrambe le set. In pratica fa una intersezione tra le due set

  @param s1 prima set
  @param s2 seconda set

  @return result una nuova set che contiene gli elementi comune ad entrambe le set
*/
template<typename T>
set<T> operator-(const set<T>& s1, const set<T>& s2){
  typename set<T>::const_iterator b1, b2, e1, e2;
  set<T> result;

  for(b1 = s1.begin(), e1 = s1.end(); b1 != e1; ++b1){
    for(b2 = s2.begin(), e2 = s2.end(); b2 != e2; ++b2){
      if(*b1 == *b2)
        result.add(static_cast<T>(*b2));
    }
  }

  return result;
}


//i predicati
/**
  @brief Funtore di uguaglianza tra 2 elementi

  Ritorna true se due elementi sono uguali
*/
struct equalTo{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a==b;
  }
};

/**
  @brief Funtore di NON uguaglianza tra 2 elementi

  Ritorna true se due elementi sono diversi
*/
struct notEqualTo{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a != b;
  }
};

/**
  @brief Funtore di confronto tra 2 elementi

  Ritorna true se il primo elemento è minore del secondo
*/
struct lessThan{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a < b;
  }
};

/**
  @brief Funtore di confronto tra 2 elementi

  Ritorna true se il primo elemento è maggiore del secondo
*/
struct greaterThan{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a > b;
  }
};

/**
  @brief Funtore di confronto tra 2 elementi

  Ritorna true se il primo elemento è minore o uguale del secondo
*/
struct lessThanOrEqualTo{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a <= b;
  }
};

/**
  @brief Funtore di confronto tra 2 elementi

  Ritorna true se il primo elemento è maggiore o uguale del secondo
*/
struct greaterThanOrEqualTo{
  template<typename T>
  bool operator()(const T& a, const T& b) const{
    return a >= b;
  }
};

#endif
