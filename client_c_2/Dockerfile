# Use a lightweight Debian image
FROM debian:stable-slim

# Install only the GCC compiler
RUN apt-get update && apt-get install -y gcc

# Set the working directory
WORKDIR /app

# Copy the client source code
COPY client.c .

# Compile the C client
RUN gcc client.c -o c_client

# Run the client by default
CMD ["./c_client"]
