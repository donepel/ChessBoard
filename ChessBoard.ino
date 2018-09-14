
/************************************************************
*****                  ChessBoard                        ****
*************************************************************/
/* ***************************************************+
Version2 Fecha 12 Septiembre 2018
se crea una rutina que mapee el keypad completo y vaya guardando en un array los escaques ocupados
ya que la funcion keypad funciona leyendo de a un escaque o tecla oprimida por vez 
  
Version 1 Fecha  08 Septiembre 2018
Se agrega configuracion basica para prueba concepto
esta configuracion se basa en la utilizacion de un teclado matrcial 4x4
a partir del puerto 5 ya que mas adelante se utilizara una matiz de 8x8
donde ira ubicada la cuadricula del tablero

*/

//Variables del estado de tablero
unsigned char Tablero[8][8],TableroNew[8][8];

//Definicion del tablero fisco
const byte PuertoFilas[8] = {22,23,24,25,26,27,28,29};
const byte PuertoColumnas[8] = {30,31,32,33,34,35,36,37};

void setup() 
{
   Serial.begin(115200);
}

void loop() 
{   
    Serial.println("Lectura de tablero");
  while(1)
  {
    Serial.println("");
    //Serial.println("nueva lectura");
    BoardStatus();
    for (char f=0;f<4;f++)
    {
      for (char c=0;c<4;c++)
      {
        Serial.print(TableroNew[f][c]);
      }
    }
    delay(100);
  }
}

/********************************************
 * Funcion de lectura del tablero
 ********************************************
 *  Esta funcion realiza la lectura actual del tablero
 *  y guarda en un arreglo (variable global) todos los escaques ocupados
Recive: Nada
Devuelve: Nada
*/
void BoardStatus()
{
  /*El tablero se compone de una matriz de 8x8 que sera leida en dos etapas 
  la primera colocando las filas en 1 y columnas en 0, buscando que columnas se encuentran en 1
  y se toma nonta
  la segunta es al reves, las columnas van en 1 y las fials en 0, se anotan que filas estan en 1
  y al finalizar se cruzan los datos para conocer todos los escaques ocupados.
  La condicion normal de los escaques es Normal Abierto
  */
  unsigned char fila,columna=0;
  for (fila=0;fila<8;fila++)//Barro todas las filas
  {
    pinMode(PuertoFilas[fila],INPUT); //Seteo fila como entrada
    digitalWrite(PuertoFilas[fila],HIGH); //Pull-UP software       
    for (columna=0;columna<8;columna++) //Por cada fila barro todas las columnas en busqueda de estados bajos
    {   
      pinMode(PuertoColumnas[columna],OUTPUT); //Seteo columna como salida
      digitalWrite(PuertoColumnas[columna],LOW); //Columna en nivel BAJO
      if (digitalRead(PuertoFilas[fila]) == LOW) //Si detecto un estado bajo, entonces esta pulsada la interseccion entre fila y columna actual
      {
         TableroNew[fila][columna]=HIGH; //Flag de escaque ocupado
         digitalWrite(PuertoColumnas[columna],HIGH); //Apago la columna para que no altere futuras mediciones
      }
      else //Si no, lo marco con LOW de forma tal que se entienda que esta libre
      {  
        TableroNew[fila][columna]=LOW; //Flag de escaque libre
        digitalWrite(PuertoColumnas[columna],HIGH); //Apago la columna para que no altere futuras mediciones
      }
    }
  }
}
