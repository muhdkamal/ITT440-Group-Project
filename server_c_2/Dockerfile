# Use a lightweight Debian image
FROM debian:stable-slim

# Install GCC and the updated MariaDB/MySQL dev libraries
RUN apt-get update && apt-get install -y gcc libmariadb-dev libmariadb-dev-compat

# Set the working directory
WORKDIR /app

# Copy the server source code
COPY server.c .

# Compile the C program (the compat library allows -lmysqlclient to work)
RUN gcc server.c -o c_server -lmysqlclient -lpthread

# Run the server
CMD ["./c_server"]
