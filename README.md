# ECA1418 – Embedded Systems Lab

Lab experiments for the ECA1418 Embedded Systems course: code, simulation projects, and output screenshots, grouped by platform.

## Repository layout

| Folder | Platform / tools | What's inside |
|---|---|---|
| [`8051-assembly/`](8051-assembly) | 8051 assembly (Proteus) | Port I/O experiments: LED blink, stepper motor, 7-segment counter |
| [`arduino-proteus/`](arduino-proteus) | Arduino UNO + Proteus | Multi-sensor alert, traffic-light FSM, LM75 temperature + pulse monitor |
| [`lpc2148-arm7/`](lpc2148-arm7) | LPC2148 (ARM7) + Keil µVision | Switch input, 7-segment display, UART serial |
| [`rtos-esp32/`](rtos-esp32) | ESP32 + FreeRTOS (Arduino framework) | Tasks, semaphores, queues, timers, ISRs, priority inheritance, memory |
| [`python-esp32-serial/`](python-esp32-serial) | Python (pyserial) + ESP32 | Host-side script that validates a test signal sent over serial |
| [`eda-systemc/`](eda-systemc) | SystemC on EDA Playground | Experiment reports (PDF) |

## Experiment index

### 8051 assembly
| Folder | Experiment |
|---|---|
| `exp-1`, `exp-2` | LED blink on P2.0 using a software delay loop |
| `exp-3` | Stepper motor drive sequence on P2 |
| `exp-4` | 7-segment digit counter 0–9 on P2 (`code-alt.asm` is a second version) |

### Arduino + Proteus
| Folder | Experiment |
|---|---|
| `multi-sensor-alert` | Gas sensor, PIR motion and ultrasonic distance driving a buzzer and LED |
| `traffic-light-fsm` | Four-state traffic light controller designed as a finite state machine |
| `lm75-pulse-monitor` | LM75 temperature over I²C plus pulse/BPM counting |

Each folder has the sketch (`.ino`), a `screenshot.png`, the Proteus project in `proteus/`, and compiled output (`.hex`, `.elf`, …) in `build/`.

### LPC2148 (ARM7)
| Folder | Experiment |
|---|---|
| `switch` | Reading a switch input |
| `seven-seg` | Driving a 7-segment display |
| `serial` | UART communication with terminal output |

These folders hold the Keil project files (`.uvproj`) and generated `.hex`; the C source files are not in the repository yet.

### FreeRTOS on ESP32
| Folder | Experiment |
|---|---|
| `exp-13-task-priorities` | High / medium / low priority tasks running at different rates |
| `exp-14-semaphores-mutex` | Binary semaphore, counting semaphore, mutex-protected counter |
| `exp-15-queue-mailbox-stream` | Queue, mailbox, and stream buffer producer/consumer |
| `exp-16-timers-event-groups` | Software timers setting event-group bits |
| `exp-17-isr-task-notification` | Button interrupt waking a task through task notification |
| `exp-19-priority-inheritance` | Mutex priority inheritance with low / medium / high tasks |
| `exp-20-memory-management` | Heap usage, stack high-water mark, fixed-size memory pool |

Experiment 18 is not in the repository yet.

### Python + ESP32 serial
`esp32_test_signal.ino` sends `TEST_SIGNAL` every second at 115200 baud; `serial_test.py` reads it from `COM3` and counts passes. Change the port in the script to match your machine.

### EDA / SystemC
- Experiment 10: clock generation simulation
- Experiment 11: TLM initiator–target transaction

## How to run

- **8051 / Arduino + Proteus:** open the `.pdsprj` in Proteus, load the matching `.hex` into the microcontroller, and run the simulation.
- **LPC2148:** open the `.uvproj` in Keil µVision.
- **ESP32 FreeRTOS:** create a PlatformIO or Arduino IDE project for your ESP32 board, drop in the `.cpp` file as `main.cpp` (or the sketch), and open the serial monitor at 115200 baud.
- **Python script:** `pip install pyserial`, then `python serial_test.py`.

## Credits

Several experiments were merged in from [Deepak192511008/ECA1418](https://github.com/Deepak192511008/ECA1418).
