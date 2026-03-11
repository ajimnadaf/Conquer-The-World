# Conquer-The-World


# Conquer The World - Logistical Optimization

![Language](https://img.shields.io/badge/Language-C++-blue.svg)
![Algorithm](https://img.shields.io/badge/Algorithm-Min--Cost%20Max--Flow-red.svg)

## 📌 Project Overview
**Conquer The World** is a high-performance C++ implementation designed to solve logistical resource distribution challenges on tree-structured networks. Inspired by the **ACM-ICPC 2018 World Finals (Problem C)**, this tool calculates the minimum cost required to redistribute resources (armies) across territories to satisfy specific demand requirements.



## 🚀 Key Features
* **Efficient Optimization:** Implements a Min-Cost Max-Flow logic on trees, handling up to 250,000 nodes.
* **Dynamic Programming:** Uses recursive state calculation with `std::map` to manage costs and savings efficiently.
* **Performance:** Optimized for competitive programming standards with Fast I/O.
* **Scalable:** Capable of handling $10^5$ inputs with high numerical precision.

## 🛠️ Technical Stack
* **Language:** C++
* **Concepts:** Dynamic Programming, Tree Data Structures, Min-Cost Max-Flow.
* **Compiler:** G++ (MinGW recommended)

## 📁 Repository Structure
```text
├── src/                # Source code (conquer_the_world.cpp)
├── docs/               # System Design Document & Project PPTX
├── problem-statement/  # Original ICPC 2018 Problem PDF
└── README.md           # Project documentation
