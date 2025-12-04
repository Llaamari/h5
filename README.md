# Object-Oriented Programming — Memory Address, Pointers & References (C++)

## Overview
This exercise demonstrates the core concepts of:
- **Memory addresses**
- **Pointers (`*`)**
- **References (`&`)**
- **Passing objects by value vs. by reference**

The program includes both primitive variables (`int`) and class objects to highlight:
- How a pointer can change what it points to
- How a reference cannot be rebound after initialization
- The difference between modifying copied object data vs. original object data

---
## Concepts Explained

### Memory Address
Every variable is stored at a specific memory location.  
In C++ you can print an address using:

```cpp
std::cout << &a;
```
### Pointer
A pointer stores the address of a variable:
```cpp
int *pointerA = &a;
```
You can change it later:
```cpp
pointerA = &b; // allowed
```
### Reference
A reference is an alias to an existing variable:
```cpp
int &refA = a;
```
You cannot rebind it:
```cpp
refA = b; // allowed but only changes value of a, not the address
// refA = &b; ❌ not allowed
```
## Exercise Instructions
1. Pointer demo
   ```cpp
   int a = 5;
   std::cout << "Value of a: " << a << " | Address: " << &a << std::endl;

   int *pointerA = &a;
   std::cout << "Pointer address: " << pointerA << std::endl;
   std::cout << "Pointer points to value: " << *pointerA << std::endl;
   ```
2. Reference demo
   ```cpp
   int &refA = a;
   std::cout << "Reference address: " << &refA << std::endl;
   std::cout << "Reference value: " << refA << std::endl;
   ```
3. Change pointer to another address
   ```cpp
   int b = 6;
   pointerA = &b; // ✅ allowed
   ```
4. Attempt reference rebind (not possible)
   ```cpp
   // refA = &b; ❌ not possible!
   // refA = b;  ✅ copies value to a instead
   ```
## Project Structure
```css
h5/
 ├─ main.cpp
 ├─ ClassB.h / ClassB.cpp
 ├─ ClassA1.h / ClassA1.cpp
 └─ ClassA2.h / ClassA2.cpp
```
## Expected Results
- ✅ Pointer can later point to a new address (`b`)
- ❌ Reference cannot change target after initialization
- Passing object as copy protects original object data
- Passing object as reference allows original object modification
## Example Output (addresses may vary)
```yaml
Value of a: 5 | Address: 0x5449fff84c

Pointer address: 0x5449fff84c
Pointer points to value: 5

Reference address: 0x5449fff84c
Reference value: 5

Pointer now points to address of b: 0x...
Value at that address: 6
```
## Usage
Clone the repository and compile with:
```bash
g++ main.cpp ClassA1.cpp ClassA2.cpp ClassB.cpp -o h5
./h5
```
