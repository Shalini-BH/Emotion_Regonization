const int pulsePin = A0;  // Pulse sensor analog pin
const int ledPin = 13;   // LED pin for visual indication

const int numSamples = 10;   // Number of pulse samples to average
int samples[numSamples];     // Array to store pulse samples
int pulseCount = 0;          // Number of pulses counted
float pulseRate = 0;         // Calculated pulse rate in beats per minute (BPM)
float averageBPM = 0;        // Average BPM value

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read pulse samples
  for (int i = 0; i < numSamples; i++) {
    samples[i] = analogRead(pulsePin);
    delay(10);
  }

  // Calculate average pulse rate
  pulseCount = 0;
  for (int i = 0; i < numSamples; i++) {
    pulseCount += samples[i];
  }
  pulseRate = pulseCount / numSamples;

  // Convert pulse rate to beats per minute (BPM)
  averageBPM = map(pulseRate, 0, 1023, 0, 150);

  if(averageBPM<70){
    Serial.print("sad   ");
  }
  else if(averageBPM<80){
    Serial.print("Fear   ");
  }
  else if(averageBPM<90){
    Serial.print("Angry   ");
  }
  else if(averageBPM<100){
    Serial.print("Happy   ");
  }
  else{
    Serial.print("Surprise   ");
  }
  // Print pulse rate in BPM
  Serial.print("Pulse Rate (BPM): ");
  Serial.println(averageBPM);

  // Display pulse rate using LED
  flashLED(averageBPM);

  delay(1000);  // Adjust delay as needed
}

void flashLED(float bpm) {
  int delayTime = 60000 / bpm;  // Calculate delay time based on BPM

  digitalWrite(ledPin, HIGH);
  delay(delayTime / 2);
  digitalWrite(ledPin, LOW);
  delay(delayTime / 2);
}
