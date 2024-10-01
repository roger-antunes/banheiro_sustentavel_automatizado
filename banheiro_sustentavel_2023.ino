//Código Banheiro Sustentável Automatizado - Mostra de Tecnologia da D.E. de Jundiaí 2023
const int boiaPrivada = 2; //nomeia o pino 2 do Arduino, fazendo referência à boia
const int boiaReservatorio = 3; //nomeia o pino 3 do Arduino, fazendo referência à boia
const int bomba = 4; // nomeia o pino 4 do Arduino, fazendo referência à bomba
const int ledBombaFuncionando = 5; // nomeia o pino 5 do Arduino, fazendo referência ao led de bomba em funcionamento
const int ledReservatorioCritico = 6; // nomeia o pino 6 do Arduino, fazendo referência ao led do nivel critico de água no reservatório

void setup() {
  Serial.begin(9600);
  pinMode(boiaPrivada, INPUT_PULLUP); //Seta o pino da boia como entrada de sinal
  pinMode(boiaReservatorio, INPUT_PULLUP); //Seta o pino da boia como entrada de sinal
  pinMode(ledBombaFuncionando, OUTPUT); //Seta o pino do led como saída de sinal
  pinMode(ledReservatorioCritico, OUTPUT); //Seta o pino do led como saída de sinal
  pinMode(bomba, OUTPUT); //Seta o pino da bomba como saída de sinal
  digitalWrite(bomba, LOW); //desliga a bomba
}

void loop() {
  if(digitalRead(boiaReservatorio)== LOW){ //verifica se a boia do reservatorio está no nivel adequado
    digitalWrite(bomba, LOW); //desliga a bomba
    Serial.println("Bomba Desligada!"); //indicador para leitura serial (pelo PC)
    digitalWrite(ledReservatorioCritico, HIGH); // liga o led que indica que o nível de água está baixo e que a bomba não funcionará
    digitalWrite(ledBombaFuncionando, LOW);    //desliga a luz da bomba
    delay(1000); //pequena pausa, pois senão o código é processado em milésimos de segundos
  } else {
    digitalWrite(ledReservatorioCritico, LOW); // desliga o led que indica que o nível de água está baixo e que a bomba não funcionará
    if (digitalRead(boiaPrivada) == HIGH){ //Se o sensor for acionado, faça:
      digitalWrite(bomba, HIGH);    //ligue a bomba
      digitalWrite(ledBombaFuncionando, HIGH);    //ligue a luz da bomba
      Serial.println("Bomba Ligada!"); //indicador para leitura serial (pelo PC)
      delay(1000); //pequena pausa, pois senão o código é processado em milésimos de segundos
    } else {    //Senão:
      digitalWrite(ledReservatorioCritico, LOW);                 
      digitalWrite(bomba, LOW);     //desligue a bomba
      digitalWrite(ledBombaFuncionando, LOW);    //desliga a luz da bomba
      Serial.println("Bomba Desligada!"); //indicador para leitura serial (pelo PC)
      delay(1000); //pequena pausa, pois senão o código é processado em milésimos de segundos
    }
  }
}
