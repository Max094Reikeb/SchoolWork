from http.server import BaseHTTPRequestHandler, HTTPServer
import os


class LPDWHTTPRequestHandler(BaseHTTPRequestHandler):
    # handle GET command
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(bytes("<html><head><title>Title goes here.</title></head>", "utf-8"))
        self.wfile.write(bytes("<body><p>This is a test.</p>", "utf-8"))
        self.wfile.write(bytes("<p>You accessed path: %s</p>" % self.path, "utf-8"))
        self.wfile.write(bytes("</body></html>", "utf-8"))


def run():
    print('http server is starting...')

    # ip and port of server
    # by default http server port is 80
    server_address = ('10.40.78.160', 5001)
    httpd = HTTPServer(server_address, LPDWHTTPRequestHandler)
    print('http server is running...')
    httpd.serve_forever()


if __name__ == '__main__':
    run()
