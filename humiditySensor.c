//Датчик измерения влажности почвы
#define value 7
#define pin A0
int readSensor();
void setup() 
{
  pinMode(value, OUTPUT);

  digitalWrite(value, LOW);//датчик включен

  Serial.begin(9600);  // открывает последовательный порт, устанавливает скорость 9600 бит/c
}

void loop() 
{
 
  Serial.print("Analog output: "); // получить показание из функции ниже и напечатать его
  Serial.println(readSensor());

  delay(1000);
}

int readSensor() //возвращает аналоговый результат измерений датчика влажности почвы
{
  digitalWrite(value, HIGH);     // Включить датчик
  delay(10);                    // Дать время питанию установиться
  int val = analogRead(pin);   // Прочитать аналоговое значение от датчика
  digitalWrite(value, LOW);   // Выключить датчик
  return val;                // Вернуть аналоговое значение влажности
}