#include <NewPing.h>                   //adauga libraria "NewPing" ( libraria senzorului ) in program ;
#define trig 12                        // defineste PIN-ul 12 sub denumriea de "trig"; 
#define echo 11                        // defineste PIN-ul 11 sub denumriea de "echo";
#define maxd 250                       // defineste distanta maxima ce va fi detectata de senzor;
int uS;                                // initializeaza variabila "uS";
float i=uS;
/* motorul A */
int enA = 9;                           // motor A; initializeaza "enA" ca fiind PIN-ul 9;
int in1 = 5;                           // initializeaza "in1" ca fiind PIN-ul 5;
int in2 = 4;                           // initializeaza "in2" ca fiind PIN-ul 4;
/* motorul B */
int enB = 6;                           // motor B; initializeaza "enB" ca fiind PIN-ul 6;
int in3 = 3;                           // initializeaza "in3" ca fiind PIN-ul 3;
int in4 = 2;                           // initializeaza "in4" ca fiind PIN-ul 2;
int ledverde = 13;                     // initializeaza "ledverde" ca fiind PIN-ul 13;
int ledrosu = 10;                       // initializeaza "ledrosu" ca fiind PIN-ul 7;
NewPing sonar(trig, echo, maxd);       // defineste PIN-urile conectate la senzor;



void setup(){                          // seteaza toate PIN-urile motorului ca iesire (OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(115200);}               // selecteaza canalul 115200 pentru " Serial Monitor" ;



void loop(){                            // tot ce este in interiorul "loop()" se va repeta la infinit;
  delay(50);                         // intarzie repetarea programului;
  unsigned int uS = sonar.ping_cm();   // initializeaza uS ca "sonar.ping_cm()" , "ping_cm()" transforma din inchi in centimetri;
  Serial.print("Distanta: ");          // afiseaza in Serial Monitor " Distanta: " ;                            /*  
  Serial.print(uS );                   // afiseaza valoarea lui "uS" ;                                                  In Serial Monitor se va afisa " Distanta: x cm" 
  Serial.println("cm");                // afiseaza in Serial Monitor "cm" ;                                                                                                  */ 
 
      if(uS>35)                              // daca  distanta dintre senzor si obstacol e mai mare de 50 ;
       {digitalWrite(in1, LOW);              // motorul A va merge in fata;
        digitalWrite(in2, HIGH);                         
        analogWrite(enA,100);               // seteaza viteza 100 din raza posibila 0~255;
        digitalWrite(in3, LOW);             // motorul B va merge in fata;
        digitalWrite(in4, HIGH);
        analogWrite(enB, 100);}              // seteaza viteza 100 din raza posibila 0~255;
        
        else{                                // altfel;  Asta va face ca robotul sa isi schimbe directia de mers;                        
                                             // motorul A va merge in fata;
          digitalWrite(in1, HIGH);                                                                                 
          digitalWrite(in2, LOW);                                                   
          analogWrite(enA, 100);             // seteaza viteza 100 din raza posibila 0~255;                             
                                             
          digitalWrite(in3, LOW);                                                                                          
          digitalWrite(in4, HIGH);           
          analogWrite(enB, 100);}            // seteaza viteza 100 din raza posibila 0~255;                                                                                     
          
      
      if(uS>35){                            // daca  distanta dintre senzor si obstacol este mai mare de 50;
        digitalWrite(ledverde,HIGH);        // ledul verde se va aprinde;
        digitalWrite(ledrosu,LOW);}         // ledul rosu va sta stins;
                  
        else{                               // in caz contrar:
          digitalWrite(ledrosu,HIGH);       // ledul rosu va fi aprins;
          digitalWrite(ledverde,LOW);}      // ledul verde va fi stins; 
}
