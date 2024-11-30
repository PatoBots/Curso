// Definindo os pinos do motor na Ponte H
const int pinoMotorA1 = 7;      // Pino de controle 1 para motor A
const int pinoMotorA2 = 8;      // Pino de controle 2 para motor A
const int pinoHabilitarA = 9;   // Pino de controle de velocidade para motor A
const int pinoMotorB1 = 11;     // Pino de controle 1 para motor B
const int pinoMotorB2 = 12;     // Pino de controle 2 para motor B
const int pinoHabilitarB = 10;  // Pino de controle de velocidade para motor B

// Definindo os pinos dos sensores reflexivos
const int pinoSensorEsquerda = 6;  // Pino do sensor reflexivo esquerdo
const int pinoSensorCentro = 5;    // Pino do sensor reflexivo central
const int pinoSensorDireita = 4;   // Pino do sensor reflexivo direito

// Definindo os pinos do sensor ultrassônico
const int pinoTrigger = 2;  // Pino de disparo do ultrassônico
const int pinoEcho = 3;     // Pino de recepção do ultrassônico

const int velocidade_motor_A = 150;
const int velocidade_motor_B = 150;

const int atacar_motor_A = 250;
const int atacar_motor_B = 250;

const int velocidade_virar_Para_Esquerda = 75;
const int velocidade_virar_Para_Direita = 75;

const int velocidade_curva_A = 75;
const int velocidade_curva_B = 75;

const int velocidade_virar_Para_Esquerda_A = 75;
const int velocidade_virar_Para_Esquerda_B = 75;

const int velocidade_virar_Para_Direita_A = 75;
const int velocidade_virar_Para_Direita_B = 75;


void setup() {
  // Configurando os pinos como saídas e entradas

  // Configurando os pinos da Ponte H
  pinMode(pinoMotorA1, OUTPUT);
  pinMode(pinoMotorA2, OUTPUT);
  pinMode(pinoHabilitarA, OUTPUT);

  pinMode(pinoMotorB1, OUTPUT);
  pinMode(pinoMotorB2, OUTPUT);
  pinMode(pinoHabilitarB, OUTPUT);

  // Configurando os pinos do sensor Óptico Reflexivo
  pinMode(pinoSensorEsquerda, INPUT);
  pinMode(pinoSensorCentro, INPUT);
  pinMode(pinoSensorDireita, INPUT);

  // Configurando os pinos do sensor Ultrassônico
  pinMode(pinoTrigger, OUTPUT);
  pinMode(pinoEcho, INPUT);
}
void atacar() {
  // Define a direção do motor para frente
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, HIGH);
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, HIGH);

  // Ajusta a velocidade do motor
  analogWrite(pinoHabilitarA, atacar_motor_A);  // 255 é a velocidade máxima
  analogWrite(pinoHabilitarB, atacar_motor_B);  // 255 é a velocidade máxima
}

void moverParaFrente() {
  // Define a direção do motor para frente
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, HIGH);
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, HIGH);

  // Ajusta a velocidade do motor
  analogWrite(pinoHabilitarA, velocidade_motor_A);  // 255 é a velocidade máxima
  analogWrite(pinoHabilitarB, velocidade_motor_B);  // 255 é a velocidade máxima
}

void ParardeMover() {
  // Define a direção do motor para frente
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, LOW);
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, LOW);
}

void moverParaTras() {
  // Define a direção do motor para trás
  digitalWrite(pinoMotorA1, HIGH);
  digitalWrite(pinoMotorA2, LOW);
  digitalWrite(pinoMotorB1, HIGH);
  digitalWrite(pinoMotorB2, LOW);

  // Ajusta a velocidade do motor
  analogWrite(pinoHabilitarA, velocidade_motor_A);
  analogWrite(pinoHabilitarB, velocidade_motor_B);
}

void virarParaDireita() {
  // Gira para a direita
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, HIGH);
  analogWrite(pinoHabilitarA, velocidade_virar_Para_Direita);  // Reduz a velocidade para facilitar a curva
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, LOW);
  // Modificar se necessário
}


void virarParaDireitaProprioeixo() {
  // Gira para a direita no proprio eixo
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, HIGH);
  analogWrite(pinoHabilitarA, velocidade_virar_Para_Direita_A);  // Reduz a velocidade para facilitar a curva
  digitalWrite(pinoMotorB1, HIGH);
  digitalWrite(pinoMotorB2, LOW);
  analogWrite(pinoHabilitarB, velocidade_virar_Para_Direita_B);  // Reduz a velocidade para facilitar a curva

  // Modificar se necessário
}

void virarParaEsquerda() {
  // Gira para a direita
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, HIGH);
  analogWrite(pinoHabilitarB, velocidade_virar_Para_Esquerda);  // Reduz a velocidade para facilitar a curva
  digitalWrite(pinoMotorA1, LOW);
  digitalWrite(pinoMotorA2, LOW);

  // Modificar se necessário
}
void virarParaEsquerdaProprioeixo() {
  // Gira para a direita
  digitalWrite(pinoMotorB1, LOW);
  digitalWrite(pinoMotorB2, HIGH);
  analogWrite(pinoHabilitarB, velocidade_virar_Para_Esquerda_B);  // Reduz a velocidade para facilitar a curva
  digitalWrite(pinoMotorA1, HIGH);
  digitalWrite(pinoMotorA2, LOW);
  analogWrite(pinoHabilitarA, velocidade_virar_Para_Esquerda_A);  // Reduz a velocidade para facilitar a curva

  // Modificar se necessário
}

int medirDistancia(int pinoTrigger, int pinoEcho) {
  // Gera um pulso curto para o sensor ultrassônico
  digitalWrite(pinoTrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrigger, LOW);

  // Lê a duração do pulso eco
  long duracao = pulseIn(pinoEcho, HIGH);

  // Converte a duração em distância
  int distancia = duracao/58;  // A velocidade do som é 34 cm/ms

  return distancia;
}

void loop() {

  // Mede a distância com o sensor ultrassônico
  int distancia = medirDistancia(pinoTrigger, pinoEcho);
  Serial.print(distancia);

  if (digitalRead(pinoSensorCentro) == LOW) {
    ParardeMover();
    moverParaTras();
    delay(1000);

    virarParaEsquerda();
  } else {
    if (distancia > 0 && distancia <= 30) {  // Ajuste conforme necessário para a sua situação
      // Se o objeto estiver detectado pelo sensor ultrassônico
      // vá em frente para "derrubá-lo"
      atacar();
    } else {
      virarParaDireitaProprioeixo();
    }
  }
}
/*void loop() {
  // Mede a distância com o sensor ultrassônico
  int distancia = medirDistancia(pinoTrigger, pinoEcho);

  if ( digitalRead(pinoSensorCentro) == LOW) {
    // Se a borda for detectada, recua e vira
    ParardeMover();
    moverParaTras();
    delay(500); // Ajuste o tempo conforme necessário
    virarParaEsquerdaProprioeixo();
    delay(500); // Ajuste o tempo conforme necessário
  } else if (distancia > 0 && distancia <= 30) {
    // Se o adversário for detectado a menos de 30 cm, atacar
    atacar();
  } else {
    // Caso contrário, mover para frente
    moverParaFrente();
  }
}
*/