const int irPin = A0; // Analog pin for IR sensor input
float voltage; // Variable to store sensor voltage
float transmittedIntensity; // Intensity of transmitted light
float receivedIntensity; // Intensity of received light (converted from voltage)
float absorbance; // Calculated absorbance using Beer-Lambert Law
float glucose; // Variable for calculated glucose
const float pathLength = 1.0; // Path length through the finger (in cm), adjust as needed
const float molarAbsorptivity = 0.01; // Hypothetical molar absorptivity constant for
glucose, adjust as needed

void setup() {
Serial.begin(9600); // Initialize serial monitor for debugging
}
void loop() {
// Read voltage from IR sensor
int sensorValue = analogRead(irPin); voltage = sensorValue * (5.0 / 1023.0); // Convert
sensor value to voltage
// Check if a finger is detected
if (sensorValue < 10) {
// Adjust threshold as needed for no-finger detection
Serial.println("No finger detected.");
delay(2000);
return;
}
// Map voltage to intensity of received light (arbitrary unit
conversion)
receivedIntensity = voltage; // Assume receivedIntensity is
proportional to voltage for simplicity
// Assume transmittedIntensity is a fixed value when no finger is
present (baseline intensity)
transmittedIntensity = 5.0; // Set a fixed value for transmitted
intensity (arbitrary units)
// Calculate absorbance using Beer-Lambert Law: A = -
log10(I_received / I_transmitted)
if (receivedIntensity > 0) {
absorbance = -log10(receivedIntensity / transmittedIntensity);
}
else {
absorbance = 0;
}

// Calculate glucose concentration using absorbance
if (absorbance > 0) {
glucose = absorbance / (molarAbsorptivity * pathLength);
}
else {
glucose = 0; // No glucose detected if absorbance is zero
}
// Output results to Serial Monitor
Serial.print("Voltage: ");
Serial.print(voltage);
Serial.print(" V, Absorbance: ");
Serial.print(absorbance);
Serial.print(", Glucose: ");
Serial.print(glucose);
Serial.println(" mg/dL");
delay(2000); // Update every 2 seconds
}
