
#include "stack.h"

void stack::ensure_capacity( size_t c ){


  if (c <= current_capacity){

    return;
  }


  size_t bytes = 1;
  while(bytes < c){
    
    bytes *= 2;
  
  }

  
  double* newData(new double[bytes]);
  std::copy(data, data+(current_capacity), newData);
  
  current_capacity = bytes;
  delete[] data;
  data = newData;
  bytes = 1;

}
   // Keep current_capacity always in powers of two.

stack::stack( ) : //Default constructor
 current_size(0),
 current_capacity(4),
 data(new double[current_capacity])
{

}

stack::stack( const stack& s ) :  //Copy constructor
  data(new double [s.current_capacity]),
  current_size(s.current_size),
  current_capacity(s.current_capacity)
  {
    std::copy(s.data, s.data + (current_size), data);
  }


const stack& stack::operator = ( const stack& s ){ //Assignment operator
  
  ensure_capacity(current_size);
  current_size = s.current_size;
  
  std::copy(s.data, s.data+(current_size), data);
  return *this; 
}


stack::~stack( ){  

  delete[] data;
}

void stack::push( double d ){
  ensure_capacity(current_size + 1);

  data[current_size] = d;
  ++current_size;
}
  
stack::stack( std::initializer_list< double > init ) :
  current_size(0),
  current_capacity(init.size()), 
  data(new double[current_capacity]){

  for (double val : init){

    push(val);

  }

}
  
void stack::pop( ){
  if(current_size == 0){
    throw std::runtime_error("pop: stack is empty");
  }
  current_size--;
}

void stack::clear( ){
  current_size = 0;
}

void stack::reset( size_t s ){
  current_size = s;
}

double stack::peek( ) const{

  if(current_size == 0){
    throw std::runtime_error("pop: stack is empty");
  }
  return data[current_size - 1];

}

size_t stack::size( ) const{
  return current_size;
}

bool stack::empty( ) const{
  if (current_size == 0){
    return true;
  }
  return false;
}

void stack::print( std::ostream& out ) const {

  for(int i = 0;  i < (current_size); i++){
    if(i == current_size - 1){
      out << data[i] <<"\n";
    } else{
    out << data[i] <<", ";
    }
  }
  out<<"\n";

}



