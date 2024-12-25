# Portable Oscilloscope with ESP32

A portable oscilloscope based on the ESP32 microcontroller, enhanced with additional features for improved usability and functionality.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
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

## Installation

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/yourusername/Portable_Oscilloscope.git
   ```

2. **Install the ESP32 Board in Arduino IDE**:
   - Follow the instructions to install ESP32 support in your Arduino IDE if not already installed.

3. **Install Required Libraries**:
   - Install the necessary libraries for the OLED display and any other dependencies.

4. **Upload the Code**:
   - Open the `Portable_Oscilloscope.ino` file in Arduino IDE.
   - Configure your Wi-Fi credentials in the code if using in client mode.
   - Upload the code to your ESP32 board.

5. **Assemble the Hardware**:
   - Connect the OLED display to the ESP32 as per the wiring diagram.
   - Attach the probes and **3-way switches** accordingly.
   - Ensure all connections are secure.

## Usage

1. **Power On the Device**:
   - Connect the ESP32 to a power source (USB or battery pack).

2. **Connect to Wi-Fi**:
   - The device will create a Wi-Fi access point or connect to your specified network.
   - On the OLED display, a QR code will be displayed.

3. **Access the Web Interface**:
   - Scan the QR code with your smartphone or navigate to the IP address displayed.
   - The updated web interface should load on your browser.

4. **Using the Oscilloscope**:
   - Connect the probes to the signal you wish to analyze.
   - Use the **3-way switches** to adjust probe settings as needed.
   - View real-time waveforms and adjust settings through the web interface.

## Modifications and Enhancements

This project includes several key modifications from the original:

1. **Updated HTML File**:
   - The web interface has been improved for better usability.
   - New features and controls have been added to enhance functionality.

2. **OLED Display with QR Codes**:
   - An OLED display has been integrated to show the device status.
   - Displays a QR code for quick access to the oscilloscope interface.
   - Provides visual feedback without the need for additional devices.

3. **Special 3-Way Switches for Probe Control**:
   - Physical **3-way switches** have been added to control the probes.
   - Allows for immediate and precise adjustments without navigating the web interface.
   - Enhances the user experience during hands-on diagnostics.

## Acknowledgements

- **BojanJurca**: Original creator of the [Esp32_oscilloscope](https://github.com/BojanJurca/Esp32_oscilloscope).
- **Open Source Community**: For providing libraries and resources that made this project possible.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
