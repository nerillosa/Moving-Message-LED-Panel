#include "lcdmatrix.h"
#include <stdint.h>
#include <string.h>

uint8_t _A[8][6] = {{0,0,1,0,0,0},{0,1,0,1,0,0},{1,0,0,0,1,0},{1,1,1,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _B[8][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _C[8][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,1,0},{0,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _D[8][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _E[8][6] = {{1,1,1,1,1,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,1,0},{0,0,0,0,0,0}};
uint8_t _F[8][6] = {{1,1,1,1,1,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{0,0,0,0,0,0}};
uint8_t _G[8][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,0,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,1,0},{0,0,0,0,0,0}};
uint8_t _H[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _I[8][6] = {{0,1,1,1,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _J[8][6] = {{0,0,1,1,1,0},{0,0,0,1,0,0},{0,0,0,1,0,0},{0,0,0,1,0,0},{0,0,0,1,0,0},{1,0,0,1,0,0},{0,1,1,0,0,0},{0,0,0,0,0,0}};
uint8_t _K[8][6] = {{1,0,0,0,1,0},{1,0,0,1,0,0},{1,0,1,0,0,0},{1,1,0,0,0,0},{1,0,1,0,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _L[8][6] = {{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,1,0},{0,0,0,0,0,0}};
uint8_t _M[8][6] = {{1,0,0,0,1,0},{1,1,0,1,1,0},{1,0,1,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _N[8][6] = {{1,0,0,0,1,0},{1,1,0,0,1,0},{1,0,1,0,1,0},{1,0,0,1,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _O[8][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _P[8][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{1,0,0,0,0,0},{0,0,0,0,0,0}};
uint8_t _Q[8][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,1,0,1,0},{1,0,0,1,0,0},{0,1,1,0,1,0},{0,0,0,0,0,0}};
uint8_t _R[8][6] = {{1,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,1,1,1,0,0},{1,0,1,0,0,0},{1,0,0,1,0,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _S[8][6] = {{0,1,1,1,0,0},{1,0,0,0,1,0},{1,0,0,0,0,0},{0,1,1,1,0,0},{0,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _T[8][6] = {{1,1,1,1,1,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0}};
uint8_t _U[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,1,1,0,0},{0,0,0,0,0,0}};
uint8_t _V[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0}};
uint8_t _W[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,1,0,1,0},{1,0,1,0,1,0},{0,1,0,1,0,0},{0,0,0,0,0,0}};
uint8_t _X[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0},{0,1,0,1,0,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,0,0,0,0,0}};
uint8_t _Y[8][6] = {{1,0,0,0,1,0},{1,0,0,0,1,0},{1,0,0,0,1,0},{0,1,0,1,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0}};
uint8_t _Z[8][6] = {{1,1,1,1,1,0},{0,0,0,0,1,0},{0,0,0,1,0,0},{0,0,1,0,0,0},{0,1,0,0,0,0},{1,0,0,0,0,0},{1,1,1,1,1,0},{0,0,0,0,0,0}};
uint8_t __[8][6] = {{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0}};
uint8_t excl[8][6] = {{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0},{0,0,1,0,0,0},{0,0,0,0,0,0}};


void* bitPacks[28] = {_A,_B,_C,_D,_E,_F,_G,_H,_I,_J,_K,_L,_M,_N,_O,_P,_Q,_R,_S,_T,_U,_V,_W,_X,_Y,_Z,__,excl};
char characters[28] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','!'};

static void* getCharbits(char element){
   int i;
   for(i=0;i<28;i++){
      if(element == characters[i] )
	return bitPacks[i];
   }
   return __;
}

void setBitR( int *A,  int k ){
        *A |= (1 << k);  // Set the bit at the k-th position in A
}

int getBitR( int A,  int k ){
        return ( (A & (1 << k )) != 0 ) ;//get the bit in the k-th position in A
}

void setBitL(int *buffer, int offset){ //set the bit in the k-th position from the left in buffer
        int num = offset/32;
        buffer[num] |= (0x80000000 >> (offset - num * 32));
}

int getBitL( int A, int k ){ //get the bit in the k-th position from the left in A
        return ( (A & (0x80000000 >> k )) != 0 ) ;
}

void getRows(int *buff, int buffsize, char *str){

        size_t str_length = strnlen(str, MAX_TEXT_LENGTH);

	void* text[str_length];

        int z;
        for(z=0;z<str_length;z++){
		text[z] = __; // blank line
	}

 	int k,j,m;

        for(z=0; z< str_length; z++){
           text[z] = getCharbits(str[z]); //Load the input string str
        }

        for(z=0; z< buffsize; z++){ // for each row (8)
                for(j=0,k=NUMBER_COLUMNS_PER_PANEL-1;j<str_length;j++){ // for each letter (5)
                        uint8_t (*arr)[LETTER_WIDTH] = (uint8_t (*)[LETTER_WIDTH]) text[j];
                        for(m=0;m<LETTER_WIDTH;m++,k--){  // start at 31 and decrease.6 for each letter 
                                if(arr[z][m]){
                                        setBitR(&buff[z], k);
                                }
                        }
                }
        }
}


void fillPanel(int* intBuffer, int* messageString, int messageStringOffset, int row_length_in_bits){
  int i,j,k,count;
  for(i=0,count=0;i<NUMBER_ROWS;i++){
    for(j=0,k=0;j<row_length_in_bits;j++,count++){
      if((messageStringOffset==0 || j/messageStringOffset > 0) && k < 32 ){
        int val = getBitL(messageString[count/32], count%32);
        if(val){
	    intBuffer[i] |= (0x80000000 >> k);
	}
        k++;
      }
    }
  }
}

void padAndfillPanel(int* intBuffer, int* messageString, int padding, int row_length){
  int i,j,count;
  for(i=0,count=0;i<NUMBER_ROWS;i++){
    for(j=0;j<row_length;j++,count++){
      if(j>=padding && j<32) {
        int val = getBitL(messageString[(count-padding)/32], (count-padding)%32);
        if(val) {
          intBuffer[i] |= (0x80000000 >> j);
        }
      }
    }
  }
}

void fillStringIntBuffer(int *intBuffer, char* str){
        size_t str_length = strnlen(str, MAX_TEXT_LENGTH);
        void* text[str_length];
        int z,k,j,m;

        for(z=0; z< str_length; z++){
           text[z] = getCharbits(str[z]); //Load the input string str
        }
        int count = 0;
        for(z=0; z< NUMBER_ROWS-1; z++){ // for each row (8)
                for(j=0;j<str_length;j++){ // for each letter
                        uint8_t (*arr)[LETTER_WIDTH] = (uint8_t (*)[LETTER_WIDTH]) text[j];
                        for(m=0;m<LETTER_WIDTH;m++){
                                // if(count && count%6 == 0) printf(" ");
                                if(arr[z][m]){
                                        setBitL(intBuffer, count);
                                        // printf(ANSI_COLOR_GREEN   "1");
                                }else{
                                        // printf(" ");
                                }
                                count++;
                        }
                }
                // printf(ANSI_COLOR_RESET  "\n");
        }
}

void shiftLeft(int rowBits[NUMBER_ROWS]){
        int i;
        for(i=0;i<NUMBER_ROWS;i++){

                rowBits[i] =  rowBits[i] << 1 ;
        }
}

void copyIntArrays(int *dest, int *src, int size){
    int w;
    for(w=0 ; w<size ; w++){
        dest[w] = src[w];
    }
}

