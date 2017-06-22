
#include "CDCI.h"

// Constructor
CDCI::CDCI(){
  
}


void CDCI::Test(){
  unsigned long N = N_get_M(0x00000400, 0x00000015, 2, 6);
  
  
}


// Chapter 5.1
unsigned long CDCI::N_get_M(unsigned long N, unsigned long M, unsigned char start, unsigned char end){
  bool state;
  int m = 0;
  
  // Set bits in N between start-end
  for(int i = start; i <= end; i++, m++){
    state = (M & (1 << m)) ? 1 : 0;
    N = N | (state << i);
  }
    
  return N;
}