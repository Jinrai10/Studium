import socket
import sys

from ntp_packet import NTPPacket, NTPTimestamp

HOST, PORT = "127.0.0.1", 123
data = "".join(sys.argv[1:])

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

sock.sendto(bytes(data + "\n", "utf-8"), (HOST, PORT))
received = NTPPacket().from_bytes(sock.recv(1024))

print("Sent:        {}".format(data))
print("Received:    {}".format(received))
