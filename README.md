# C-Project-ft_printf
my third project in 42 common core nyeheheh (๑'ᵕ'๑)⸝*

### **1. Understand the Project**

- **Goal**: Reimplement the `printf()` function in C with specific formatting features (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`).
- **Output**: A library file (`libftprintf.a`) with a proper Makefile.
- **Constraints**:
    - Follow the Norm (code style rules).
    - Handle memory leaks and errors gracefully.
    - Mandatory part must be perfect before bonuses are graded.

---

### **2. Breakdown into Smaller Milestones**

### **Milestone 1: Set up the project structure**

- Create a `libftprintf` repository with directories for source (`src/`) and header files (`include/`).
- Prepare a Makefile with mandatory rules (`all`, `clean`, `fclean`, `re`, etc.).

### **Milestone 2: Learn Variadic Functions**

- Study `stdarg.h` to understand how `va_start`, `va_arg`, and `va_end` work.
    - **Resources**:
        - [Variadic Functions in C - GeeksforGeeks](https://www.geeksforgeeks.org/variadic-functions-in-c/)
        - [YouTube: Variadic Functions](https://youtu.be/ZwqxPnp7LQk)

### **Milestone 3: Implement Individual Conversions**

1. `%c`: Handle single characters.
2. `%s`: Print strings.
3. `%p`: Print pointers in hexadecimal.
4. `%d`, `%i`: Print signed integers.
5. `%u`: Print unsigned integers.
6. `%x`, `%X`: Print unsigned integers in hexadecimal (lowercase and uppercase).
7. `%%`: Print `%`.

### **Milestone 4: Testing**

- Write test cases for all the conversions and compare your output with the original `printf()`.
- Use tools like [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF) or [printfTester](https://github.com/Tripouille/printfTester).

### **Milestone 5: Optimize and Debug**

- Ensure your implementation is modular and extensible for bonus features.
- Use tools like Valgrind to check for memory leaks and undefined behavior.
    - **Command**: `valgrind --leak-check=full ./your_program`

### **Milestone 6: Bonuses (Optional)**

- Implement additional flags (, `0`, `.`, `#`, `+`, `space`) systematically.

---

### **3. Key Resources**

### **Articles and Documentation**

- [Variadic Functions in the C Standard Library](https://en.cppreference.com/w/c/variadic)
- [Printf Function Explained](https://aticleworld.com/printf-in-c/)

### **YouTube Tutorials**

- [ft_printf Explanation (42 Projects)](https://youtu.be/FT_hNWe3JLE)
- [Understanding Makefiles](https://youtu.be/Vdu9vDhlE5A)

### **GitHub Repositories**

- [ft_printf GitHub Example](https://github.com/topics/ft-printf) - Look for well-documented repositories to learn structure and best practices.
- https://github.com/Surfi89/ft_printf.git
- https://github.com/Kuninoto/42_ft_printf.git
- https://github.com/mcombeau/ft_printf.git

### **Other Tools**

- **Norminette**: Check for code compliance with 42's norms.
- **Valgrind**: Debugging memory errors.

---

### **4. Approach**

1. **Use Visual Aids**: Flowcharts for logic, and diagrams to map variadic function behaviour.
2. **Keep Notes**: Write down small achievements to stay motivated.
