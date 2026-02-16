# K-Boundary: High-Performance Observer-Centric Geometry

**A Lightweight C++ Library for Fast Circular Boundary Detection without `sqrt()` or `atan2()`.**

---

## Overview

**K-Boundary** is a geometry optimization library designed for real-time systems, game engines, and robotics. While traditional geometry calculates distances from the center, this library focuses on the **Eccentric Observer**—the "displaced observer" within a circle.

By leveraging the **K-Constant (K=0.5)** discovered through the derivative of the eccentric distance function $c(\theta)$, we provide a pre-computed lookup table (LUT) that allows for O(1) distance queries.

####Why use K-Boundary?

* **Zero Runtime Sqrt:** Eliminates expensive square root operations in collision loops.
* **Observer-Centric:** Perfect for LiDAR/Sensor offset compensation.
* **Bit-Shift Optimized:** Designed with power-of-two resolutions for maximum CPU throughput.

---

## The Mathematical Insight

This project redefines the circle as a dynamic set of variations. By analyzing the derivative of the distance $c'(\theta)$ from an offset $k$, we identified a **Critical Point ($k \approx 0.707$)** where the dynamic energy constant **$K$ equals exactly 0.5**.



---

## Performance Benchmark

| Method | Operations | Relative Speed |
| :--- | :--- | :--- |
| **Standard (Euclidean)** | `sqrt`, `pow`, `atan2` | 1x (Baseline) |
| **K-Boundary (Ours)** | **Memory Lookup + Multiply** | **1.5 xFaster** |



## Installation

Simply git clone all files into your project.

```cpp
./Eccentricmain.cpp radius index_n detectdist
```

*index n is the number of (360 / 512) * n

example

```
./Eccentricmain.cpp 10 21(it is almost 30 degree) 5
```

result : clean

example

```
./Eccentricmain.cpp 10 21(it is almost 30 degree) 11
```

result : Collision detected
