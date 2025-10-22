#define LED_AZUL 12
#define LED_AMARELA 13

bool estadoSistema = false;
int espacamento = 100; // Define o espacamento inicial como sendo 100ms

void setup() {
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_AMARELA, OUTPUT);
}

// Função para atualizar os LEDs
void atualizaLeds() {
  if (estadoSistema) {
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELA, LOW);
  } else {
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELA, HIGH);
  }
}

// Classe Sistema
class Sistema {
  public:
    void alternarEstado() { // Função para alternar o estado dos LEDs
      estadoSistema = !estadoSistema;
      atualizaLeds();
    }
};

Sistema sistema;

void loop() {
  sistema.alternarEstado(); // Alterna o estado
  delay(espacamento); // Espera uma quantidade de tempo igual a "espacamento"
  espacamento = espacamento + (espacamento/10); // Redefine espacamento como ele mesmo + um décimo de seu valor
}
