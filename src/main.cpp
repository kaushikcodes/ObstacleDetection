#include <Arduino.h>
#include <NewPing.h>

const int trigPin = 5;
const int echoPin = 18;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

long duration;
float distanceCm;
float distanceInch;
uint16_t count = 0;


void setup() {
    Serial.begin(115200); // Starts the serial communication
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
    delay(500);

    unsigned int uS = sonar.ping();

    pinMode(echoPin, OUTPUT);
    digitalWrite(echoPin,LOW);
    pinMode(echoPin, INPUT);

    Serial.print("Ping: ");
    Serial.print(uS / US_ROUNDTRIP_CM);

    if((uS / US_ROUNDTRIP_CM) < 3){
        count = count + 1;
    }

    if(count > 3){
        Serial.println("Obstacle nearing, BRAKE!!!!");
        count = 0;
    }

    Serial.println("cm");
}
