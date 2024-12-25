# Portable Oscilloscope with ESP32



A portable oscilloscope based on the ESP32 microcontroller, enhanced with additional features for improved usability and functionality.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Circuit Diagram and Connections](#circuit-diagram-and-connections)
- [Simulation](#simulation)
- [Setup and Installation](#setup-and-installation)
- [Usage](#usage)
- [CAD and designs](#CAD-and-designs)
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
  - Connect the common pin (C) to **GND**.
  - Connect one side (Position 1) to **GPIO 2** on the ESP32.
  - Connect the other side (Position 2) to ***GPIO 32** on the ESP32.

- **Probe 2 Switch**:
  - Connect the common pin (C) to **GND**.
  - Connect one side (Position 1) to **GPIO 4** on the ESP32.
  - Connect the other side (Position 2) to ***GPIO 35** on the ESP32.

These switches allow you to change the probe settings without using the web interface.


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

## Setup and Installation

Follow these instructions to set up and install the Portable Oscilloscope on your ESP32.

### 1. Copy Files to Project Directory

Copy all files from this package to the `Esp32_oscilloscope` directory on your computer.

### 2. Open the Project in Arduino IDE

- Open `Esp32_oscilloscope.ino` with the Arduino IDE.

### 3. Configure Wi-Fi Settings

- Find and open the `Esp32_servers_config.h` file.
- Locate the following lines:

  ```cpp
  #define STA_SSID "YOUR-STA-SSID"
  #define STA_PASSWORD "YOUR-STA-PASSWORD"
  ```

- Replace `"YOUR-STA-SSID"` with your Wi-Fi network's SSID.
- Replace `"YOUR-STA-PASSWORD"` with your Wi-Fi network's password.

### 4. Select Partition Scheme

The oscilloscope uses the LittleFS file system, so you need to select an appropriate partition scheme.

- In the Arduino IDE, go to **Tools** > **Partition Scheme**.
- Select one of the **SPIFFS** partition schemes (e.g., **"Default 4MB with spiffs (1.2MB APP/1.5MB SPIFFS)"**).

### 5. Adjust for Boards Without Flash Disk (Optional)

Some ESP32 boards do not have a flash disk. If your board lacks flash storage:

- Open `Esp32_servers_config.h`.
- Comment out the line:

  ```cpp
  #define FILE_SYSTEM FILE_SYSTEM_LITTLEFS
  ```

- This will make the oscilloscope use program memory (progmem) instead of the file system to store the `oscilloscope.html` file.

### 6. Compile and Upload the Sketch

- Compile the sketch by clicking the **Verify** button in the Arduino IDE.
- Upload the sketch to your ESP32 by clicking the **Upload** button.

### 7. Format the LittleFS File System

- When you run the sketch on your ESP32 for the first time, it will format the flash disk with the LittleFS file system.
- **Warning**: This will erase all data previously stored in the ESP32's flash memory.

### 8. Upload HTML and Image Files via FTP

To serve the web interface and icons, upload the required files to the ESP32:

#### Required Files:

- `oscilloscope.html`
- `android-192-osc.png`
- `apple-180-osc.png`

#### Steps:

1. **Connect to ESP32 via FTP**:

   - You can use the command-line FTP utility or a GUI FTP client like FileZilla.
   - No username or password is required.

2. **FTP Command-Line Example**:

   ```bash
   ftp YOUR-ESP32-IP
   ```

   Replace `YOUR-ESP32-IP` with the IP address of your ESP32 (e.g., `192.168.1.100`).

3. **Upload Files to `/var/www/html` Directory**:

   ```bash
   ftp> put android-192-osc.png /var/www/html/android-192-osc.png
   ftp> put apple-180-osc.png /var/www/html/apple-180-osc.png
   ftp> put oscilloscope.html /var/www/html/oscilloscope.html
   ```

   **Example Session**:

   ```
   C:\esp32_oscilloscope>ftp YOUR-ESP32-IP
   Connected to 192.168.1.100.
   220-ESP32 FTP server - everyone is allowed to login
   User (192.168.1.100:(none)):
   331 enter password
   Password:
   230 logged on, use "/" to refer to your home directory "/"
   ftp> put android-192-osc.png /var/www/html/android-192-osc.png
   226 /var/www/html/android-192-osc.png transfer complete
   ftp> put apple-180-osc.png /var/www/html/apple-180-osc.png
   226 /var/www/html/apple-180-osc.png transfer complete
   ftp> put oscilloscope.html /var/www/html/oscilloscope.html
   226 /var/www/html/oscilloscope.html transfer complete
   ftp> bye
   ```

4. **Using Windows Explorer (Optional)**:

   - Open Windows Explorer.
   - Enter `ftp://YOUR-ESP32-IP` in the address bar.
   - Copy the files into the `/var/www/html` directory.

### 9. Access the Oscilloscope Web Interface

- Open a web browser on your computer or smartphone.
- Navigate to `http://YOUR-ESP32-IP/oscilloscope.html`.
- Replace `YOUR-ESP32-IP` with the actual IP address of your ESP32.
- The oscilloscope interface should load, and you can start using it.

## Usage

1. **Power On the Device**:

   - Connect the ESP32 to a power source (USB cable connected to a computer or a battery pack).

2. **Connect to Wi-Fi**:

   - The ESP32 will initialize and connect to your specified Wi-Fi network.
   - The OLED display will show a QR code and the IP address.

3. **Access the Web Interface**:

   - Scan the QR code with your smartphone, or enter the IP address into a web browser.
   - The oscilloscope interface will load, displaying real-time waveform data.

4. **Using the Oscilloscope**:

   - **Connect Probes**:
     - Attach the probes to the signals you wish to analyze.
   - **Adjust Probe Settings**:
     - Use the **3-way switches** to select probe modes (e.g., attenuation, coupling).
   - **Interact with Web Interface**:
     - Adjust time base, trigger settings, voltage scale, and other parameters through the web interface.
   - **Start/Stop Acquisition**:
     - Use on-screen controls to start or stop signal acquisition.

5. **Diagnostics and Troubleshooting**:

   - **No Waveform Displayed**:
     - Check probe connections and ensure they are properly attached to the signal source.
     - Verify that the switches are in the correct positions.
   - **Network Issues**:
     - Ensure that the ESP32 is connected to the correct Wi-Fi network.
     - Check the OLED display for the IP address and ensure your device is on the same network.

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
- **Wokwi Community**: For providing the simulation platform and resources.
- **Open Source Community**: For libraries and tools that have made this project possible.

## CAD and designs
The project includes cad and stl files to be used as a casing for the deivce 

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

Feel free to contribute to this project by submitting issues or pull requests. Your feedback and improvements are greatly appreciated!

# Additional Information

If you have any questions or need assistance with setting up or modifying the oscilloscope, please don't hesitate to reach out via the project's issue tracker on GitHub.

---

**Note**: Always exercise caution when working with electronic components and circuits. Ensure that all power sources are appropriate for your project to prevent damage to components or injury.

---

Happy tinkering!

# Troubleshooting

If you encounter issues during setup or usage, consider the following tips:

- **Compilation Errors**:
  - Ensure all required libraries are installed and up to date.
  - Double-check that the correct board and partition scheme are selected.

- **FTP Connection Problems**:
  - Verify that the ESP32 is connected to the Wi-Fi network.
  - Make sure you are using the correct IP address.
  - Check firewall settings that might block FTP connections.

- **Files Not Serving Correctly**:
  - Ensure that the files are uploaded to the correct directory (`/var/www/html`).
  - Confirm that the filenames are correct and match those referenced in the code.

- **OLED Display Not Working**:
  - Check the wiring connections between the OLED display and the ESP32.
  - Ensure that the I2C address in the code matches your OLED display's address.

# Conclusion

By following these instructions, you should have a fully functional portable oscilloscope based on the ESP32 microcontroller. This project not only provides practical functionality but also offers an opportunity to learn and experiment with microcontrollers, networking, and web technologies.
