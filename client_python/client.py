import socket
import time

# The server's name is the container name we gave it earlier
SERVER_HOST = 'py-server-container'
SERVER_PORT = 5001

def get_score_from_server():
    try:
        # Create a socket and connect to the server
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((SERVER_HOST, SERVER_PORT))
        
        # Send the required command
        client_socket.send("GET_SCORE".encode())
        
        # Receive and print the response
        response = client_socket.recv(1024).decode()
        print(f"Server Response: {response}")
        
        client_socket.close()
    except Exception as e:
        print(f"Connection failed: {e}")

if __name__ == "__main__":
    print("Client started. Requesting score...")
    get_score_from_server()
