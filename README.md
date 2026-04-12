# tsuPod

A lightweight music library manager written in C++. tsuPod lets you manage a collection of songs with a memory cap — add, remove, sort, shuffle, and browse your library from the command line.

## Features

- Add and remove songs by title, artist, and size
- Enforces a configurable memory limit (in MB)
- Sort your library by title, artist, or size
- Shuffle songs into a random order
- View remaining and total storage at any time

## How it works

Songs are stored in a linked list, making the library dynamic — no fixed song limit, just a memory ceiling you set at startup.

## Usage

Compile with:

```bash
g++ Song.cpp tsuPod.cpp test_tsuPod.cpp
```

Then run:

```bash
./a.out
```

## Tech

- C++
- Linked lists
- Object-oriented design
