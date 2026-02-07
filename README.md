# 🐧 Mini Linux Scheduler Simulator

A CPU scheduling simulator inspired by **Linux OS scheduling concepts**, implemented using **time-based simulation** rather than formula-based calculations.

This project demonstrates how CPU schedulers behave **at runtime**, including preemption, fairness, and real execution order.

---

## 📌 Project Overview

Traditional OS scheduling problems are often solved using static formulas.  
This project instead **simulates CPU execution unit-by-unit**, closely mimicking how an actual operating system scheduler works internally.

The simulator:
- Advances CPU time dynamically
- Makes scheduling decisions at runtime
- Generates a real **Gantt Chart**
- Computes accurate scheduling metrics
- Allows fair comparison between algorithms

---

## 🎯 Features

- Time-driven CPU simulation  
- Preemptive and non-preemptive scheduling  
- Accurate Gantt chart generation  
- Per-process metrics:
  - Completion Time (CT)
  - Turnaround Time (TAT)
  - Waiting Time (WT)
- Average metrics:
  - Average Turnaround Time (ATAT)
  - Average Waiting Time (AWT)
- Command-line user input
- Modular and well-structured C code

---

## 🧠 Scheduling Algorithms Implemented

### 1️⃣ First Come First Serve (FCFS)
- Non-preemptive
- Processes execute in order of arrival
- Simple but suffers from convoy effect

### 2️⃣ Shortest Job First (SJF)
- Non-preemptive
- Chooses the process with the smallest burst time
- Minimizes average waiting time (theoretical)

### 3️⃣ Shortest Remaining Time First (SRTF)
- Preemptive version of SJF
- Scheduler re-evaluates every time unit
- Demonstrates true preemption and context switching

### 4️⃣ Round Robin (RR)
- Preemptive, time-sliced scheduling
- Uses a fixed time quantum
- Ensures fairness and responsiveness
- Priority is intentionally excluded to preserve fairness

---

## ⏱️ Simulation Model

- CPU time progresses **one unit at a time**
- At each time unit:
  - New processes may arrive
  - Scheduler may preempt the running process
  - Remaining burst time is updated
  - Gantt chart is recorded
- Metrics are calculated **after actual execution**, not by formulas

This mirrors real operating system scheduler behavior.

---


