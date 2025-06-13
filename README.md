
# 🧠 Memory Allocation Visualizer (C Project)

This C program simulates operating system memory allocation strategies including **Contiguous Allocation**, **Paging**, and shows **Fragmentation Analysis** through a colorful and interactive terminal interface.

---

## 🎯 Features

- ✅ Contiguous memory allocation using **First Fit**
- ✅ **Paged memory allocation** using fixed-size pages
- ✅ Interactive and **color-coded memory visualization**
- ✅ Detailed block-wise memory information
- ✅ Calculation of **internal and external fragmentation**
- ✅ **Demo mode** and **Interactive mode**
- ✅ Terminal-compatible across Linux, macOS, Windows

---

## 📦 Memory Configuration

- Total Memory: `64 blocks`
- Page Size: `8 blocks`
- Each block is visualized as a single unit in the terminal.

---

## 🛠️ How It Works

### Memory Block Structure
Each memory block stores:
- `start`: start index
- `size`: block size (default 1)
- `allocated`: whether the block is used
- `process_id`: PID of the process
- `is_page`: true if it's part of a page
- `page_number`: number within process

### Modes

1. **Demo Mode**
   - Demonstrates multiple memory operations step-by-step.

2. **Interactive Mode**
   - Choose from a menu to allocate/free memory, inspect blocks, or reset.

---

## 📸 Visual Output Example

----------------------
=== Memory Map ===
0 1 2 3 4 5
0123456789012345678901234567890123456789012345678901234567890123
+----------------------------------------------------------------+
|..22222.....PPP.......33333333...............PPP.........4444..|
+----------------------------------------------------------------+

-----------------------

Legend:
0-9 - Allocated process blocks
P - Allocated page
. - Free memory
---
---

## 🔍 Fragmentation Analysis

- **Internal Fragmentation**: Wasted space inside allocated pages.
- **External Fragmentation**: Free memory that's not contiguous.

---

## 📥 How to Compile & Run

### 🧾 Requirements
- C compiler (e.g., GCC)
- Terminal (supports ANSI color codes)

### 💻 Build and Run

```bash
gcc -o memory_visualizer memory_visualizer.c
./memory_visualizer
