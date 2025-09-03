# 🖥️ Stack Processor
A small emulator I built for a **stack-based processor** as part of my university course on **Algorithms and Data Structures** at **Gdańsk University of Technology**.  

---

## 📖 Project Description

The processor features:

- **Program memory** – stores a sequence of instructions.
- **Instruction pointer** – points to the next instruction to execute.
- **Stack** – stores lists of symbols, which can represent numbers or sequences of characters.

Each instruction is a single character. The stack stores **lists of symbols**, where numeric lists store digits in reverse order (e.g., `-1234` → `4321-`).

This emulator handles:

- **Basic stack operations** – push, pop, duplicate, swap, copy
- **Arithmetic operations** – addition, negation, absolute value
- **Input/Output** – read character, write character, dump stack
- **Conditional operations** – comparisons, jumps
- **Advanced manipulations** – ASCII conversions, list splitting

All programs are assumed to be valid according to the instruction set.

---

## 🔧 Instruction Set Highlights

| Symbol | Operation |
|--------|-----------|
| `'` | Push empty list |
| `,` | Pop list from stack |
| `:` | Duplicate top list |
| `;` | Swap top two lists |
| `@` | Copy list from specific stack position |
| `.` | Read input character |
| `>` | Output first character of top list |
| `!` | Logical negation |
| `<, =` | Comparisons |
| `+` | Add two numbers |
| `$` | Split first character to new list |
| `#` | Append list A to top of stack |
| `[ ]` | ASCII conversions |
| Other | Append character to top list |

---

## 🏗️ Constraints

- **No STL** is allowed except for input and output
- **No Arrays** except for storing input
- Only **one loop** (`for/while/do`) allowed, recursion is required for iteration.  


