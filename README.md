# Portable Oscilloscope with ESP32



A portable oscilloscope based on the ESP32 microcontroller, enhanced with additional features for improved usability and functionality.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram and Connections](#circuit-diagram-and-connections)
- [Simulation](#simulation)
- [Installation](#installation)
- [Usage](#usage)
- [Modifications and Enhancements](#modifications-and-enhancements)
- [Acknowledgements](#acknowledgements)
- [License](#license)

## Introduction

This project is a portable oscilloscope built using the ESP32 microcontroller. It is a modification of the original [Esp32_oscilloscope by BojanJurca](https://github.com/BojanJurca/Esp32_oscilloscope). The oscilloscope interfaces with a web browser via Wi-Fi, providing a convenient and accessible way to visualize analog signals.

## Features

- **Wi-Fi Connectivity**: Access the oscilloscope interface through any web browser without the need for additional software.
- **OLED Display with QR Code**: An onboard OLED display shows a QR code for easy access to the oscilloscope web interface.
- **Probe Control via 3-Way Switches**: Special 3-way switches have been added to control probe usage, allowing for quick and precise adjustments.
- **Updated Web Interface**: The HTML interface has been updated for better user experience and functionality.
- **Portable Design**: Compact and portable, suitable for fieldwork and on-the-go diagnostics.

## Hardware Requirements

- **ESP32 Development Board**
- **OLED Display Module** (128x64 pixels recommended)
- **Analog Probes**
- **3-Way Switches** for probe control
- **Battery Pack** (optional, for portable power)
- **Additional Components**:
  - Breadboard or custom PCB
  - Connecting wires and jumpers
  - Enclosure (optional, for portability and protection)

## Circuit Diagram and Connections

### Circuit Diagram

A schematic of the circuit connections is essential for assembling the oscilloscope. The circuit diagram can be found below:



*(If you're viewing this document on GitHub, you can find the circuit diagram image in the `images` folder. If the image is not available, refer to the connection details provided.)*

### Connection Details

#### OLED Display Connections (I2C Interface)

| OLED Pin | ESP32 Pin |
|----------|-----------|
| VCC      | 3.3V      |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

#### 3-Way Switches for Probe Control

Assuming two probes, each with a 3-way switch:

- **Probe 1 Switch**:
  - Connect the common pin (C) to **GPIO 32** on the ESP32.
  - Connect one side (Position 1) to **3.3V**.
  - Connect the other side (Position 2) to **GND**.

- **Probe 2 Switch**:
  - Connect the common pin (C) to **GPIO 33** on the ESP32.
  - Connect one side (Position 1) to **3.3V**.
  - Connect the other side (Position 2) to **GND**.

These switches allow you to change the probe settings without using the web interface.

#### Analog Probe Connections

- **Probe 1**:
  - Signal wire to **GPIO 34** (Analog Input).
  - Ground wire to **GND**.

- **Probe 2**:
  - Signal wire to **GPIO 35** (Analog Input).
  - Ground wire to **GND**.

#### Additional Connections

- **Power Supply**:
  - The ESP32 can be powered via the USB port or an external battery pack connected to the VIN pin (ensure the voltage is appropriate).

## Simulation

To help you understand and test the oscilloscope without physical hardware, a simulation is available on Wokwi, an online electronics simulator.

### Wokwi Simulation Link

[**Portable Oscilloscope Simulation on Wokwi**](https://wokwi.com/projects/418253792702537729)

### Using the Simulation

- **Access the Simulation**: Click the link above to open the simulation in your web browser.
- **Interact with Components**: You can click on the components to see their properties and adjust parameters.
- **Run the Simulation**: Press the "Start Simulation" button to run the code and see the oscilloscope in action.
- **View the Serial Monitor**: Use the serial monitor within Wokwi to view debug messages or outputs.

### Benefits of Simulation

- **Test Code Changes**: Modify the code and instantly see the effects without hardware.
- **Visualize Connections**: Helps in understanding how components are connected.
- **Learning Tool**: Great for educational purposes to learn about microcontrollers and electronics.

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/Portable_Oscilloscope.git
   ```

2. **Install the ESP32 Board in Arduino IDE**:
   - Open the Arduino IDE.
   - Go to **File** > **Preferences**.
   - In **Additional Boards Manager URLs**, add:
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Go to **Tools** > **Board** > **Boards Manager**.
   - Search for **ESP32** and install **"esp32" by Espressif Systems**.

3. **Install Required Libraries**:
   - **Adafruit SSD1306**:
     - Go to **Tools** > **Manage Libraries**.
     - Search for **Adafruit SSD1306** and install it.
   - **Adafruit GFX Library**:
     - Search for **Adafruit GFX** and install it.
   - Install any other dependencies specified in the code.

4. **Upload the Code**:
   - Open `Portable_Oscilloscope.ino` in the Arduino IDE.
   - Configure your Wi-Fi credentials in the code if necessary.
   - Select your ESP32 board under **Tools** > **Board**.
   - Choose the correct **Port**.
   - Click **Upload** to flash the code to your ESP32.

5. **Assemble the Hardware**:
   - Refer to the [Circuit Diagram and Connections](#circuit-diagram-and-connections) section.
   - Carefully connect all components according to the diagram and connection details.
   - Double-check all connections before powering up the device.

## Usage

1. **Power On the Device**:
   - Connect the ESP32 to a power source (USB cable connected to a computer or a battery pack).

2. **Connect to Wi-Fi**:
   - The ESP32 will initialize and either create a Wi-Fi access point or connect to your network.
   - The OLED display will show a QR code and IP address.

3. **Access the Web Interface**:
   - Scan the QR code with your smartphone, or enter the IP address into a web browser.
   - The oscilloscope interface should load, displaying real-time waveform data.

4. **Using the Oscilloscope**:
   - Connect the probes to the signals you wish to analyze.
   - Use the **3-way switches** to adjust probe settings, such as voltage range or coupling mode.
   - Interact with the web interface to adjust time base, trigger settings, and other parameters.

5. **Diagnostics and Adjustments**:
   - If the waveform is not displayed correctly, check the probe connections and switch positions.
   - Ensure that the signal levels are within the acceptable range for the ESP32's ADC.

## Modifications and Enhancements

This project includes several key modifications from the original:

1. **Updated HTML File**:
   - Improved web interface with enhanced user experience.
   - Added controls for better interaction with the oscilloscope functions.

2. **OLED Display with QR Codes**:
   - Integrated OLED display provides immediate device status feedback.
   - Displays a QR code for quick and easy access to the web interface.
   - Eliminates the need to manually find the device's IP address.

3. **Special 3-Way Switches for Probe Control**:
   - Physical switches allow for rapid adjustments to probe settings.
   - Enhances usability during hands-on diagnostics without relying solely on the web interface.
   - Provides precise control over probe functions like attenuation and coupling.

## Acknowledgements

- **BojanJurca**: Original creator of the [Esp32_oscilloscope](https://github.com/BojanJurca/Esp32_oscilloscope).
- **Wokwi Community**: For providing the simulation platform and resources.
- **Open Source Community**: For libraries and tools that have made this project possible.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and improvements are greatly appreciated!

# Additional Information

If you have any questions or need assistance with setting up or modifying the oscilloscope, please don't hesitate to reach out via the project's issue tracker on GitHub.
