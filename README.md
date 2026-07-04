**Inventory System**

`This is my first completed C++ project.`

`Console-based inventory system written in modern C++20.`

This project I created as a learning project to practice object-oriented programming and modern C++ concepts. The main goal was to understand how inheritance and polymorphism work together, while also gaining experience with smart pointers and dynamic memory management.

## Learning Goals

* Practice inheritance and polymorphism.
* Practice manipulating objects and class data.
* Learn how `std::unique_ptr` manages dynamically allocated memory without requiring manual memory deallocation.
* Explore how a base class and derived classes interact through polymorphism.

## Features

* Add items to the inventory.
* Display all inventory items.
* Equip weapons.
* Drink potions.
* Drop items.
* Automatic memory management using `std::unique_ptr`.
* Object-oriented item hierarchy (`Item`, `Weapon`, `Armor`, `Potion`).

## Technologies

* C++20
* Object-Oriented Programming
* Polymorphism
* Inheritance
* Smart Pointers (`std::unique_ptr`)
* STL (`std::vector`)

## Build

```bash
clang++ -std=c++20 Armor.cpp Item.cpp Player.cpp Potion.cpp Weapon.cpp main.cpp -o main
```

Run:

```bash
./main
```

## Future Improvements

* Save and load inventory from files.
* Improve the console interface.
* Add new item types.
* Add an enemy and combat system.
* Improve the overall project architecture as I continue learning modern C++.