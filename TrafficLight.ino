int RedLed = 13;             // Порт 13, красный светодиод
int YelLed = 12;             // Порт 12, желтый светодиод
int GrnLed = 11;             // Порт 11, зеленый светодиод

int RedTime = 10000;          // Время горения красного сетодиода
int YelTime = 2000;          // Время горения желтого светодиода
int GrnTime = 7000;          // Время горения зеленого светодиода до первого включения желтого

int GrnFlashTime = 500;      // Время мигания зеленого светодиода

int GrnNumFlash = 3;         // Сколько раз необходимо мигнуть зеленому светодиоду

void setup()
{
  // Инициализируем порты "Led" как выходные
  pinMode(RedLed, OUTPUT);   
  pinMode(YelLed, OUTPUT);
  pinMode(GrnLed, OUTPUT);
  
  // Устанавливаем все светодиоды LOW
  digitalWrite(RedLed, LOW);
  digitalWrite(YelLed, LOW);
  digitalWrite(GrnLed, LOW);
}  

void loop()
{
  // Включаем красный светодиод.
  digitalWrite(RedLed, HIGH);            
  delay(RedTime);                         
          
  // Включаем желтый светодиод
  digitalWrite(YelLed, HIGH);           
  delay(YelTime);                       
  
  // Отключаем желтый и красный светодиоды.
  digitalWrite(YelLed, LOW);    
  digitalWrite(RedLed, LOW);   
  
  // Включаем зеленый светодиод на GrnTime
  digitalWrite(GrnLed, HIGH);           
  delay(GrnTime);               
  
  // Мигаем GrnNumFlash аз зеленым с частотой GrnFlashTime   
  for (int i=GrnNumFlash; i>0; i--)
    {
      digitalWrite(GrnLed, LOW);         
      delay(GrnFlashTime);                
      digitalWrite(GrnLed, HIGH);        
      delay(GrnFlashTime);                
    }  
  
  // Включаем желтый светодиод и отключаем зеленый 
  digitalWrite(GrnLed, LOW); 
  digitalWrite(YelLed, HIGH);           
  delay(YelTime);            

  // Отключаем желтый и зеленый светодиоды.
  digitalWrite(YelLed, LOW); 
}
