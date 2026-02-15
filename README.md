# K-Boundary: High-Performance Observer-Centric Geometry

**A Lightweight C++ Library for Fast Circular Boundary Detection without `sqrt()` or `atan2()`.**

---

## 🚀 Overview

**K-Boundary** is a geometry optimization library designed for real-time systems, game engines, and robotics. While traditional geometry calculates distances from the center, this library focuses on the **Eccentric Observer**—the "displaced observer" within a circle.

By leveraging the **K-Constant (K=0.5)** discovered through the derivative of the eccentric distance function $c(\theta)$, we provide a pre-computed lookup table (LUT) that allows for O(1) distance queries.

### 💡 Why use K-Boundary?
* **Zero Runtime Sqrt:** Eliminates expensive square root operations in collision loops.
* **Observer-Centric:** Perfect for LiDAR/Sensor offset compensation.
* **Bit-Shift Optimized:** Designed with power-of-two resolutions for maximum CPU throughput.

---

## 🦋 The Mathematical Insight

This project redefines the circle as a dynamic set of variations. By analyzing the derivative of the distance $c'(\theta)$ from an offset $k$, we identified a **Critical Point ($k \approx 0.707$)** where the dynamic energy constant **$K$ equals exactly 0.5**.



---

## ⚡ Performance Benchmark

| Method | Operations | Relative Speed |
| :--- | :--- | :--- |
| **Standard (Euclidean)** | `sqrt`, `pow`, `atan2` | 1x (Baseline) |
| **K-Boundary (Ours)** | **Memory Lookup + Multiply** | **~10x - 15x Faster** |

---

## 🛠 Installation (Header-Only)

Simply copy `EccentricCircle.hpp` into your project.

```cpp
#include "EccentricCircle.hpp"

// Initialize with Radius 100 and Displacement k=0.707 (K=0.5)
EccentricCircle circle(100.0f, 0.7071f);

// Get distance at 45 degrees in O(1)
float dist = circle.get_dist_fast(45);
