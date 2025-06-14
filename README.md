# 🧠 Memory Allocation Visualizer (C Project)

This C program simulates operating system memory allocation strategies including **Contiguous Allocation**, **Paging**, and shows **Fragmentation Analysis** through a colorful and interactive terminal interface.

---

## 🎯 Features

- ✅ Contiguous memory allocation using **First Fit**
- ✅ **Paged memory allocation** using fixed-size pages
- ✅ Interactive and **color-coded memory visualization**
- ✅ Detailed block-wise memory information
- ✅ Calculation of **fragmentation**
- ✅ **Demo mode** and **Interactive mode**
- ✅ Terminal-compatible across Linux, macOS, Windows

---

## 📦 Memory Configuration

- Total Memory: `1024 blocks`
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

```
=== Memory ===
|_ |_ |_ |1 |1 |1 |1 |1 |1 |1 |1 |1 |2 |2 |2 |2 |2 |2 |2 |2 |_
...
```

Legend:  
- Numbers: Allocated process blocks  
- `_`: Free memory

---

## 🔍 Fragmentation Analysis

- **Fragmentation**: Shows total free blocks and largest contiguous free block.

---

## 📥 How to Compile & Run

### 🧾 Requirements
- C compiler (e.g., GCC)
- Terminal (supports ANSI color codes)

### 💻 Build and Run

Open a terminal in the `src` directory and run:

```sh
gcc *.c -o memory_visualizer
./memory_visualizer
```
On Windows, run:
```sh
memory_visualizer.exe
```

---

## 📁 File Structure

```
memory_allocator_project/
│
├── include/
│   ├── allocator.h
│   ├── common.h
│   ├── fragmentation.h
│   └── visualizer.h
│
├── src/
│   ├── allocator.c
│   ├── fragmentation.c
│   ├── main.c
│   └── visualizer.c
│
└── README.md
```

---

## 🙌 Credits

Developed for educational purposes to demonstrate memory allocation strategies