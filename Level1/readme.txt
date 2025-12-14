Level-1 telemetry pipeline implemented using simulated sensor data.

A C program generates accelerometer, gyroscope, altitude, and temperature
data at 20 Hz and transmits it using a UART-style frame format.

Each frame includes an XOR checksum for data integrity.

A Python receiver script reads the telemetry, validates the checksum,
parses the data, and logs verified samples into a CSV file.

No hardware was used; the solution was validated on a Windows PC.



