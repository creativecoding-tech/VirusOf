# 🌀 VirusOf | OpenFrameworks Generative Experiments

Experimen visual dengan animasi Bezier curves, Phyllotaxis spiral, dan easing functions. Project ini dibuat untuk belajar dan membandingkan performa antara **Processing** vs **OpenFrameworks**.

[![YouTube Demo](https://img.shields.io/badge/Watch-Demo-red?style=for-the-badge&logo=youtube)](https://youtu.be/Cfb6Yz5rZ8Q)

![OpenFrameworks](https://img.shields.io/badge/OpenFrameworks-0.12.1-blue)
![C++](https://img.shields.io/badge/C++-20-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)
![License](https://img.shields.io/badge/License-Apache%202.0-green)

---

## 📺 Demo Video

Cek hasilnya di YouTube: **[VirusOf - Processing vs OpenFrameworks Performance](https://youtu.be/Cfb6Yz5rZ8Q)**

---

## ✨ Fitur & Teknik

- **Bezier Curves Animation** — 99 curves per pattern dengan animated control points
- **Phyllotaxis Arrangement** — Spiral pattern berdasarkan Golden Angle (137.5°)
- **Grid Layout** — 2D grid yang bisa di-switch ke phyllotaxis mode
- **Smooth Transitions** — Lerp interpolation antar posisi
- **Oscillating Motion** — Sine-based easing untuk smooth movement
- **Color Gradients** — HSB color mapping dengan rainbow spectrum
- **Trail Effects** — Partial background clear untuk visual trails
- **Interactive** — Mouse & keyboard controls

---

## 🚀 Performance Comparison

| Framework | Performance | FPS |
|-----------|-------------|-----|
| **Processing** (Java) | ⚠️ Lag & stutter | ~15-30 FPS |
| **OpenFrameworks** (C++) | ✅ Smooth | 60 FPS solid |

**Kesimpulan:** OpenFrameworks lebih efisien untuk visual experiments yang banyak animasi objects. Hardware acceleration dan memory management yang lebih baik membuat frame rate stabil.

---

## 🎮 Controls

| Input | Action |
|-------|--------|
| **Mouse Click** | Pause / Play animation |
| **Key 'A'** | Switch Grid ⇄ Phyllotaxis mode |
| **Key 'Q'** | Quit application |

---

## 🛠️ Tech Stack

- **OpenFrameworks 0.11.0+**
- **C++17**
- **Visual Studio 2019/2022** (Windows)
- **Bezier Curves Mathematics**
- **Phyllotaxis Algorithms**
- **Golden Ratio (φ = 1.618...)**

---

## 📦 Installation

### Prerequisites

1. Install **OpenFrameworks** for Windows from [openframeworks.cc](https://openframeworks.cc/download/)
2. Install **Visual Studio 2019/2022** with "Desktop development with C++" workload

### Setup

```bash
# Clone this repo
git clone https://github.com/username/VirusOf.git

# Open Visual Studio
# Double-click: VirusOf.sln

# Build & Run
# Press F5 or click "Local Windows Debugger"
```

---

## 🧬 Mathematics Behind

### Phyllotaxis Formula

```
angle = n × 137.5° (golden angle)
radius = c × √n
x = center_x + radius × cos(angle)
y = center_y + radius × sin(angle)
```

### Easing Function

```cpp
// Smooth ease-in-out using sine wave
t = oscillationTime / cycleDuration
easedT = (sin(t × 2π - π/2) + 1) / 2
radius = easedT × maxRadius
```

---

## 📝 Project Structure

```
VirusOf/
├── src/
│   ├── main.cpp           # Entry point
│   ├── ofApp.cpp/h        # Main application
│   └── BezierCurve.cpp/h  # Bezier curve class
├── bin/                   # Build output (gitignored)
├── obj/                   # Intermediate files (gitignored)
└── dll/                   # OF dependencies
```

---

## 🎯 Purpose

Project ini adalah bagian dari eksplorasi **Creative Coding** dan belajar:

- 🔬 Eksperimen visual algorithms
- ⚡ Benchmark performa framework
- 📚 Belajar matematika dalam visual programming
- 🎯 Memahami konsep computational geometry

---

## 🤝 Contributing

Ide, saran, dan improvement sangat welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests
- Share your experiments!

---

## 📄 License

This project is licensed under the **Apache License 2.0** - see the LICENSE file for details.

---

## 🙏 Credits & References

- **OpenFrameworks** - Creative coding framework
- **Nature** - Phyllotaxis patterns dari tumbuhan 🌻

---

**Made with ❤️ for learning purposes**

*[YouTube: Creative Coding](https://www.youtube.com/channel/UCpa-NHKB3Tjx7FM8l9nr_sw)* | *[GitHub](https://github.com/creativecoding-tech)*
