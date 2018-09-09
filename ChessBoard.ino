
/************************************************************
*****                  ChessBoard                        ****
*************************************************************/
/* Version 1 Fecha  08 Septiembre 2018
Se agrega configuracion basica para prueba concepto
esta configuracion se basa en la utilizacion de un teclado matrcial 4x4
a partir del puerto 5 ya que mas adelante se utilizara una matiz de 8x8
donde ira ubicada la cuadricula del tablero

*/
#include <Keypad.h>
 
const byte rowsCount = 4;
const byte columsCount = 4;

const byte rowPins[rowsCount] = {12,11,10,9};
const byte columnPins[columsCount] = {8,7,6,5};
char keys[8][8]={
                  {7,15,23},
                  {6,14,22},
                  {5,13,21},
                  {4,12,20},
                  {3,11,19},
                  {2,10,18},
                  {1,9,17},
                  {0,8,16}
};
/*char keys[8][8]={ {0,1,2,3,4,5,6,7},
                  {8,9,10,11,12,13,14,15},
                  {16,17,18,19,20,21,22,23},
                  {24,25,26,27,28,29,30,31},
                  {32,33,34,35,36,37,38,39},
                  {40,41,42,43,44,45,46,47},
                  {48,49,50,51,52,53,54,55},
                  {56,57,58,59,60,61,62,63}};
 */
//Convierto nro de tecla a nombre de escaque
   char* escaque[] ={ "A1","A2","A3","A4","A5","A6","A7","A8",
                      "B1","B2","B3","B4","B5","B6","B7","B8",
                      "C1","C2","C3","C4","C5","C6","C7","C8",
                      "D1","D2","D3","D4","D5","D6","D7","D8",
                      "E1","E2","E3","E4","E5","E6","E7","E8",
                      "F1","F2","F3","F4","F5","F6","F7","F8",
                      "G1","G2","G3","G4","G5","G6","G7","G8",
                      "H1","H2","H3","H4","H5","H6","H7","H8",
                    }; 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
void setup() {
   Serial.begin(9600);
}
 
void loop() {
   char key = keypad.getKey();
    if (key) {
      
      Serial.println(escaque[key]);
      
   }
}
