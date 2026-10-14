# 🖋️ PROJECT: POLYGLOT SCRIBE & CANVASBOT
## Autonomous Multilingual Calligraphy & Computational Painting Robot
> **Lead Systems Engineer:** Shlok (Age 15)  
> **Target Caliber:** MIT EECS / Stanford Maker Portfolio & SlideRoom Submission  
> **Repository:** `F:\DEV\Shlok-2\me\Engineering\Robotics\POLYGLOT_SCRIBE_AND_CANVASBOT_BLUEPRINT.md`  
> **Status:** Architecture Locked // November 2026 Kickoff  

---

## 🏛️ 1. The Engineering Philosophy: English First (The MVP)

In professional robotics and systems architecture, attempting to solve all 20 complex scripts simultaneously on Day 1 is an engineering anti-pattern. 

**The Strategy:** We build a bulletproof **Minimum Viable Product (MVP) in English (Latin Script)** first:
1. **Discrete Left-to-Right Tokens:** Eliminates complex cursive ligature shaping during initial kinematic testing.
2. **Standard 1-Line Vector Glyphs:** Uses single-stroke vector topologies (Hershey fonts & parametric splines) rather than hollow dual outlines.
3. **End-to-End Pipeline Validation:** Validates the entire signal chain:
   $$\text{User Text Input} \longrightarrow \text{Parametric Vector Math} \longrightarrow \text{TSP Path Optimizer} \longrightarrow \text{Virtual Simulator} \longrightarrow \text{Serial G-code} \longrightarrow \text{Arduino Uno}$$
4. **Modularity:** Once the pipeline draws English with micrometer precision, expanding to Gujarati, Sanskrit, Arabic, and Van Gogh impasto strokes is purely a mathematical plug-in!

---

## 📐 2. The 4-Layer System Architecture

```text
+-------------------------------------------------------------------------------------------------+
|                                    LAYER 1: THE PYTHON BRAIN                                    |
|   - Text Input Engine: English String Parser                                                    |
|   - Vector Geometry: Hershey Single-Line Font Coordinates                                       |
|   - Parametric Bézier Curves: Continuous spline interpolation for smooth handwriting curvature  |
+-----------------------------------------------+-------------------------------------------------+
                                                │
                                                ▼  (Raw Path Vectors: Array of [X, Y, PenState])
+-----------------------------------------------+-------------------------------------------------+
|                         LAYER 2: TSP TOOLPATH OPTIMIZER (Python)                                |
|   - Problem: Naive text drawing lifts the pen and travels randomly, wasting 40% of time.        |
|   - Solution: Nearest-Neighbor / 2-Opt Traveling Salesperson Problem (TSP) algorithm            |
|   - Output: Shortest air-travel trajectory between strokes                                      |
+-----------------------------------------------+-------------------------------------------------+
                                                │
                                                ▼  (Optimized G-code / Coordinate Packets)
+-----------------------------------------------+-------------------------------------------------+
|                         LAYER 3: VIRTUAL SIMULATOR & SERIAL BRIDGE                              |
|   - Screen Visualizer: Real-time graphical pen simulation (Matplotlib / Pygame)                |
|   - USB Serial Bridge: 115200 Baud packet streaming to Arduino Uno                              |
+-----------------------------------------------+-------------------------------------------------+
                                                │
                                                ▼
+-----------------------------------------------+-------------------------------------------------+
|                     LAYER 4: REAL-TIME MOTION FIRMWARE (Arduino C++)                            |
|   - Multi-Axis Interpolation: Bresenham Line Generation                                        |
|   - Velocity Planning: Trapezoidal S-curve acceleration (eliminates motor stall & pen chatter)  |
|   - Z-Axis Pen Actuator: PWM Micro-Servo (SG90)                                                 |
+-------------------------------------------------------------------------------------------------+
```

---

## 📅 3. The November 2026 Execution Sprint (Post SA-1 Exams)

| Week | Sprint Focus | Mathematical & Software Deliverables |
|:---:|:---|:---|
| **Week 1 (Nov 1 – Nov 7)** | **English Stroke Geometry** | • Python single-line Hershey font parser.<br>• Bézier curve interpolation ($B(t) = (1-t)^2 P_0 + 2(1-t)t P_1 + t^2 P_2$).<br>• Glyphs normalized to bounding box $[0, 1] \times [0, 1]$. |
| **Week 2 (Nov 8 – Nov 14)** | **The Virtual Screen Plotter** | • Interactive Python visualizer.<br>• Renders virtual pen strokes stroke-by-stroke with animated pen-up/pen-down transitions. |
| **Week 3 (Nov 15 – Nov 21)** | **The TSP Path Optimizer** | • Nearest-neighbor pen-lift minimization algorithm.<br>• Telemetry reporting total drawn distance vs air-travel distance. |
| **Week 4 (Nov 22 – Nov 30)** | **Arduino Serial Bridge** | • USB packet streaming protocol (`G00`, `G01`, `PEN_UP`, `PEN_DOWN`).<br>• Arduino Uno receives coordinates and flashes timing feedback. |

---

## 🚀 4. The Roadmap Beyond English (Phase 2 & 3)

```text
[PHASE 1: English MVP] ────────► [PHASE 2: Indic & Perso-Arabic] ────► [PHASE 3: Van Gogh CanvasBot]
• Hershey Single-Line Font       • Gujarati Ligatures (Jodakshar)      • Edge Tangent Flow (ETF) Fields
• Parametric Bézier Paths         • Sanskrit Shirorekha Continuous      • Impasto Directional Brushstrokes
• TSP Air-Travel Optimization    • Persian Nastaliq Diagonal Baseline  • Multi-Color Palette Dipping
• Virtual Screen Simulator       • HarfBuzz Text-Shaping Integration   • Z-Axis Bristle Pressure Control
```

---

## 🛠️ 5. Physical Hardware Roadmap (Summer 2027)

* **Kinematic Chassis Options:**
  1. **Option A (The HTX Mobile Magnetic Crawler):** 2x N20 metal gearmotors + Neodymium magnets on a vertical magnetic whiteboard.
  2. **Option B (Desktop CoreXY Gantry):** 2x NEMA 17 Stepper motors + GT2 timing belts for ultra-high-resolution calligraphy.
* **Onboard Electronics:** Arduino Uno R3 / ESP32 + SG90 micro-servo (Z-axis pen lift) + 0.96" I2C OLED display (animated expressive eyes).

---
*Created on October 14, 2026. Permanent System Architecture Locked.*
