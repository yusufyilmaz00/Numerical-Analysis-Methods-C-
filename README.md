# 🧮 Numerical Analysis Solver

A terminal-based numerical analysis tool that allows users to solve various mathematical problems using well-established numerical methods. This program supports **root-finding, matrix operations, numerical differentiation, and integration** with an interactive menu system.

---

## 🚀 Features

✅ **Root-Finding Algorithms**: Implements Bisection, Regula Falsi, and Newton-Raphson methods.  
✅ **Matrix Operations**: Supports NxN matrix inversion, Gauss Elimination, and Gauss-Seidel methods.  
✅ **Numerical Differentiation**: Computes derivatives using forward, backward, and centered difference methods.  
✅ **Numerical Integration**: Implements **Simpson’s Rule** and **Trapezoidal Rule** for definite integrals.  
✅ **Polynomial Handling**: Users can input and evaluate polynomial equations dynamically.  
✅ **Iterative Computation**: Supports precision control and iteration limits for optimized calculations.  
✅ **File-Based Persistence**: Computed results can be saved in text/binary files.  
✅ **Real-Time Terminal UI**: Displays step-by-step iterations dynamically.  

---

## 🛠️ Installation & Compilation

To use this numerical analysis solver, you need to have a **C compiler** installed on your system (e.g., `gcc` for Linux/macOS or MinGW for Windows).

### **🔹 Compilation**
You can compile the program using GCC:

```bash
gcc Project.c -o numerical_solver -lm
```

### **🔹 Running the Program**

After compiling, you can run the program with:

```bash
./numerical_solver
```

---

## 📜 Usage Instructions

Once you run the program, you will see a menu-based system where you can select the desired numerical method by entering the corresponding number.

### 📝 Example Usage: Bisection Method

1. Select `1` for the Bisection Method.
2. Enter the polynomial function coefficients and exponents.
3. Input the interval `[a, b]`, the maximum iterations, and the tolerance value.
4. The program will iterate and display step-by-step calculations.

---

## 📌 Menu Options

| Option | Method |
|--------|--------------------------------|
| 1 | Bisection Method |
| 2 | Regula Falsi Method |
| 3 | Newton-Raphson Method |
| 4 | Matrix Inversion |
| 5 | Gauss Elimination |
| 6 | Gauss-Seidel Method |
| 7 | Numerical Differentiation |
| 8 | Simpson’s Rule |
| 9 | Trapezoidal Rule |
| 10 | Gregory-Newton Interpolation |
| 0 | Quit |

---

## 🔧 Technologies Used

- **C Programming** – Implements numerical methods and core logic.  
- **File I/O (Binary & Text)** – Stores polynomial equations and computed results.  
- **Dynamic Memory Allocation** – Efficiently manages matrices and polynomial functions.  
- **Iterative Algorithms** – Handles numerical computations with precision.  
- **Terminal Interaction** – Provides an interactive CLI experience.  

---

## 📌 Example Calculation

### **Bisection Method Example**

#### **Input:**
```
Please enter how many x do you want in your polynomial (For example ax2 + bx + c has 3 x values): 4
Enter x's coefficient: 1
Enter x's power: 3
Enter x's coefficient: -7
Enter x's power: 2
Enter x's coefficient: 14
Enter x's power: 1
Enter x's coefficient: -6
Enter x's power: 0

1.00 * X^3 + -7.00 * X^2 + 14.00 * X^1 + -6.00* X^0

Enter an {a} value for [a,b]: 0
Enter a {b} value for [a,b]: 1
Enter a max iteration value: 100
Enter a tolerance value: 0.01

```

#### **Output:**
```
Iteration #1
left  -> F(0.000000): -6.000000
mid   -> F(0.500000): -0.625000
right -> F(1.000000): 2.000000

Iteration #2
left  -> F(0.500000): -0.625000
mid   -> F(0.750000): 0.984375
right -> F(1.000000): 2.000000

Iteration #3
left  -> F(0.500000): -0.625000
mid   -> F(0.625000): 0.259766
right -> F(0.750000): 0.984375

Result : x ≈ 0.625000
```

---

## 📌 Contribution

If you'd like to contribute to the project, feel free to fork the repository and submit a pull request. Bug reports and suggestions are welcome!

---

## 📝 License

This project is released under the **MIT License**.

---

## 📞 Contact

For any questions or feedback, feel free to reach out! 🚀
