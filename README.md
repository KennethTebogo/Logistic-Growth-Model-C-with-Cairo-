# Logistic Growth Model (C with Cairo)

This repository contains a C implementation of the **logistic growth model**, a fundamental concept in population dynamics. The program generates a **logistic growth curve** and saves it as an image using the **Cairo graphics library**.

## Description
The logistic growth equation is given by:

$$
\ \frac{dP}{dt} = kP (M - P) \
$$

where:
- \( P \) is the population size,
- \( k \) is the growth rate,
- \( M \) is the carrying capacity,
- \( t \) is time.

This C program uses **Cairo** to visualize the population growth over time and saves the output as a PNG file.

## Prerequisites
Ensure you have **GCC** and **Cairo** installed.

### **For Ubuntu Users**
Install Cairo with:
```sh
sudo apt install libcairo2-dev
```

## Installation
Clone the repository:
```sh
git clone https://github.com/KennethTebogo/logistic-growth-c.git
cd logistic-growth-c
```

## Compilation & Execution

### **1. Compile the C Program**
```sh
gcc LogisticGrowth.c -o LogisticGrowth -lm -lcairo
```

### **2. Run the Program**
```sh
./LogisticGrowth
```

## Output
The program generates a **logistic growth curve** and saves it as:
```sh
logistic_growth.png
```
This file will be located in the same directory as the program.

## License
This project is licensed under the MIT License.

