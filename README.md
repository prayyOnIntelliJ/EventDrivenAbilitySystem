#⚙️ EventAbilitySystem

Status: Work in Progress

This is an active portfolio project and still in development.

🧭 Overview


EventAbilitySystem is a small portfolio project that shows how an event-driven ability system can be structured in a clean and modular way.

The goal is not to create a full game, but to demonstrate good system design, clear responsibilities, and readable C++ code, mainly using Unreal Engine 5.


---

🧩 Core Ideas

- Event-driven ability system

- Clear separation of responsibilities
	- Character → executes actions

	- AbilityComponent → manages and routes abilities

	- AbilityBase → rules and lifecycle


- Single entry point to activate abilities

- Abilities do not handle input directly

- UI reacts to events only (planned)


---

🚧 Current State

- Core ability architecture implemented

- Dash ability as an example

- Enhanced Input set up via PlayerController

- Central place for ability names

Still in progress:


- UI feedback (cooldowns, states)

- More abilities (e.g. Shield, Heal)

- Diagrams and documentation

- General cleanup and polish


---

📝 Notes

- The project currently uses the Unreal Engine Third Person Template.

- Visuals, animations, and art are not the focus of this project.

- Networking and advanced features are intentionally not included.


---

🎯 Purpose


This project is meant to show:


- How gameplay systems can be structured

- Understanding of Unreal Engine architecture

- Clean and maintainable code

- Engine-agnostic thinking


---

🛠 Tech

- Unreal Engine 5

- C++

- Enhanced Input

- Event-driven gameplay systems


---
This project is built as a learning and portfolio piece.

Feedback is welcome.