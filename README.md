<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/8f0f4fec01831f9f50ae640d9a76d6d8ca2264e1/welcomeScreens/elevatorEmulator.svg" style="width: 100%"></a>
</div>

<br>
<br>  

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7e25e7a877f6b5ad1166eaaa0aec52e9091b9627/headers/demo.svg" style="width: 100%"></a>
</div>

<br>

<div align="center" style="width: 100%;">
    <a href="https://youtu.be/i3VYq7fYbPA"><img src="https://github.com/BinaryQuBit/Readme-Setup/blob/main/gifs/elevatorEmulator.gif?raw=true" style="width: 100%">Final Product</a>
</div>

<br>
<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/99b7aa6f08701c8fcac3add942ac416b607ae2a4/headers/objective.svg" style="width: 100%"></a>
</div>

<br>

<p>
    The objective of this project is to develop a functional elevator emulator using the STM32F103RB microcontroller, leveraging RTOS on Keil uVision5 for efficient task management. The emulator will interface with a serial connection through PuTTY, visually representing the operation of a five-floor elevator system. It will accurately display time elapsed, current floor number, and operational status. The emulator will also respond to a comprehensive set of commands including up, down, select floor, open, close, emergency, and maintenance, providing a realistic simulation of elevator operations for testing and educational purposes.
</p>

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/99b7aa6f08701c8fcac3add942ac416b607ae2a4/headers/background.svg" style="width: 100%"></a>
</div>

<br>

<p>
    Elevators are a critical component in modern buildings, providing efficient vertical transportation for people and goods. Understanding the control systems and software that manage elevator operations is essential for engineers and developers working in the field of embedded systems and automation.
</p>

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/99b7aa6f08701c8fcac3add942ac416b607ae2a4/headers/intendedAudience.svg" style="width: 100%"></a>
</div>

<br>

- Embedded Systems Engineers
- Students and Educators
- Developers and Programmers
- Researchers
- Hobbyists and DIY Enthusiasts
- Industrial Automation Professionals

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/99b7aa6f08701c8fcac3add942ac416b607ae2a4/headers/focus.svg" style="width: 100%"></a>
</div>

<br>

- Real-Time Operating System (RTOS) Integration
- Microcontroller Programming
- Serial Communication and Interface
- Command Processing and System State Management
- User Interface and Visualization
- Educational and Practical Applications

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/626da83e39e3bc3f0359d0fb63a73a934c32f932/headers/assumptions%26Constraints.svg" style="width: 100%"></a>
</div>

### Assumptions:
- The STM32F103RB microcontroller and its necessary peripherals are assumed to be correctly configured and operational
- The RTOS is properly installed and configured on the Keil uVision5 development environment, with all required drivers and libraries integrated
- Users are expected to have a basic understanding of microcontroller programming, RTOS, and serial communication
- The serial connection between the microcontroller and PuTTY is assumed to be stable, with accurate data transmission and reception
- The elevator's status, including time elapsed, current floor number, and operational status, is accurately displayed and updated in real-time on PuTTY

### Constraints:
- Limited processing power and memory of the STM32F103RB microcontroller may restrict task complexity and number
- Requires a stable power supply to prevent unreliable operation or system resets
- Dependent on Keil uVision5, which may have compatibility issues with certain libraries or hardware components
- Text-based command interface through PuTTY can lead to human errors and limited user experience compared to graphical interfaces
- RTOS must efficiently handle real-time tasks; any delays or scheduling issues can affect the emulator’s accuracy and responsiveness

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7e25e7a877f6b5ad1166eaaa0aec52e9091b9627/headers/techStack.svg" style="width: 100%"></a>
</div>

<h3 align = "center">👩‍💻 Languages</h3>

<div align="center">

[![C](https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7831b9bf376caf17c9bf3ea09adba48a26525523/badges/languages/middle/c.svg)](https://www.cprogramming.com/)
[![C++](https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7831b9bf376caf17c9bf3ea09adba48a26525523/badges/languages/right/c++.svg)](https://www.cprogramming.com/)

</div>

<h2></h2>

<h3 align="center">🚀 Development Tools & Environments</h3>
<div align="center">

[![KEIL UVISION5](https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7831b9bf376caf17c9bf3ea09adba48a26525523/badges/developmentTools%26environments/left/keilUVision.svg)](https://www.keil.com/)
[![RTOS](https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7831b9bf376caf17c9bf3ea09adba48a26525523/badges/developmentTools%26environments/right/rtos.svg)](https://www.freertos.org/index.html)

</div>

<h2></h2>

<h3 align="center">⚙️ Hardware and Microcontroller Boards</h3>
<div align="center">

[![STM](https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7831b9bf376caf17c9bf3ea09adba48a26525523/badges/hardware%26Microcontrollers/middle/stm.svg)](https://www.st.com/content/st_com/en.html)

</div>

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/8f0f4fec01831f9f50ae640d9a76d6d8ca2264e1/headers/setup.svg" style="width: 100%"></a>
</div>

### Connect Microcontroller to the Computer:
- Connect the <a href="https://www.st.com/en/microcontrollers-microprocessors/stm32f103rb.html">STM32F103RB</a> microcontroller to your computer using a USB-to-Serial adapter or a USB cable

### Clone the Project:
- Clone the project repository
- Open the cloned project in <a href="https://www.keil.com/download/product/">Keil uVision5</a>

### Flash the Project
- Compile and flash the project onto the STM32F103RB microcontroller using Keil uVision5

### Open PuTTY:
- Launch <a href="https://www.putty.org/">PuTTY</a> and configure a new serial connection with the appropriate COM port and baud rate settings (115200)

### Connect and Enjoy:
- Connect to the serial port via PuTTY and start interacting with the elevator emulator
- Use the provided commands (up, down, select floor, open, close, emergency, maintenance) to control the elevator and monitor its status in real-time

<br>

<div style="width: 100%;">
  <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/626da83e39e3bc3f0359d0fb63a73a934c32f932/headers/result.svg" style="width: 100%"></a>
</div>

<br>

- Successful Serial Communication
- Real-Time Status Display
- Command Execution
- Smooth Operation
- Educational Insight

<br>

<div style="width: 100%;">
  <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/626da83e39e3bc3f0359d0fb63a73a934c32f932/headers/nextSteps.svg" style="width: 100%"></a>
</div>

<br>

- Feature Enhancements
- User Interface Improvements
- Error Handling and Safety Features
- Performance Optimization
- Documentation and Tutorials
- Testing and Validation
- Integration with Real Hardware

<br>

<div style="width: 100%;">
  <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/7e25e7a877f6b5ad1166eaaa0aec52e9091b9627/headers/resources.svg" style="width: 100%"></a>
</div>

<br>

- <a href = "https://github.com/BinaryQuBit/Elevator-Emulator/blob/master/Documents/Description.pdf">Description</a>

- <a href = "https://github.com/BinaryQuBit/Elevator-Emulator/blob/master/Documents/Milestone.pdf">Milestone</a>

<br>

<div style="width: 100%;">
  <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/626da83e39e3bc3f0359d0fb63a73a934c32f932/headers/contributors.svg" style="width: 100%"></a>
</div>

<br>

<div align="center">

  [<img src="https://github.com/binaryqubit.png" width="80px;" /><br /><sub><a href="https://github.com/binaryqubit">Amandip Padda</a></sub>](https://github.com/BinaryQuBit)
  
</div>

<br>

<div style="width: 100%;">
    <a href="#"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/8f0f4fec01831f9f50ae640d9a76d6d8ca2264e1/headers/vBlogs.svg" style="width: 100%"></a>
</div>

<br>

<div align="center">
    <a href="https://youtu.be/6z2m30fuD-Y"><img src="https://github.com/BinaryQuBit/Readme-Setup/blob/main/gifs/elevatorEmulatorMilestone.gif?raw=true" width="49%"></a>
    <a href="https://youtu.be/i3VYq7fYbPA"><img src="https://github.com/BinaryQuBit/Readme-Setup/blob/main/gifs/elevatorEmulator.gif?raw=true" width="49%"></a>
</div>

<div align="center">
    <a href="https://youtu.be/6z2m30fuD-Y"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/c703a0f2c09ef0a6f5487859cb0dcc64d3b2a8e5/projectTitles/elevatorEmulatorMilestonevBlog.svg" width="49%"></a>
    <a href="https://youtu.be/i3VYq7fYbPA"><img src="https://raw.githubusercontent.com/BinaryQuBit/Readme-Setup/c703a0f2c09ef0a6f5487859cb0dcc64d3b2a8e5/projectTitles/elevatorEmulatorFinalvBlog.svg" width="49%"></a>
</div>