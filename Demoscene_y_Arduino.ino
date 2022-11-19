/*

  La demoscene me ayudó en mis proyectos conArduino:

  Demo de lectura de pines analógicos del Arduino UNO R3 y su visualización por puerto serial y ANSI
  Permite ahorrar recursos sin necesidad de una pantalla
  Ideal para docencia y talleres de Arduino
  Se puede aplicar tanto a Arduino como a Raspberry Pi Pico (desde la Arduino IDE)
  Bajos recursos (10%)


  Diapositiva 1

  Arduino (y otros microcontroladores) le dieron la espalda a la terminal serial como elemento cotidiano.
  A nivel docente se habla solamente como herramienta de debug y para algunas comunicaciones (BT, comandos AT, etc)

  -> Que me pasaba antes (problema)
  Me resultaba incompleto el Monitor Serie del Arduino IDE o de VSCode con Platformio.

  -> Por qué me funciona bien ANSI y Arduino
  Principalmente, me resulta mucho más enriquecedor tener una terminal linda en donde ver todo los datos del proyecto.
  Me abre un panorama nuevo sobre interactivdad, por ejemplo con sensores de distancia, de temperatura, pines y diferentes componentes

*/
#define ARRIBA 12
#define ABAJO 9
#define IZQUIERDA 11
#define DERECHA 10

int pantalla = 0;
bool concluido = false;
int valor = 0;
bool valorModificado = false;

#include "ansi.h"
ANSI ansi(&Serial);
unsigned long previousMillisSEGUNDO = 0;
int SEGUNDO = 1000;

void setup() {

  pinMode(ARRIBA, INPUT_PULLUP);
  pinMode(ABAJO, INPUT_PULLUP);
  pinMode(IZQUIERDA, INPUT_PULLUP);
  pinMode(DERECHA, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  ansi.clearScreen();
  RecuadroLineaDoble();
  DibujarArduinoUNO();

}

void BorraMediaPantalla()
{
  for (int x = 0; x < 23; x++) {
    for (int y = 0; y < 40; y++) {
      ansi.gotoXY(2 + x, 39 + y);
      ansi.print(" ");
    }
  }
}


void Bienvenidos()
{
  BorraMediaPantalla();
  ansi.gotoXY(10, 52);
  ansi.print("Bienvenidos! ");
  ansi.gotoXY(2, 47);
  ansi.foreground(2);
  ansi.print("La Demoscene y Arduino");
  ansi.gotoXY(4, 48);
  ansi.print("Por Marce Ferrarotti");
  ansi.gotoXY(6, 50);
  ansi.print("teno@disroot.org");
  ansi.gotoXY(8, 39);
  ansi.print("https://otroblogdemarcelo.wordpress.com/");
  ansi.normal();
  concluido = true;
}

void Diapositiva1()
{

  /* Arduino (y otros microcontroladores) le dieron la espalda a la terminal serial como elemento cotidiano.
    A nivel docente se habla solamente como herramienta de debug y para algunas comunicaciones (BT, comandos AT, etc)

    -> Que me pasaba antes (problema)
    Me resultaba incompleto el Monitor Serie del Arduino IDE o de VSCode con Platformio.

    -> Por qué me funciona bien ANSI y Arduino
    Principalmente, me resulta mucho más enriquecedor tener una terminal linda en donde ver todo los datos del proyecto.
    Me abre un panorama nuevo sobre interactivdad, por ejemplo con sensores de distancia, de temperatura, pines y diferentes componentes */

  BorraMediaPantalla();
#define Titulo "1 - La Demoscene y Arduino"
#define Linea1  "Arduino (y otros microcontroladores)"
#define Linea2  "le dieron la espalda a la terminal"
#define Linea3  "serial como elemento cotidiano."
#define Linea4  "Resulta incompleto el Monitor Serie"
#define Linea5  "del Arduino IDE o de VSCodium"
#define Linea6  "Solucion:"
#define Linea7  "Inspirado en la demoscene, usar ANSI!"
#define Linea8  "Es enriquecedor tener una terminal para"
#define Linea9  "ver todos los datos de un proyecto."
#define Linea10 "Y abre nuevos panoramas a explorar"

  ansi.gotoXY(2, 40);
  ansi.print(Titulo);
  ansi.gotoXY(4, 40);
  ansi.print(Linea1);
  ansi.gotoXY(5, 40);
  ansi.print(Linea2);
  ansi.gotoXY(6, 40);
  ansi.print(Linea3);
  ansi.gotoXY(8, 40);
  ansi.print(Linea4);
  ansi.gotoXY(9, 40);
  ansi.print(Linea5);
  ansi.gotoXY(11, 40);
  ansi.print(Linea6);
  ansi.gotoXY(12, 40);
  ansi.print(Linea7);
  ansi.gotoXY(14, 40);
  ansi.print(Linea8);
  ansi.gotoXY(15, 40);
  ansi.print(Linea9);
  ansi.gotoXY(17, 40);
  ansi.print(Linea10);

  concluido = true;
}

void Diapositiva2()
{
  BorraMediaPantalla();
  ansi.gotoXY(2, 40);
  ansi.print("2 - Usando ANSI en Arduino");
  ansi.gotoXY(4, 40);
  ansi.print("Instalar biblioteca con secuencias ANSI");
  ansi.gotoXY(5, 40);
  ansi.print("(VT100, Tera Term, Syncterm, etc.)");
  ansi.foreground(6);
  ansi.gotoXY(7, 40);
  ansi.print("Autor: Rob Tillaart");
  ansi.normal();
  ansi.gotoXY(9, 40);
  ansi.print("En Arduino IDE: ");
  ansi.gotoXY(9, 40);
  ansi.print("Programa -> Incluir libreria");
  ansi.gotoXY(10, 40);
  ansi.print("Administrar Bibliotecas...");
  ansi.gotoXY(11, 40);
  ansi.print("Buscar ANSI y luego INSTALAR");
  ansi.foreground(3);
  ansi.gotoXY(13, 40);
  ansi.print("#include ''ansi.h''");
  ansi.gotoXY(14, 40);
  ansi.print("ANSI ansi(&Serial); ");
  ansi.foreground(5);
  ansi.gotoXY(16, 40);
  ansi.print("ansi.gotoXY(fila, col); ");
  ansi.gotoXY(17, 40);
  ansi.print("ansi.background(color); ");
  ansi.gotoXY(18, 40);
  ansi.print("ansi.foreground(color); ");
  ansi.gotoXY(19, 40);
  ansi.print("ansi.print(''hola!''); ");
  ansi.gotoXY(20, 40);
  ansi.print("ansi.normal(); ");
  ansi.normal();
  ansi.gotoXY(22, 40);
  ansi.print("Leer documentacion y ejemplos...");
  concluido = true;
}


void Diapositiva3()
{
  BorraMediaPantalla();
  ansi.gotoXY(2, 40);
  ansi.print("3 - Ventajas");
  ansi.gotoXY(4, 40);
  ansi.print("Exceder las capacidades de los");
  ansi.gotoXY(5, 40);
  ansi.print("displays 'comprables' por ejemplo: ");
  ansi.gotoXY(6, 40);
  ansi.print("LCD 1602 y 2004, oled 0.96'', etc.");
  ansi.gotoXY(8, 40);
  ansi.print("Mostrar mayor cantidad de datos");
  ansi.gotoXY(9, 40);
  ansi.print("y de mejor calidad, ");
  ansi.gotoXY(10, 40);
  ansi.print("agregando descripciones, etc.");
  ansi.gotoXY(12, 40);
  ansi.print("Se usan menos pines");
  ansi.gotoXY(14, 40);
  ansi.print("Se abarata el proyecto");
  ansi.gotoXY(16, 40);
  ansi.print("Son necesarios pocos elementos: ");
  ansi.gotoXY(17, 40);
  ansi.print("Arduino, sensores, ");
  ansi.gotoXY(18, 40);
  ansi.print("cable USB y terminal ANSI");
  concluido = true;

  /*

    Exceder las capacidades de los
    displays más usados
    (1602, 2004, oled, etc)

    Mostrar más informacion y con
    mas cantidad de detalles

    Usar menos cantidad de pines

    Abaratar los proyectos de desarrollo
  */
}

void Diapositiva4()
{
  BorraMediaPantalla();
#define Titulo "4 - Desventajas"
#define Linea1  "Consumo de memoria en micros chicos"
#define Linea2  "Complica programas dependientes"
#define Linea3  "de timers precisos"

  ansi.gotoXY(2, 40);
  ansi.print(Titulo);
  ansi.gotoXY(4, 40);
  ansi.print(Linea1);
  ansi.gotoXY(6, 40);
  ansi.print(Linea2);
  ansi.gotoXY(7, 40);
  ansi.print(Linea3);

  concluido = true;
}

void Diapositiva5()
{
  BorraMediaPantalla();
  ansi.gotoXY(2, 40);
  ansi.print("5 - Ejemplo de lectura del ADC");

  ansi.gotoXY(6, 50);
  ansi.foreground(2);
  ansi.print("A0: ");

  ansi.gotoXY(8, 50);
  ansi.foreground(3);
  ansi.print("A1: ");

  ansi.gotoXY(10, 50);
  ansi.foreground(4);
  ansi.print("A2: ");

  ansi.gotoXY(12, 50);
  ansi.foreground(5);
  ansi.print("A3: ");

  ansi.gotoXY(14, 50);
  ansi.foreground(6);
  ansi.print("A4: ");

  ansi.gotoXY(16, 50);
  ansi.foreground(7);
  ansi.print("A5: ");

  ansi.normal();
  concluido = true;
}

void Diapositiva6() {
  BorraMediaPantalla();
  ansi.gotoXY(2, 40);
  ansi.print("6 - Barra de estado");
  ansi.gotoXY(5, 46);
  ansi.print("Progreso:");
  ansi.gotoXY(4, 40);
  ansi.print("[");
  ansi.gotoXY(4, 65);
  ansi.print("]");
  concluido = true;
}

void DibujarArduinoUNO()
{
  //PCB
  ansi.gotoXY(4, 3);
  ansi.foreground(4);
  for (int x = 1; x < 20; x++) {
    for (int y = 1; y < 35; y++) {
      ansi.gotoXY(4 + x, 3 + y);
      ansi.print((char)178);
    }
  }
  for (int y = 2; y < 31; y++) {
    ansi.gotoXY(24, 3 + y);
    ansi.print((char)178);
  }

  //USB
  ansi.foreground(6);
  ansi.gotoXY(2, 26);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(3, 26);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(4, 26);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(5, 26);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);

  //PINES
  ansi.normal();
  for (int x = 1; x < 8; x++) {
    ansi.gotoXY(9 + x, 5);
    ansi.print(char(254));

    for (int x = 1; x < 7; x++) {
      ansi.gotoXY(17 + x, 5);
      ansi.print(char(254));
    }

    for (int x = 1; x < 9; x++) {
      ansi.gotoXY(15 + x, 36);
      ansi.print(char(254));
    }

    for (int x = 1; x < 9; x++) {
      ansi.gotoXY(6 + x, 36);
      ansi.print(char(254));
    }

    //Atmega328
    ansi.normal();
    ansi.foreground(0);
    for (int x = 1; x < 15; x++) {
      ansi.gotoXY(9 + x, 15);
      ansi.normal(); ansi.print((char)181); ansi.foreground(0); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.normal(); ansi.print((char)198); ansi.foreground(0);

    }

    //ETIQUETAS
    ansi.normal();
    ansi.foreground(0);
    ansi.background(4);
    ansi.gotoXY(10, 7);
    ansi.print("IOREF");
    ansi.gotoXY(11, 7);
    ansi.print("RST");
    ansi.gotoXY(12, 7);
    ansi.print("3V3");
    ansi.gotoXY(13, 7);
    ansi.print("5v");
    ansi.gotoXY(14, 7);
    ansi.print("GND");
    ansi.gotoXY(15, 7);
    ansi.print("GND");
    ansi.gotoXY(16, 7);
    ansi.print("Vin");
    ansi.gotoXY(18, 7);
    ansi.print("A0");
    ansi.gotoXY(19, 7);
    ansi.print("A1");
    ansi.gotoXY(20, 7);
    ansi.print("A2");
    ansi.gotoXY(21, 7);
    ansi.print("A3");
    ansi.gotoXY(22, 7);
    ansi.print("A4");
    ansi.gotoXY(23, 7);
    ansi.print("A5");

    ansi.gotoXY(7, 31);
    ansi.print("AREF");
    ansi.gotoXY(8, 32);
    ansi.print("GND");
    ansi.gotoXY(9, 33);
    ansi.print("13");
    ansi.gotoXY(10, 33);
    ansi.print("12");
    ansi.gotoXY(11, 32);
    ansi.print("~11");
    ansi.gotoXY(12, 32);
    ansi.print("~10");
    ansi.gotoXY(13, 33);
    ansi.print("~9");
    ansi.gotoXY(14, 34);
    ansi.print("8");

    ansi.gotoXY(16, 34);
    ansi.print("7");
    ansi.gotoXY(17, 33);
    ansi.print("~6");
    ansi.gotoXY(18, 33);
    ansi.print("~5");
    ansi.gotoXY(19, 34);
    ansi.print("4");
    ansi.gotoXY(20, 33);
    ansi.print("~3");
    ansi.gotoXY(21, 34);
    ansi.print("2");
    ansi.gotoXY(22, 29);
    ansi.print("TX > 1");
    ansi.gotoXY(23, 29);
    ansi.print("RX < 0");

    ansi.gotoXY(8, 15);
    ansi.print("[ ] led");

    ansi.normal();
  }
}

void RecuadroLineaDoble() {

  ansi.gotoXY(1, 1);
  ansi.print((char)201);
  ansi.gotoXY(1, 80);
  ansi.print((char)187);
  ansi.gotoXY(25, 1);
  ansi.print((char)200);
  ansi.gotoXY(25, 80);
  ansi.print((char)188);

  for (int i = 2; i < 80; i++)
  {
    ansi.gotoXY(1, i);
    ansi.print((char)205);
    ansi.gotoXY(25, i);
    ansi.print((char)205);
  }

  for (int i = 2; i < 25; i++)
  {
    ansi.gotoXY(i, 1);
    ansi.print((char)186);
    ansi.gotoXY(i, 80);
    ansi.print((char)186);
  }
  ansi.normal();
}

void loop() {

  unsigned long currentMillisSEGUNDO = millis();

  if ((unsigned long)(currentMillisSEGUNDO - previousMillisSEGUNDO) >= SEGUNDO) {
    ansi.gotoXY(24, 65);
    ansi.foreground(4);
    ansi.print(millis() / 1000);
    ansi.foreground(6);
    ansi.print(" segundos");
    ansi.normal();

    switch (pantalla) {
      case 0:
        if (concluido == false) {
          Bienvenidos();
        }
        break;
      case 1:
        if (concluido == false) {
          Diapositiva1();
        }
        break;
      case 2:
        if (concluido == false) {
          Diapositiva2();
        }
        break;
      case 3:
        if (concluido == false) {
          Diapositiva3();
        }
        break;
      case 4:
        if (concluido == false) {
          Diapositiva4();
        }
        break;
      case 5:
        if (concluido == false) {
          Diapositiva5();
        }
        ansi.gotoXY(6, 54);
        ansi.print("    ");
        ansi.gotoXY(8, 54);
        ansi.print("    ");
        ansi.gotoXY(10, 54);
        ansi.print("    ");
        ansi.gotoXY(12, 54);
        ansi.print("    ");
        ansi.gotoXY(14, 54);
        ansi.print("    ");
        ansi.gotoXY(16, 54);
        ansi.print("    ");

        ansi.gotoXY(6, 54);
        ansi.background(2);
        ansi.foreground(0);
        ansi.print(analogRead(A0));
        ansi.normal();

        ansi.gotoXY(8, 54);
        ansi.background(3);
        ansi.foreground(0);
        ansi.print(analogRead(A1));
        ansi.normal();

        ansi.gotoXY(10, 54);
        ansi.background(4);
        ansi.foreground(0);
        ansi.print(analogRead(A2));
        ansi.normal();

        ansi.gotoXY(12, 54);
        ansi.background(5);
        ansi.foreground(0);
        ansi.print(analogRead(A3));
        ansi.normal();

        ansi.gotoXY(14, 54);
        ansi.background(6);
        ansi.foreground(0);
        ansi.print(analogRead(A4));
        ansi.normal();

        ansi.gotoXY(16, 54);
        ansi.background(7);
        ansi.foreground(0);
        ansi.print(analogRead(A5));
        ansi.normal();
        break;
      case 6:
        if (concluido == false) {
          Diapositiva6();
        }
        if (valorModificado == true) {
          valorModificado == false;
          ansi.gotoXY(5, 57);
          ansi.foreground(3);
          ansi.print(map(valor, 1, 25, 1, 100));
          ansi.print(" % ");
          for (int i = 1; i < 25; i++) {
            ansi.gotoXY(4, i + 40);
            ansi.print(" ");
          }
          for (int i = 1; i < valor; i++) {
            ansi.gotoXY(4, i + 40);
            ansi.print((char)178);
          }

          if (map(valor, 1, 25, 1, 100) == 100) {
            ansi.gotoXY(10, 51);
            ansi.foreground(4);
            ansi.print("Muchas gracias!");
            ansi.gotoXY(12, 51);
            ansi.foreground(5);
            ansi.print("Marce Ferrarotti");
            ansi.gotoXY(14, 51);
            ansi.foreground(6);
            ansi.print("teno@disroot.org");
            ansi.gotoXY(16, 39);
            ansi.foreground(1);
            ansi.print("https://otroblogdemarcelo.wordpress.com/");
          }
          ansi.normal();
        }
        break;
    }

    previousMillisSEGUNDO = currentMillisSEGUNDO;

  }

  if (digitalRead(IZQUIERDA) == 0) {
    digitalWrite(LED_BUILTIN, !digitalRead(IZQUIERDA));
    while (!digitalRead(IZQUIERDA));
    concluido = false;
    pantalla--;
    if (pantalla <= 0) {
      pantalla = 0;
    }
  } else {
    digitalWrite(LED_BUILTIN, !digitalRead(IZQUIERDA));
  }

  if (digitalRead(DERECHA) == 0) {
    digitalWrite(LED_BUILTIN, !digitalRead(DERECHA));
    while (!digitalRead(DERECHA));
    concluido = false;
    pantalla++;
    if (pantalla > 6) {
      pantalla = 6;
    }
  } else {
    digitalWrite(LED_BUILTIN, !digitalRead(DERECHA));
  }

  if (digitalRead(ARRIBA) == 0) {
    digitalWrite(LED_BUILTIN, !digitalRead(ARRIBA));
    while (!digitalRead(ARRIBA));
    valorModificado = true;
    valor++;
    if (valor > 25) {
      valor = 25;
    }
  } else {
    digitalWrite(LED_BUILTIN, !digitalRead(ARRIBA));
  }

  if (digitalRead(ABAJO) == 0) {
    digitalWrite(LED_BUILTIN, !digitalRead(ABAJO));
    while (!digitalRead(ABAJO));
    valorModificado = true;
    valor--;
    if (valor < 1) {
      valor = 1;
    }
  } else {
    digitalWrite(LED_BUILTIN, !digitalRead(ABAJO));
  }


}

/* digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  ansi.gotoXY(8, 15);
  if (digitalRead(LED_BUILTIN) == 1)
  {
  ansi.foreground(3);
  ansi.print((char)178);
  ansi.normal();
  } else {
  ansi.normal();
  ansi.print(" ");
  }
*/

/* ansi.gotoXY(18, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(18, 10);
  ansi.print(analogRead(A0));

  ansi.gotoXY(19, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(19, 10);
  ansi.print(analogRead(A1));

  ansi.gotoXY(20, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(20, 10);
  ansi.print(analogRead(A2));

  ansi.gotoXY(21, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(21, 10);
  ansi.print(analogRead(A3));

  ansi.gotoXY(22, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(22, 10);
  ansi.print(analogRead(A4));

  ansi.gotoXY(23, 10);
  ansi.foreground(4);
  ansi.print((char)178); ansi.print((char)178); ansi.print((char)178); ansi.print((char)178);
  ansi.gotoXY(23, 10);
  ansi.print(analogRead(A5));

  //Saco el cursor del medio de la pantalla
  ansi.gotoXY(25, 80);
*/
