# Railway-DeadLock-Stimulation
This project is a Railway Deadlock Simulation System using C, HTML, and Python. It applies the Banker’s Algorithm to model resource allocation in a multi-track railway environment, simulating deadlock scenarios and identifying safe or unsafe states based on available resources.

# Features
Resource Allocation & Deadlock Detection: Utilizes the Banker's Algorithm to allocate resources to trains and determine if a safe state can be maintained.
Interactive Web Interface: An HTML interface (f1.html) enables users to input the number of trains and tracks and visually inspect the results.
Dynamic CGI Script: A CGI-based backend written in C (logic.c) computes resource matrices, performs safety checks, and outputs results in a user-friendly format.
Local Server Setup: A Python script (run_cgi.py) starts a local server, compiles the C code, and handles CGI requests for simulation runs.
Files
logic.c: Core program logic, generates allocation, maximum, and need matrices for trains and tracks and checks for safe states.
f1.html: Frontend form to input simulation parameters and view results.
run_cgi.py: Python script to compile and serve the C CGI program.
tasks.json: Build task configuration for compiling C code using GCC.

# How to Run
Compile the C code and start the local server with run_cgi.py.
Access the simulation interface at http://localhost:8000/static/f1.html.
Input the number of trains and tracks, then submit to see the simulation results.

# Technologies Used
C for core logic and resource handling.
HTML/CSS for the frontend interface.
Python for server and CGI handling.

This project is a valuable learning tool for deadlock detection and avoidance in resource allocation systems.






