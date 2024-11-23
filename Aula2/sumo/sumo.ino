// Definindo os pinos do motor na Ponte H
const int pinoMotorA1 = 7;    // Pino de controle 1 para motor A
const int pinoMotorA2 = 8;    // Pino de controle 2 para motor A
const int pinoHabilitarA = 9; // Pino de controle de velocidade para motor A
const int pinoMotorB1 = 11;    // Pino de controle 1 para motor B
const int pinoMotorB2 = 12;    // Pino de controle 2 para motor B
const int pinoHabilitarB = 10; // Pino de controle de velocidade para motor B

// Definindo os pinos dos sensores reflexivos
const int pinoSensorEsquerda = 6; // Pino do sensor reflexivo esquerdo
const int pinoSensorCentro = 5;   // Pino do sensor reflexivo central
const int pinoSensorDireita = 4;  // Pino do sensor reflexivo direito

void setup()
{
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
}
void moverParaFrente()
{
    // Define a direção do motor para frente
    digitalWrite(pinoMotorA1, LOW);
    digitalWrite(pinoMotorA2, HIGH);
    digitalWrite(pinoMotorB1, LOW);
    digitalWrite(pinoMotorB2, HIGH);

    // Ajusta a velocidade do motor
    analogWrite(pinoHabilitarA, 50); // 255 é a velocidade máxima
    analogWrite(pinoHabilitarB, 66); // 255 é a velocidade máxima
}

void ParardeMover()
{
    // Define a direção do motor para frente
    digitalWrite(pinoMotorA1, LOW);
    digitalWrite(pinoMotorA2, LOW);
    digitalWrite(pinoMotorB1, LOW);
    digitalWrite(pinoMotorB2, LOW);
}

void moverParaTras()
{
    // Define a direção do motor para trás
    digitalWrite(pinoMotorA1, HIGH);
    digitalWrite(pinoMotorA2, LOW);
    digitalWrite(pinoMotorB1, HIGH);
    digitalWrite(pinoMotorB2, LOW);

    // Ajusta a velocidade do motor
    analogWrite(pinoHabilitarA, 50);
    analogWrite(pinoHabilitarB, 66);
}

void virarParaDireita()
{
    // Gira para a direita
    digitalWrite(pinoMotorA1, LOW);
    digitalWrite(pinoMotorA2, HIGH);
    analogWrite(pinoHabilitarA, 75); // Reduz a velocidade para facilitar a curva
    digitalWrite(pinoMotorB1, LOW);
    digitalWrite(pinoMotorB2, LOW);
    delay(1000);
}

void virarParaEsquerda()
{
    // Gira para a direita
    digitalWrite(pinoMotorB1, LOW);
    digitalWrite(pinoMotorB2, HIGH);
    analogWrite(pinoHabilitarB, 75); // Reduz a velocidade para facilitar a curva
    digitalWrite(pinoMotorA1, LOW);
    digitalWrite(pinoMotorA2, LOW);

    delay(1000);
}

void loop()
{

    if(digitalRead(pinoSensorCentro) == LOW){
    ParardeMover();
    delay(500);
    moverParaTras();
    delay(1000);

    virarParaDireita();
    }
    else if(digitalRead(pinoSensorCentro) == HIGH)
    {
        // Nenhuma condição especial, vá em frente
        moverParaFrente();
    }
}