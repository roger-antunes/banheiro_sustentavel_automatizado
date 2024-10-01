# Banheiro Sustentável Automatizado

## Descrição do Projeto

O projeto "Banheiro Sustentável Automatizado" foi desenvolvido em conjunto com alunos da E.E. M. A. Schledorn como um protótipo de sistema de reaproveitamento de água. O sistema foi apresentado na Mostra de Tecnologia da Diretoria de Ensino de Jundiaí em 2023, onde obteve o segundo lugar. O objetivo do projeto é promover a sustentabilidade e a eficiência no uso da água em ambientes domésticos.

## Funcionalidade

O código implementa um sistema que controla uma bomba de água com base em dois sensores de boia: um para o reservatório de água e outro para a privada. O sistema garante que a bomba funcione apenas quando o nível de água no reservatório estiver adequado e que a privada necessite de água.

### Componentes Utilizados

- **Boia da Privada**: Sensor que indica quando a privada precisa de água.
- **Boia do Reservatório**: Sensor que monitora o nível de água no reservatório.
- **Bomba**: Dispositivo que movimenta a água do reservatório para a privada.
- **LEDs**: Indicadores visuais para o funcionamento da bomba e o nível crítico de água no reservatório.

## Código

```cpp
// Código Banheiro Sustentável Automatizado - Mostra de Tecnologia da D.E. de Jundiaí 2023
const int boiaPrivada = 2; // nomeia o pino 2 do Arduino, fazendo referência à boia
const int boiaReservatorio = 3; // nomeia o pino 3 do Arduino, fazendo referência à boia
const int bomba = 4; // nomeia o pino 4 do Arduino, fazendo referência à bomba
const int ledBombaFuncionando = 5; // nomeia o pino 5 do Arduino, fazendo referência ao led de bomba em funcionamento
const int ledReservatorioCritico = 6; // nomeia o pino 6 do Arduino, fazendo referência ao led do nível crítico de água no reservatório

void setup() {
  Serial.begin(9600);
  pinMode(boiaPrivada, INPUT_PULLUP); // Seta o pino da boia como entrada de sinal
  pinMode(boiaReservatorio, INPUT_PULLUP); // Seta o pino da boia como entrada de sinal
  pinMode(ledBombaFuncionando, OUTPUT); // Seta o pino do led como saída de sinal
  pinMode(ledReservatorioCritico, OUTPUT); // Seta o pino do led como saída de sinal
  pinMode(bomba, OUTPUT); // Seta o pino da bomba como saída de sinal
  digitalWrite(bomba, LOW); // Desliga a bomba
}

void loop() {
  if(digitalRead(boiaReservatorio) == LOW) { // Verifica se a boia do reservatório está no nível adequado
    digitalWrite(bomba, LOW); // Desliga a bomba
    Serial.println("Bomba Desligada!"); // Indicador para leitura serial (pelo PC)
    digitalWrite(ledReservatorioCritico, HIGH); // Liga o led que indica que o nível de água está baixo
    digitalWrite(ledBombaFuncionando, LOW); // Desliga a luz da bomba
    delay(1000); // Pausa para evitar processamento excessivo
  } else {
    digitalWrite(ledReservatorioCritico, LOW); // Desliga o led do nível crítico
    if (digitalRead(boiaPrivada) == HIGH) { // Se o sensor da privada for acionado
      digitalWrite(bomba, HIGH); // Liga a bomba
      digitalWrite(ledBombaFuncionando, HIGH); // Liga a luz da bomba
      Serial.println("Bomba Ligada!"); // Indicador para leitura serial (pelo PC)
      delay(1000); // Pausa para evitar processamento excessivo
    } else { // Se não
      digitalWrite(bomba, LOW); // Desliga a bomba
      digitalWrite(ledBombaFuncionando, LOW); // Desliga a luz da bomba
      Serial.println("Bomba Desligada!"); // Indicador para leitura serial (pelo PC)
      delay(1000); // Pausa para evitar processamento excessivo
    }
  }
}
```

## Como Funciona

1. **Inicialização**: O sistema inicializa os pinos do Arduino e desliga a bomba.
2. **Monitoramento do Reservatório**: O código verifica continuamente o nível de água no reservatório. Se o nível estiver baixo, a bomba é desligada e um LED de alerta é acionado.
3. **Controle da Bomba**: Quando a boia da privada é acionada, a bomba é ligada para fornecer água. Se a boia da privada não estiver
