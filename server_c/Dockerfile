FROM debian:stable-slim

# Install GCC and the updated MariaDB/MySQL dev libraries
RUN apt-get update && apt-get install -y gcc libmariadb-dev libmariadb-dev-compat

WORKDIR /app

COPY server.c .

# Keep the -lmysqlclient flag; the 'compat' package makes it work
RUN gcc server.c -o c_server -lmysqlclient -lpthread

CMD ["./c_server"]
