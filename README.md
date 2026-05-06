# Adaptive Sampling Based Digital Communication System

## 📌 Project Overview
This project implements an efficient end-to-end communication system designed to transmit analog signals with high integrity while significantly reducing data redundancy. Conventional uniform sampling often leads to excessive data transmission when a signal is relatively constant. This system utilizes an **Adaptive Sampling algorithm** that dynamically adjusts the sampling frequency based on the signal's slope (rate of change).

The architecture features a dual-microcontroller setup using **Arduino Uno** boards connected via a **UART digital link**, achieving over **50% data reduction** in simulations and hardware tests.

## 🚀 Key Features
* **Bandwidth Optimization:** Achieved a **50.5% reduction** in total transmitted samples by using event-based logic.
* **Digital Noise Immunity:** Uses a UART serial link to eliminate the electrical interference common in long-distance analog signal lines.
* **Hardware Reconstruction:** Employs a physical **RC Low-Pass Filter** to reconstruct smooth analog signals from PWM outputs.
* **Real-time Visualization:** Integrated I2C-enabled 16x2 LCD for live monitoring of transmitted values.

## 🛠️ System Architecture
The system is divided into two primary nodes:
1.  **Transmitter Node:** * Monitors an analog input (10kΩ Potentiometer).
    * Implements a threshold-based adaptive algorithm.
    * Only transmits data if **current value - last sent value > threshold**
2.  **Receiver Node:** * Decodes the digital UART packets.
    * Updates the I2C LCD display.
    * Generates a PWM signal that is converted back to analog via an RC filter (1Kohm resistor + 1uF capacitor)
    * 

## 📊 Performance Analysis
The system's performance was validated by comparing the adaptive sampling output against a standard uniform sampling rate.

### 1. Data Reduction Efficiency
Based on the Scilab simulations and hardware testing:
* **Uniform Sampling:** 101 samples required for a standard signal period.
* **Adaptive Sampling:** ~50 samples required for the same period.
* **Total Bandwidth Saved:** **50.5%**

### 2. Serial Plotter Verification
Real-time testing was conducted using the **Arduino Serial Plotter** to verify the event-based logic:
* **Observation:** The plotter shows data "spikes" or transmission pulses only when the input slope exceeds the pre-defined threshold.
* **Stability:** When the input is stationary, the transmission stops completely, demonstrating zero redundant data usage and effective noise rejection.

### 3. Signal Reconstruction
Despite the 50% reduction in data, the hardware **RC Low-Pass Filter** successfully smoothed the PWM steps into a continuous analog waveform. This proves that "Sampling on Demand" maintains high signal fidelity while saving significant resources.


## 📄 Full Documentation
For the complete mathematical analysis and simulation results, view the report here:
👉 [Adaptive_Sampling_based_Digital_Communication_Report.pdf](./Adaptive_Sampling_based_Digital_Communication_Report.pdf)
