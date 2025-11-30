#System Architecture#
1. Optical Layer: IR LED (transmit) + IR photodiode (receive).
2. Analog Conditioning: LM358 amplification + passive filtering.
3. Digital Layer: Arduino ADC sampling, finger-detection logic, Beer-Lambert absorbance.
4. Algorithm Layer:
  Voltage → Intensity mapping
  Absorbance = –log10(I_received / I_transmitted)
  Glucose = f(absorbance) via calibration models
5. Output Layer: Serial monitor + optional Python plotting.

#Flow of Hardware:#
IR LED → Finger Tissue → Photodiode → LM358 Amplifier → Filter → Arduino A0 → Absorbance/Glucose Calculation → Serial Output.
