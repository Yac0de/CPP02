# CPP Module 02 - Canonical Form, Operator Overloading & Fixed-Point Arithmetic

## Table of Contents

1. [Project Overview](#project-overview)
2. [What is the Canonical Form?](#what-is-the-canonical-form)
3. [Fixed-Point Arithmetic - A New Number Representation](#fixed-point-arithmetic)
4. [Operator Overloading](#operator-overloading)
5. [Exercise Breakdown](#exercise-breakdown)
   - [Ex00: Mon premier canon](#ex00-mon-premier-canon)
   - [Ex01: Une classe plus utile](#ex01-une-classe-plus-utile)
   - [Ex02: Maintenant, on peut parler](#ex02-maintenant-on-peut-parler)
   - [Ex03: BSP](#ex03-bsp)
6. [Compiling and Testing](#compiling-and-testing)
7. [Conclusion & What’s Next](#conclusion--whats-next)

---

## Project Overview

This module marks a critical shift: we move from object design to object **refinement**.
We build a robust numerical class that mimics fixed-point arithmetic, all while adhering strictly to C++ best practices — especially the **canonical form** and **operator overloading**.

We also begin exploring **polymorphism via operator overloads** — sometimes called *ad-hoc polymorphism* — which allows custom behavior for native operators (`+`, `-`, `==`, etc.).

---

## What is the Canonical Form?

Starting with this module, every class you write should follow the **canonical form**, also known as the **Coplien Form**. It consists of four essential methods:

1. **Default constructor**
2. **Copy constructor**
3. **Copy assignment operator**
4. **Destructor**

Why?

- These ensure that your class behaves properly during **copying, assignment, and destruction**.
- It also makes your class compatible with STL containers and standard C++ idioms.

Here’s what it looks like:

```cpp
class MyClass {
public:
    MyClass();                             // Default constructor
    MyClass(const MyClass& other);         // Copy constructor
    MyClass& operator=(const MyClass& rhs); // Copy assignment
    ~MyClass();                            // Destructor
};
```

---

## Fixed-Point Arithmetic

In most programming environments, numbers are represented in two main formats: **integers** (like `int`) and **floating-point** (like `float` or `double`).

### But what's the difference?

- **Floating-point numbers** allow fractional values (like 3.14), but suffer from rounding errors due to their binary approximation — especially dangerous in financial or scientific contexts where precision is key.
- **Fixed-point numbers** simulate fractional numbers using integers, offering **better precision control** and often **faster computation** on systems without floating-point hardware (e.g., embedded systems).

### So how does fixed-point work?

Instead of storing a real number directly, we:

- Store an **integer** that represents the real number multiplied by a scaling factor (usually a power of 2).
- Use **bit shifting** to simulate decimal behavior.

#### Example:

If we want to store `3.5` and are using 8 bits for the fractional part, we calculate:

```
scaled = 3.5 * 2^8 = 896
```

We store `896` internally. Later, when we need the real value back:

```
real = 896 / 2^8 = 3.5
```

In code, we implement this using:

```cpp
int _value;                        // raw fixed-point value
static const int _fracBits = 8;    // number of bits reserved for the fractional part
```

Conversion formulas:

- **From float to fixed:** `roundf(f * (1 << _fracBits))`
- **From fixed to float:** `_value / (float)(1 << _fracBits)`

### Why this matters:

This technique allows us to:

- Avoid floating-point inaccuracies
- Have deterministic precision
- Maintain integer-only calculations under the hood — crucial for consistency and portability

> 📌 This is particularly useful in systems programming, DSP, financial apps, or any context where precise decimal behavior is required.

---

## Operator Overloading and Intro to Polymorphism

C++ allows redefining native operators (`+`, `-`, `==`, etc.) for your own types. This is called **operator overloading**.

Why is this useful?

- Code reads more naturally: `a + b` instead of `a.add(b)`
- Makes your class feel like a built-in type

### How it works:

You define a function like:

```cpp
Fixed operator+(const Fixed& rhs) const;
```

Inside, you perform arithmetic on the underlying `_value` fields.

We also overload:

- Comparison operators: `==`, `<`, `>=`, etc.
- Increment/decrement: `++`, `--`
- Insertion (`<<`) to use with `std::cout`

---

## What is Polymorphism?

Polymorphism means "many forms" — it lets objects behave differently based on context.

In this module, we deal with **ad-hoc polymorphism** — a form of polymorphism achieved via **function and operator overloading**. That means we define multiple versions of a function/operator, each working with different types or doing slightly different things.

### Example:

```cpp
Fixed a(5.25f);
Fixed b(2);
Fixed result = a + b; // invokes overloaded operator+
```

The `+` operator behaves *as if* `Fixed` were a native number type, but it only works because we taught it how by defining the appropriate overload.

This form of polymorphism is static (resolved at compile time) and differs from **dynamic polymorphism**, which we’ll explore in CPP03 using `virtual` functions and class inheritance.

> Polymorphism gives our custom classes the flexibility and expressive power we expect from native types — a cornerstone of idiomatic C++ design.

---

## Exercise Breakdown

### Ex00: Mon premier canon

**Goal:** Implement the canonical form (default/copy/assign/destructor) for a `Fixed` class.

**Key Concepts:**

- Proper class lifecycle management
- Internal representation of raw data

**Functions implemented:**

- `getRawBits()` and `setRawBits()` give direct control over the internal integer value.

### Ex01: Une classe plus utile

**Goal:** Make the class actually represent numbers.

**What we add:**

- Constructors for `int` and `float`
- Conversion methods: `toInt()`, `toFloat()`
- Overload `operator<<` to allow: `std::cout << fixed;`

**Concept in focus:** *fixed-point representation*

We convert values using bit shifting to simulate decimal points while storing everything as integers.

**Comparison with C:**
In C, you’d store floats directly, or manipulate integers and shift manually. Here, C++ encapsulates all of this into a single safe and reusable class.

### Ex02: Maintenant, on peut parler

**Goal:** Add arithmetic and comparison capabilities.

**Key additions:**

- Overloaded operators: `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `<=`, `>=`
- Pre/post increment and decrement
- Static methods: `min()` and `max()`

**Technical depth:**
These overloads require manually adjusting `_value` and keeping the fixed-point format intact. Especially for multiplication and division, conversion to float might be used internally.

**Why this matters:**
This is C++’s first real encounter with **polymorphism**. Your `Fixed` object can now behave like a number — but only because you told the compiler how.

### Ex03: BSP (Bonus - Optional)

**Goal:** Use `Fixed` to build a simple geometry utility: detect if a point lies inside a triangle.

**What we learn:**

- Create a `Point` class in canonical form
- Use basic geometry: barycentric coordinates or cross products
- Practice manipulating your `Fixed` class in real logic

---

## Compiling and Testing

1. Go into the exercise folder:

```sh
cd ex02
```

2. Compile with make:

```sh
make
```

3. Run the executable:

```sh
./<program_name>
```

4. Clean builds:

```sh
make clean
make fclean
make re
```

---

## Conclusion & What’s Next

In this module, we’ve mastered the **form canonique**, built a reusable **fixed-point number class**, and used **operator overloading** to simulate built-in types.

These are powerful techniques that bring us much closer to idiomatic C++ and prepare us for:

- **Deeper OOP patterns** (inheritance, polymorphism)
- **Proper resource management (RAII)**
- **Custom types that blend seamlessly into the language**

Up next in **CPP03**, we’ll tackle inheritance, virtual functions, and dynamic polymorphism!

