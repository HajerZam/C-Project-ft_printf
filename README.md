<h1 align="center">✨ C-Project-ft_printf ✨</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/github/languages/top/HajerZam/C-Project-ft_printf?style=flat-square" />
  <img src="https://img.shields.io/github/repo-size/HajerZam/C-Project-ft_printf?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/HajerZam/C-Project-ft_printf?style=flat-square" />
  <img src="https://img.shields.io/github/issues/HajerZam/C-Project-ft_printf?style=flat-square" />
</p>

<p align="center">
  🧵 *My third project in 42's Common Core — nyeheheh (๑'ᵕ'๑)⸝* 🎓  
</p>

---

## 📌 Project Overview

> Reimplement the `printf()` function in C with limited formatting capabilities — with precision, grace, and a touch of chaos.

### 🎯 **Goal**

Recreate the core functionality of the C standard `printf()` function in your own custom version called `ft_printf`.

#### Features to Implement:

- `%c`: Character
- `%s`: String
- `%p`: Pointer address
- `%d`, `%i`: Signed decimal integer
- `%u`: Unsigned decimal integer
- `%x`, `%X`: Unsigned hexadecimal integer
- `%%`: Literal `%` sign

### 📦 Output

- A static library file: `libftprintf.a`
- A proper `Makefile` with the required rules: `all`, `clean`, `fclean`, `re`

### ⚠️ Constraints

- Must follow 42’s **Norm** (strict code style)
- Handle memory safely (no leaks allowed!)
- Mandatory part must be 100% before bonus is graded

---

## 🛠️ Project Milestones

### ✅ Milestone 1: Project Setup
- `src/` and `include/` directories
- Functional `Makefile`

### 📚 Milestone 2: Master Variadic Functions
- Learn about `va_start`, `va_arg`, `va_end`
- 📖 [GeeksforGeeks](https://www.geeksforgeeks.org/variadic-functions-in-c/) | 🎥 [YouTube](https://youtu.be/ZwqxPnp7LQk)

### 🧩 Milestone 3: Implement Conversions
| Specifier | Description            |
|----------|------------------------|
| `%c`      | Print single character |
| `%s`      | Print string           |
| `%p`      | Print pointer in hex   |
| `%d`, `%i`| Signed integer         |
| `%u`      | Unsigned integer       |
| `%x`      | Hex lowercase          |
| `%X`      | Hex uppercase          |
| `%%`      | Literal `%`            |

### 🧪 Milestone 4: Testing
- Compare against original `printf()`
- ✅ [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
- ✅ [printfTester](https://github.com/Tripouille/printfTester)

### 🔍 Milestone 5: Optimize & Debug
- Use `valgrind` for memory leak detection:
```bash
valgrind --leak-check=full ./your_program
```
---
Language     Files     Lines    Code   Comments   Blanks
----------------------------------------------------------
C            XX        XXXX     XXXX     XXX       XXX
Header       XX        XXXX     XXXX     XXX       XXX
---

🧵 Final Thoughts
“Coding is 10% writing code and 90% staring at the screen wondering why it doesn’t work.”

Let's printf like it's 1999 ✨

---
