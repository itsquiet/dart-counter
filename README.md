# Dart Counter System

A modular, offline-first dart scoring system with a reusable C game engine, web-based frontends, and event-driven extensions for hardware integration.

This project is primarily a **learning and reference project** with a strong focus on **clean software architecture**, **API design**, and **professional development practices** across backend, frontend, and system boundaries.

---

## Motivation

Most existing dart scoring applications focus on UI features but lack:

- a cleanly separated and reusable game logic core
- offline-first operation without cloud dependency
- extensibility for custom hardware (LEDs, cameras, etc.)
- a transparent, well-documented architecture

This project intentionally addresses these gaps by building the system **from the ground up**, using a low-level language (C) for the core logic and modern web technologies for presentation.

---

## Project Goals

### Core Goals

- Implement a **reusable and testable dart game engine in C**
- Clean separation between:
  - game logic
  - transport layer (HTTP)
  - persistence
  - frontend
  - hardware integration
- Support classic dart games:
  - X01 (301 / 501)
  - later: Cricket, Shanghai, training modes

### Usage Scenarios

- **Local dart room setup**
  - Raspberry Pi as server
  - iPad for input
  - TV near the dartboard for display
- **Offline operation**
  - Local WiFi only, no internet required
- **Future online mode**
  - Remote players joining games once internet is available

---

## Architecture Overview

The system follows a **layered, event-driven architecture**.

### High-Level Components

- **C Game Engine**
  - Pure game rules and state handling
  - No UI, no hardware dependencies
- **HTTP API Layer**
  - Exposes the engine via REST endpoints
  - JSON-based communication
- **Persistence Layer**
  - SQLite database
  - Player profiles, statistics
  - Crash-recovery for active games
- **Event System**
  - Decouples game logic from side effects
  - Enables LEDs, logging, and future camera modules
- **Web Frontends (Angular)**
  - Input UI (tablet)
  - Display UI (TV, read-only)
- **Optional Hardware Modules**
  - LED effects via Raspberry Pi GPIO
  - Future camera-based dart tracking

All architectural decisions are documented using **UML diagrams** stored in this repository.

---

## Design Principles

- **Single Responsibility**
- **Loose coupling**
- **Explicit APIs**
- **Deterministic game logic**
- **Offline-first**
- **No framework magic in the core**
- **Everything explainable and debuggable**

This project is intentionally designed so that every part can be understood, justified, and reused.

---

## Repository Structure

dart-counter/
├── README.md
├── docs/
│ └── uml/ # PlantUML diagrams (architecture, sequences, states)
├── backend/
│ ├── src/ # C source files
│ ├── include/ # Public C headers (engine API)
│ └── tests/ # Unit and integration tests
├── frontend/
│ └── angular/ # Angular web clients
├── .gitignore


---

## UML Documentation

All design decisions are documented using **PlantUML**.

Current diagram types:

- Component diagram (system architecture)
- Sequence diagrams (request flow)
- State machines (dart game logic)
- Structural models (C structs & APIs)

Rendered images are intentionally **not committed**.  
Only `.puml` source files are versioned.

---

## Technology Stack

### Backend
- C (C17)
- SQLite
- POSIX sockets / HTTP
- Event-driven architecture

### Frontend
- Angular
- HTML / CSS
- REST API consumption

### Tooling
- Git & GitHub
- PlantUML
- Graphviz
- Visual Studio Code

---

## Development Approach

This project is developed incrementally:

1. Architecture & UML
2. Game engine API design
3. Core game logic implementation
4. Persistence integration
5. HTTP API
6. Frontend clients
7. Hardware extensions
8. Optional containerization (Docker)

Each step is designed to be **understandable and reviewable in isolation**.

---

## Educational Purpose

This project is explicitly designed as:

- a learning project for professional software engineering
- a reference for clean C architecture
- a demonstration of backend/frontend separation
- a portfolio-ready system

Code clarity and structure are prioritized over shortcuts.

---

## Status

🚧 **Work in progress**

The project is currently in the **architecture and setup phase**.  
Implementation starts after the UML design is finalized.

---

## License

License information will be added once the project reaches a stable core.

---

## Author

Developed as a personal learning and reference project.
