const int irPin = A0; // Analog pin for IR sensor input
float voltage; // Variable to store sensor voltage
float glucose; // Variable for calculated glucose
const int numReadings = 10; // Number of readings for calculating mean and SD
float readings[numReadings]; // Array to store glucose readings
int index = 0; // Index for the array
float sum = 0; // Sum of readings
float mean; // Mean of glucose readings
float standardDeviation; // Standard deviation of glucose readings
void setup() {
Serial.begin(9600); // Initialize serial monitor for debugging
for (int i = 0; i < numReadings; i++) {
readings[i] = 0; // Initialize readings array with zeros
}
}
void loop() {
// Read voltage from IR sensor
int sensorValue = analogRead(irPin);
voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
// If no finger is detected, set glucose to 0
if (sensorValue < 10) { // Adjust threshold as needed for no-finger detection
glucose = 0;
} else {
// Map voltage to glucose level (example calibration)
glucose = mapGlucose(voltage);
// Add new reading to the array and update sum
sum -= readings[index];
readings[index] = glucose;
sum += readings[index];
index = (index + 1) % numReadings;
// Calculate mean
mean = sum / numReadings;
// Calculate standard deviation
float sumSquares = 0;
for (int i = 0; i < numReadings; i++) {

sumSquares += pow(readings[i] - mean, 2);
}
standardDeviation = sqrt(sumSquares / numReadings);
}
// Output results to Serial Monitor
Serial.print("Voltage: ");
Serial.print(voltage);
Serial.print(" V, Glucose: ");
Serial.print(glucose);
Serial.print(" mg/dL, Mean BGL: ");
Serial.print(mean);
Serial.print(" mg/dL, SD: ");
Serial.println(standardDeviation);
delay(2000); // Update every 2 seconds
}
// Function to map voltage to glucose level
float mapGlucose(float voltage) {
// Calibration: Adjust equation based on testing data
// Example: glucose = voltage * conversion factor + offset
if (voltage <= 1.5) return voltage * 70; // Hypothetical factor
else if (voltage <= 2.5) return voltage * 80; // Higher voltage range
else return voltage * 90;
}
