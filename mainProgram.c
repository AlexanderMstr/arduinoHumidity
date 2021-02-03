#include <iarduino_4LED.h>                                  
//#include "QuadDisplay2.h" //для работы с дисплеем

int ledPin = 13;                   // Светодиод подключенный к вход/выходу 13
int inPin = 7;                    // кнопка на входе 7
int val = 0;                     // переменная для хранения значения
int analogPin = 3;              // номер порта к которому подключен потенциометр
int aPin=A0; // контакт подключения аналогового выхода датчика
int ledPins[1]={13};  // контакты  подключения светодоодов индикации
int countled=1;// переменная количества светящихся светодиодов
int analogValue = 0;    // переменная для хранения считываемого значения

int minvalue=300;// минимальная влажность 

int maxvalue=800;// максимальная влажность

void setup() 
{
pinMode(ledPin, OUTPUT);      // устанавливает режим работы - выход

Serial.begin(9600); // открывает последовательный порт, устанавливает скорость 9600 бит/c


}

void loop() 
{
 
  digitalWrite(ledPin, HIGH);   // включает светодиод
  delay(1000);                  // ждет секунду
  digitalWrite(ledPin, LOW);    // выключает светодиод
  delay(1000);                  // ждет секунду
  val = analogRead(analogPin);     // считываем значение
  Serial.println(val);             // выводим полученное значение


 // масштабируем значение на светодиое
  countled=map(countled,maxvalue,minvalue,0,1);
  analogValue = analogRead(0);// считываем данные с входа 0
 Serial.println(analogValue); 
  // индикация уровня влажности
  for(int i=0;i<8;i++)
    {
    if(i<=countled)
       digitalWrite(ledPins[i],HIGH); //зажигаем светодиод
    else
       digitalWrite(ledPins[i],LOW);  // гасим светодиод
    }

  delay(1000);// приостанавливает программу на интервал, измеряемый в миллисекундах
}
//void pindMode(int pin, int mode)

//void digitalWrite(int pin, int value)