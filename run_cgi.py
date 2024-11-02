import http.server
import os
import subprocess

class CGIHTTPRequestHandler(http.server.CGIHTTPRequestHandler):
    cgi_directories = ['/cgi-bin']

if __name__ == '__main__':
    # Compile the C program
    os.system("gcc -o cgi-bin/logic.cgi cgi-bin/logic.c")

    # Start the server on port 8000
    server_address = ('', 8000)
    httpd = http.server.HTTPServer(server_address, CGIHTTPRequestHandler)
    print("Server running on port http://localhost:8000/static/f1.html")
    httpd.serve_forever()
