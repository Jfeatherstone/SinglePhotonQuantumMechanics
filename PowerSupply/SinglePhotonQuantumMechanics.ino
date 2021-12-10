

// We have a whole bunch of input and output pins
const int PUSH_BUTTON_PIN = 2;
const int TOGGLE_SWITCH_PIN = 3;
const int SOUND_TOGGLE_PIN = 1;

const int BLUE_LED_PIN = 8;
const int GREEN_LED_PIN = 9;
const int LIGHT_GREEN_LED_PIN = 10;

const int PHOTORES_1_PIN = A1;
const int PHOTORES_2_PIN = A2;

const int RELAY_PINS[4] = {4, 5, 6, 7};

const int LIGHT_LEVEL_POT_PIN = A0;
// The maximum and minimum value of potentiometer
const int LIGHT_LEVEL_POT_MAX = 100000;
const int LIGHT_LEVEL_POT_MIN = 50000;
const float LIGHT_LEVEL_BASE_CUTOFF = 25;

// State variables

bool currentlyPowered = false; // Powered (true) vs. standby (false)
bool LEDMode = true; // LED (true) vs. sound (false)
bool canBePowered = false;

// Amount of time to not register a another button press (ms)
int buttonDeadTime = 400;
// The timestamp of the last button press (ms)
int lastButtonPressTS = 0;

void setup() {
  // Debugging 
  Serial.begin(9600);

  // Pin mode initialization
  // The pullup part clamps the output unless it is at full reading
  pinMode(PUSH_BUTTON_PIN, INPUT_PULLUP);
  pinMode(TOGGLE_SWITCH_PIN, INPUT_PULLUP);
  
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(LIGHT_GREEN_LED_PIN, OUTPUT);

  pinMode(PHOTORES_1_PIN, INPUT);
  pinMode(PHOTORES_2_PIN, INPUT);
  pinMode(LIGHT_LEVEL_POT_PIN, INPUT);

  for (int i = 0; i < 4; i++) {
    pinMode(RELAY_PINS[i], OUTPUT);
  }

}

void toggleSound() {
  pinMode(SOUND_TOGGLE_PIN, OUTPUT);
  delay(300);
  pinMode(SOUND_TOGGLE_PIN, INPUT);
}

void loop() {

  //digitalWrite(SOUND_TOGGLE_PIN, HIGH);
  
  int currentTime = millis();

  // Update the various state variables based on switch status
  bool pushButtonPressed = !digitalRead(PUSH_BUTTON_PIN);
  bool toggleSwitchState = digitalRead(TOGGLE_SWITCH_PIN);
  bool attemptPowerSwitch = false;
  
  if (pushButtonPressed && currentTime > lastButtonPressTS + buttonDeadTime) {
    attemptPowerSwitch = true;
  }

  // Read in the current photoresistor values
  float photoRes1 = analogRead(PHOTORES_1_PIN);
  float photoRes2 = analogRead(PHOTORES_2_PIN);

  float potAdjustment = analogRead(LIGHT_LEVEL_POT_PIN) / 1023.0f + .2;

  //Serial.println(analogRead(LIGHT_LEVEL_POT_PIN));

  float adjustedLightLevelCutoff = LIGHT_LEVEL_BASE_CUTOFF * potAdjustment;
  
  Serial.println(String(photoRes1) + "," + String(photoRes2) + "," + String(adjustedLightLevelCutoff));

  if (photoRes1 < adjustedLightLevelCutoff && photoRes2 < adjustedLightLevelCutoff) {
    canBePowered = true;
  } else {
    canBePowered = false;
  }

  if (attemptPowerSwitch) {
      lastButtonPressTS = currentTime;
    // If the power is currently on, it can always be turned off
    if (currentlyPowered) {
      currentlyPowered = false;
    } else {
      // If the power is off, we have to check if we can turn the power on
      if (canBePowered) {
        currentlyPowered = true;
      }
    }
  }
//  digitalWrite(2, HIGH);
//  digitalWrite(LED_BUILTIN, HIGH);
//  delay(500);
//  pinMode(1, INPUT);
//  digitalWrite(2, LOW);
//  delay(1000);
  //digitalWrite(1, HIGH);
  //Serial.println(digitalRead(TOGGLE_SWITCH_PIN));

  // Regardless of the state, we always cut power if necessary
  if (!canBePowered) {
    currentlyPowered = false;
    // TODO
    lastButtonPressTS = currentTime;
  }

  ///////////////////////////////////////
  ///////////////////////////////////////
  // Below this is now just updating the state of the physical
  // hardware; no more changes to state variables are made

  //Serial.println(String(pushButtonPressed) + "," + String(attemptPowerSwitch) + "," + String(canBePowered) + "," + String(currentlyPowered));

  // Open/close the relay gates
  for (int i = 0; i < 4; i++) {
    digitalWrite(RELAY_PINS[i], currentlyPowered ? LOW : HIGH);
  }

  // Update LED indicator
  if (currentlyPowered) {
    // Green indicator
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(LIGHT_GREEN_LED_PIN, HIGH);
    digitalWrite(GREEN_LED_PIN, HIGH);
  } else {
    // If we can be powered we do teal
    if (canBePowered) {
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
      digitalWrite(LIGHT_GREEN_LED_PIN, HIGH);
    } else {
      // Otherwise blue
      digitalWrite(GREEN_LED_PIN, LOW);
      digitalWrite(BLUE_LED_PIN, HIGH);
      digitalWrite(LIGHT_GREEN_LED_PIN, LOW);
    }
    
  }

}
