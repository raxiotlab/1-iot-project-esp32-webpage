# ESP32 LED Web Controller

This project demonstrates how to control an LED connected to an ESP32 board through an external web interface. The ESP32 connects to Wi-Fi and receives commands from a webpage hosted on an external server, allowing the user to turn the LED on or off remotely.

## Features
- Control an LED remotely from any browser  
- External webpage (HTML, CSS, JS) communicates with ESP32  
- ESP32 receives HTTP requests and updates LED state  
- Lightweight and easy to understand project for beginners in IoT  

## Files
- **sketch_oct27a.ino** → ESP32 firmware (Arduino code)  
- **main.html** → Webpage layout  
- **style.css** → Webpage styling  
- **main.js** → JavaScript logic to send HTTP requests to ESP32  

## Requirements
- ESP32 development board  
- Arduino IDE installed  
- Wi-Fi connection  
- External web hosting (can be GitHub Pages, Netlify, or any basic web server)  
- USB cable  

## How to Use
1. Upload **sketch_oct27a.ino** to your ESP32 using Arduino IDE.  
2. Set your Wi-Fi SSID and password in the code.  
3. Note the ESP32’s local IP address from the Serial Monitor.  
4. Host the webpage files (**main.html**, **style.css**, and **main.js**) on your external web server.  
5. In **main.js**, update the ESP32 IP address so the webpage can send requests to it.  
6. Open the hosted webpage and control the LED from anywhere on your network.  

## License
This project is open-source and free to use for educational purposes.
