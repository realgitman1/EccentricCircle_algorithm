# EccentricCircle_algorithm

This project implements a high-performance collision detection algorithm based on the **Eccentric Observer Model**. By redefining circular geometry through the lens of a shifted observer, we achieve constant-time collision checks.

## Key Feature: $O(1)$ Collision Detection

The most significant advantage of this algorithm is its ability to perform collision detection in **Constant Time $O(1)$**.

- **Elimination of Sqrt:** Traditional Euclidean distance checks require $O(n)$ or expensive square root/trigonometric operations per check.
- **LUT-Based Logic:** Our method utilizes a Pre-calculated Lookup Table (LUT) based on the eccentric distance function.
- **Bit-masking Optimization:** By using bit-wise operations (`& 511`) for index mapping, the algorithm bypasses the overhead of standard mathematical functions, making it ideal for high-frequency physics engines and low-power embedded systems.

------

## Mathematical Background

### The P-O-Q Relationship

- **$O$ (Center):** The fixed origin of the circle.
- **$P$ (Observer):** The eccentric point shifted by $k$.
- **$Q$ (Boundary):** A point on the circumference.
- **$k$ (Normalized Eccentricity):** $k = \frac{OP}{R}$.

### The K-Constant: $S/A$ Ratio

We define **$K$** as the ratio between the **Fluctuation Energy ($S$)** and the **Static Area ($A$)**:

$$K = \frac{S}{A} = \frac{\int_{0}^{2\pi} \frac{1}{2} [C'(\theta)]^2 \, d\theta}{\pi R^2}$$

Through this model, we discovered that **$K=1/2$** is a unique "Circular Identity" that occurs at the critical threshold of $k = 1/\sqrt{2}$.

------

## Performance Comparison

| **Algorithm**          | **Complexity**           | **Primary Operation**     | **Accuracy**        |
| ---------------------- | ------------------------ | ------------------------- | ------------------- |
| **Standard Euclidean** | $O(1)$ (High Latency)    | `sqrt(x^2 + y^2)`         | High                |
| **AABB / Shadow**      | $O(1)$ (Low Latency)     | Comparison (`if`)         | Low (Rectangular)   |
| **Minkowski (GJK)**    | Iterative                | Vector Searching          | Very High           |
| **K-Boundary (Ours)**  | **$O(1)$ (Low Latency)** | **LUT Lookup + Bit-mask** | **High (Circular)** |

------

## Usage

C++

```
#include "Eccentric.hpp"

Eccentric eccentric; 
float radius = 10.0f;
int index = 43; // 30 degrees

// Instant O(1) Boundary check
float boundary_dist = eccentric.getTableValue(index) * radius;
```

