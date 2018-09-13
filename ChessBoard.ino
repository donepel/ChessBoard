
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
unsigned char actualboard[64]; //Aqui guardare el estado actual del tablero

//Definicion del tablero
const byte PuertoFilas[7] = {12,11,10,9};
const byte PuertoColumnas[7] = {8,7,6,5};

void setup() 
{
   Serial.begin(9600);
}

void loop() 
{   
  Serial.println("Lectura de tablero");
  while(1)
  {
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


}
