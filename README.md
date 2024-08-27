<h1 align="center">
  📢 minitalk
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/benzThor/minitalk?color=red" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/benzThor/minitalk?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/benzThor/minitalk?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/benzThor/minitalk?color=green" />
</p>

<h3 align="center">
	<a href="#-project-overview">📝 Project Overview</a>
	<span> · </span>
	<a href="#-objectives">🎯 Objectives</a>
  <span> · </span>
	<a href="#️-installation">🛠️ Installation</a>
	<span> · </span>
	<a href="#-usage">🚀 Usage</a>
	<span> · </span>
	<a href="#️-functionality">⚙️ Functionality</a>
	<span> · </span>
	<a href="#-testing">🧪 Testing</a>
</h3>

## 📝 Project Overview

`Minitalk` is a 42 project that involves creating a small data exchange program between a client and a server using UNIX signals. The main goal is to implement a simple messaging system where the client can send strings to the server, which the server then displays.

**Key Concepts:** 

  - **UNIX Signals:** Using SIGUSR1 and SIGUSR2 signals to transmit information.
  - **Signal Handling:** Handling signals effectively to ensure data integrity.
  - **Process Communication:** Establishing communication between two processes (client and server).

## 🎯 Objectives

The Minitalk project focuses on:

  - Learning about UNIX signals and how they can be used for inter-process communication.
  - Understanding the principles of client-server architecture.
  - Implementing robust signal handling to ensure that all messages are accurately transmitted and received.
  - Gaining experience in managing asynchronous events in a C program.

## 🛠️ Installation

To set up the project, follow these steps:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/benzThor/minitalk.git
   cd minitalk
   ```

2. **Compile the project:**

   The project includes a Makefile that handles the compilation process for both the server and client programs. To compile the project, simply run:

   ```bash
   make
   ```

   This command will generate the server and client executables in the project directory.

   - To clean up the compiled files, you can use:
     ```bash
     make clean
     ```
    - To remove all compiled and object files, use:
      ```bash
      make fclean
      ```
    - To recompile the project from scratch, use:
      ```bash
      make re
      ```

## 🚀 Usage

1. **Start the server:**

   First, run the server. The server will display its Process ID (PID), which the client will need to send messages.

   ```bash
   ./server
   ```

   The server will print its PID to the terminal.

2. **Send a Message with the Client:**

   Use the client to send a message to the server. You need to provide the server's PID and the message as arguments:

   ```bash
   ./client [server_pid] "Your message here"
   ```

   Replace [server_pid] with the actual PID of the server, and replace "Your message here" with the message you want to send.

3. **Example:**

   If the server's PID is 12345 and you want to send the message "Hello, Minitalk!", you would run:

   ```bash
   ./client 12345 "Hello, Minitalk!"
   ```

   The server should then display "Hello, Minitalk!" in its terminal.

## ⚙️ Functionality

  - **Signal Transmission**: The client encodes each character of the message into a series of signals (SIGUSR1 and SIGUSR2) and sends them to the server.
  - **Signal Handling**: The server decodes the received signals back into characters and prints the message to the terminal.

## 🧪 Testing

  To test the Minitalk program:

  1. Start the server in one terminal.
  2. Use the client in another terminal to send messages to the server.
  3. Observe the server output to ensure it correctly displays the received messages.





  
