𝑮𝒆𝒕_𝒏𝒆𝒙𝒕_𝒍𝒊𝒏𝒆
  
    Reading a line from a file descriptor, one step at a time.

_____________________________________________________________________

Description

The get_next_line project is part of the 42 School curriculum. The goal of this project is to implement a function that reads a line from a file descriptor. It must handle multiple file descriptors simultaneously, manage memory efficiently, and respect strict coding standards.

This project provides a deeper understanding of file descriptors, buffer management, and dynamic memory allocation in C.

Prototype

`char *get_next_line(int fd);`

Features

	•	Reads and returns the next line from a file descriptor.
	•	Handles multiple file descriptors simultaneously.
	•	Manages memory dynamically to accommodate lines of any length.
	•	Supports customizable buffer sizes defined by BUFFER_SIZE.
