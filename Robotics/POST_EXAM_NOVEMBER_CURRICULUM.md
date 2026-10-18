# 🚀 POST-EXAM NOVEMBER CURRICULUM: INTEGRATED SYSTEMS & ROBOTICS
## Full-Spectrum Engineering: C++ / Python Software + Electrical Hardware Practicals
> **Author:** Shlok (Age 15) & Antigravity  
> **Launch Window:** November 05 – December 02, 2026 (Post-SA-1 Board Exams)  
> **Target Caliber:** MIT EECS / Stanford SlideRoom Maker Portfolio  
> **Repository Location:** `F:\SHLOK\me\Engineering\Robotics\POST_EXAM_NOVEMBER_CURRICULUM.md`  

---

## 🛒 1. The Phase 2 Hardware Procurement List (~₹650 – ₹850 INR)

To be ordered around **October 30, 2026** from **Robu.in** / **ElectronicsComp** so parts arrive for exam completion:

| Item | Component Name | Core Physics / Engineering Concept | Est. Price (INR) |
|:---:|:---|:---|:---:|
| **1** | **SG90 9g Micro Servo Motor** | 50 Hz PWM angle modulation ($1.0 - 2.0\text{ ms}$ pulse width for $0^\circ - 180^\circ$). Z-axis pen actuation. | ₹120 – ₹140 |
| **2** | **0.96" I2C OLED Display (SSD1306)** | Two-wire I2C serial bus (`SDA` / `SCL`). Visual telemetry & animated robot eyes. | ₹220 – ₹250 |
| **3** | **HC-SR04 Ultrasonic Distance Sensor** | Speed of sound time-of-flight ($v = 343\text{ m/s}$). Microsecond acoustic echo metrology. | ₹70 – ₹90 |
| **4** | **120-Piece Capacitor Assortment Box** | Electrolytic ($10\mu\text{F}, 100\mu\text{F}$) for motor power decoupling + Ceramic ($0.1\mu\text{F}$) for RF noise filtering. | ₹150 – ₹180 |
| **5** | **5mm LDR Light Sensors (5 pcs)** | Cadmium Sulfide (CdS) photoconductive bandgap absorption. Optical sensing. | ₹20 – ₹30 |
| **6** | **5V Active Piezo Buzzer (2 pcs)** | Acoustic square-wave transducers & audio telemetry. | ₹25 – ₹35 |
| **TOTAL** | | **Target Budget: ~ ₹600 – ₹725 INR** | |

---

## 📅 2. The 4-Week Integrated Execution Schedule

### Week 1 (Nov 05 – Nov 11): Time, Waves & Signal Filtering
* **Electrical Lab 1: The RC Time Constant ($\tau = R \cdot C$)**
  - Circuit: $100\mu\text{F}$ capacitor + $10\text{k}\Omega$ resistor.
  - Metrology: Real-time exponential charging curve plotting ($V = V_0(1 - e^{-t/\tau})$) on Arduino Serial Plotter.
* **Electrical Lab 2: Ultrasonic Echo Transducer (HC-SR04)**
  - Acoustic pulse-echo timing, converting microsecond round-trip deltas into millimeter distance.
* **Software Track:**
  - **C++ Lesson 11:** Functions, signatures, return types, pass-by-reference (`&`).
  - **Python Lesson 7:** Dynamic lists, slicing, and rolling-average data filtering.

---

### Week 2 (Nov 12 – Nov 18): Memory Pointers & Mechanical Motion
* **Electrical Lab 3: Servo Kinematics & Motor Power Isolation (SG90)**
  - 50 Hz PWM waveform generation without blocking delays.
  - Adding electrolytic decoupling capacitors to absorb servo inductive current spikes.
* **Software Track:**
  - **C++ Lesson 12:** Memory addresses (`&`), raw pointers (`*`), and zero-copy memory buffers.
  - **Python Lesson 8:** Parametric Bézier curve generation ($B(t)$) for smooth cursive strokes.

---

### Week 3 (Nov 19 – Nov 25): Digital Buses & Display Telemetry
* **Electrical Lab 4: The I2C Protocol Bus (SSD1306 OLED)**
  - Master-Slave digital communication over 2 wires (`SDA`/`SCL`).
  - Drawing bitmaps, text, and expressive animated robot eyes.
* **Software Track:**
  - **C++ Lesson 13:** Structs, bit-fields, and packet serialization for serial transmission.
  - **Python Lesson 9:** Full-duplex USB Serial communication (115200 baud) streaming coordinate packets.

---

### Week 4 (Nov 26 – Dec 02): The Grand Flagship Integration
* **Milestone: Polyglot Scribe Alpha Testbench**
  1. Python script takes user text, converts it to Bézier vector paths, and optimizes air travel via TSP.
  2. Python streams coordinate packets over USB to the Arduino Uno.
  3. Arduino moves the SG90 servo for pen up/down, updates OLED with live coordinates, and times virtual motor steps.
  4. Complete end-to-end hardware-software integration running live!

---
*Generated October 18, 2026. Permanent Post-Exam Action Plan.*
