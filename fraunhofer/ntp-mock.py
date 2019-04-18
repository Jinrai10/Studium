import socketserver
import time

from ntp_packet import NTPPacket, NTPTimestamp

def create_NTPPacket(return_time):


    response = NTPPacket()
    response.version = 3
    response.mode = 4
    response.stratum = 1
    response.reference_identifier = b'XFAK'
    response.origin_timestamp = NTPTimestamp.ZERO
    response.reference_timestamp = NTPTimestamp.from_unix_timestamp(return_time)
    response.receive_timestamp = NTPTimestamp.from_unix_timestamp(return_time)
    response.transmit_timestamp = NTPTimestamp.from_unix_timestamp(return_time)

    return response

class MyUDPHandler(socketserver.BaseRequestHandler):
    drift_start = time.time()
    speed = 0.9996

    def handle(self):
        data = self.request[0].strip()
        socket = self.request[1]
        print("{} wrote:".format(self.client_address[0]))
        print(data)

        time_since_start = time.time() - self.drift_start
        return_time = self.drift_start + time_since_start * self.speed

        socket.sendto(create_NTPPacket(return_time).to_bytes(), self.client_address)

if __name__ == "__main__":
    HOST, PORT = "127.0.0.1", 123
    with socketserver.UDPServer((HOST, PORT), MyUDPHandler) as server:
        server.serve_forever()
