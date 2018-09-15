
/************************************************************
*****                  ChessBoard                        ****                        
*****                 by Don_Epel                        ****
*************************************************************/

/* ***************************************************+
Version
Version2.2 fecha 15 sep
*function BoardStatus() is ok
Version2 Fecha 12 Septiembre 2018
*se crea una rutina que mapee el keypad completo y vaya guardando en un array los escaques ocupados
*ya que la funcion keypad funciona leyendo de a un escaque o tecla oprimida por vez 
Version 1 Fecha  08 Septiembre 2018
*Se agrega configuracion basica para prueba concepto
*esta configuracion se basa en la utilizacion de un teclado matrcial 4x4
*a partir del Port 5 ya que mas adelante se utilizara una matiz de 8x8
*donde ira ubicada la cuadricula del Board

*/

//Variables del estado de Board
unsigned char Board[8][8],BoardNew[8][8];

//Definicion del Board fisco
const byte PortRows[8] = {22,23,24,25,26,27,28,29};
const byte PortColumns[8] = {30,31,32,33,34,35,36,37};

void setup() 
{
   Serial.begin(115200);
}

void loop() 
{   
    
  while(1)
  {
    Serial.println("");
    Serial.println("Chessboard status");
    BoardStatus();
    for (char f=0;f<8;f++)
    {
      for (char c=0;c<8;c++)
      {
        Serial.print(BoardNew[f][c]);
      }
      Serial.println("");
      
    }
    delay(1000);
  }
}

/********************************************
 * Funcion de lectura del Board
 ********************************************
 *  Esta funcion realiza la lectura actual del Board
 *  y guarda en un arreglo (variable global) todos los escaques ocupados
Recive: Nada
Devuelve: Nada
*/
void BoardStatus()
{
  unsigned char row,column=0;
  for (row=0;row<8;row++)//Barro todas las Rows
  {
    pinMode(PortRows[row],INPUT); //Seteo row como entrada
    digitalWrite(PortRows[row],HIGH); //Pull-UP software       
    for (column=0;column<8;column++) //Por cada row barro todas las Columns en busqueda de estados bajos
    {   
      pinMode(PortColumns[column],OUTPUT); //Seteo column como salida
      digitalWrite(PortColumns[column],LOW); //column en nivel BAJO
      if (digitalRead(PortRows[row]) == LOW) //Si detecto un estado bajo, entonces esta pulsada la interseccion entre row y column actual
      {
         BoardNew[row][column]=HIGH; //Flag de escaque ocupado
         digitalWrite(PortColumns[column],HIGH); //Apago la column para que no altere futuras mediciones
      }
      else //Si no, lo marco con LOW de forma tal que se entienda que esta libre
      {  
        BoardNew[row][column]=LOW; //Flag de escaque libre
        digitalWrite(PortColumns[column],HIGH); //Apago la column para que no altere futuras mediciones
      }
    }
  }
}
